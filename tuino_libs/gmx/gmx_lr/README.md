# GMX LR 
These are the interface libraries to the GMX LoRa module. The **tuino_lora** folder contains the basic example with the best practice to implement a LoRa based project.<br/>
Our library is using the Regexp.cpp library from [Nick Gammon](https://github.com/nickgammon/Regexp) which we find really excellent!<br/>
The GMX LR module is a completely independent STM32L0/SX1276 based module where all the LoRa stack is running and it is interfaced to the Tuino via UART. <br/>There is a complete series of commands that give you access to the low level params of the LoRaWAN stack enabling you to control things like RX1 & RX2 window delays, Join window delays, datarate on the RX2 window and enabling/disabling ADR .<br/>
Another important feature that we have implemented is that RX is interrupt based, you simply register the callback function with the module initilazation function and you are set. 

```c
/*
 * Callback function that sets a flag to signal main loop a RX Event
 */
void loraRx(){
  data_received = true;
}

..
..

void setup() {
  // put your setup code here, to run once:
  
  // GMX-LR init pass RX callback function
  gmxLR_init(&loraRx);


```


# MODULE INIT AND LORAWAN JOIN PARAMETERS

The board init function will reset and reboot the module and you will see all the leds flashing in sequence at boot.<br/> 
As described above you need to specify the RX callback function when calling this function. 

```c
byte gmxLR_init(void (*function)());
```

for the current version

```c
byte gmxLR_getVersion(String& version);
```


Setting up the LoRaWAN parameters for OTAA/ABP and CLASS.
All keys and EUI ( DevEui, AppEui, AppKey, DevAddr, etc. ) must be specified in hex byte sequence separated by a colon ':', like this: **00:00:11:99:22:11:22:99**<br/>
The Class currently implemented are 'A' and 'C'.

<b>*** IMPORTANT ***</b><br/>
All production GMX-LR modules come with their unique DevEUI that cannot be changed (ie. the gmxLR_setDevEui() function won't work, we can provide a custom firmware if you need to change the DevEUI).<br/> 
AppEUI and AppKey, for OTA provisioning, come preprogrammed, but can be changed with the respective gmxLR_ function calls. The preprogrammed values follow this pattern:<br/>
* AppEUI = DevEUI
* AppKey = two times the DevEUI
so for example:<br/>
DevEUI = 78AF580301020304<br/>
AppEUI = 78AF580301020304<br/>
AppKEY = 78AF58030102030478AF580301020304
<br/>
When you change the AppKey and AppEUI they will stored in the EEPROM of the GMX-LR module and will remain set also after power cycle.<br/>


```c

byte gmxLR_getDevEui(String& devEui);

// only available with special firmware
byte gmxLR_setDevEui(String devEui);

byte gmxLR_getAppEui(String& appEui);
byte gmxLR_setAppEui(String appEui);

byte gmxLR_getAppKey(String& appKey);
byte gmxLR_setAppKey(String appKey);

byte gmxLR_getDevAddr(String& devAddr);
byte gmxLR_setDevAddr(String devAddr);

byte gmxLR_getNetworkID(String& netId);
byte gmxLR_setNetworkID(String netId);

byte gmxLR_getNetworkSessionKey(String& nwsk);
byte gmxLR_setNetworkSessionKey(String nwsk);

byte gmxLR_setApplicationSessionKey(String appsk);
byte gmxLR_getApplicationSessionKey(String& appsk);

byte gmxLR_getClass(String& lrclass);
byte gmxLR_setClass(String lrclass);


```



# NETWORK JOIN
The **gmxLR_Join()** call is non blocking, it will start the join process and return immediately. Your code has to poll the module with the **gmxLR_isNetworkJoined()** to verify if it has actually joined the network. The join procedure will go on forever until a join is achieved.

```c
byte gmxLR_Join(void);
byte gmxLR_isNetworkJoined(void);

byte gmxLR_setJoinMode(byte mode);
byte gmxLR_getJoinMode(String& mode);
```

It's up to your application what to do if if can't join the network for a long time, here is our join code in the example project you find in this repo. It resets the module after n tries, but it's up you what you want to do....

```c
  
  Serial.println("Joining...");
  join_wait = 0; 
  while((join_status = gmxLR_isNetworkJoined()) != LORA_NETWORK_JOINED) {

  Serial.print("Join:");
  Serial.println(join_wait);
  
    if ( join_wait == 0 ) {

      // we set again parameters 
      gmxLR_setAppEui("00:00:00:00:00:00:00:00");
      gmxLR_setAppKey("01:02:03:04:05:06:07:08:01:02:03:04:05:06:07:08");

      gmxLR_Join();
    }
    
    join_wait++;

    if (!( join_wait % 100 )) {
      gmxLR_Reset();
      join_wait = 0;
    }

    delay(5000);

  };

```


# LOWER LEVEL LORAWAN FUNCTIONS
Here is the list of functions with which you can tune the LoRaWAN stack, actually you shouldn't because it is already on the standard values, but if you really want...<br/>


```c
byte gmxLR_getADR();
byte gmxLR_setADR(String on_off);

byte gmxLR_getDutyCycle();
byte gmxLR_setDutyCycle(String dutycyle);

byte gmxLR_getRSSI(String& rssi);
byte gmxLR_getSNR(String& snr);

byte gmxLR_getTXPower(String& power);
byte gmxLR_setTXPower(String power);

byte gmxLR_getJoinRX1Delay(String& joinrx1);
byte gmxLR_setJoinRX1Delay(String joinrx1);

byte gmxLR_getJoinRX2Delay(String& joinrx2);
byte gmxLR_setJoinRX1Delay(String joinrx2);

byte gmxLR_getRX1Delay(String& rx1);
byte gmxLR_setRX1Delay(String rx1);

byte gmxLR_getRX2Delay(String& rx2);
byte gmxLR_setRX2Delay(String rx2);

byte gmxLR_getRX2DataRate(String& rx2dr);
byte gmxLR_setRX2DataRate(String rx2dr);

byte gmxLR_getDataRate(String& dr);
byte gmxLR_setDataRate(String dr);

```


# SENDING AND RECEIVING DATA

You have two functions to transmit data, the first without the port number, which defaults to port 1, and the second if you want to specify the port.<br/>The payload **data** must be an hexadecimal string, in the form **00a133b577**. If the format is incorrect the function will return an error.<br/> The **gmxLR_TXData()** is non blocking and will return immediately, the packet might or might not be sent immediately depending on the available duty cycle slots.<br/>
While the module will generate an interrupt on every RX packet, you need to call the **gmxLR_RXData()** function to retrieve the actual payload and the port on which it has been received.

```c
byte gmxLR_TXData(String data);
byte gmxLR_TXData(String data, int port);
byte gmxLR_RXData(String& data, int *port);
```

By default confirmation (acknowledge) is disabled on all transmissions, but you can enable it with the specific function. If the confirmation is enabled you need to call the **gmxLR_getMessageConfirmation()** after a TX to verify if the message has been confirmed.


```c
byte gmxLR_getConfirmationMode(void);
byte gmxLR_setConfirmationMode(String cfm);

byte gmxLR_getMessageConfirmation(void);
```


# UTILITIES
There is the possibility of driving the fourth LED on the GMX-LR1 board. 1 turns if on, 0 turns it off.<br/>
And as always there is reset function that reboots the module, remember after a reboot you need to rejoin the network.<br/>
The gmxLR_StringToHex() function is useful in converting a RX HEX string to a byte array that is more easy to handle for packet decoding.


```c
byte gmxLR_Led(byte led_state);

void gmxLR_Reset(void);

void gmxLR_StringToHex(String string, char *data, int *len );

```

# LED FEEDBACK
On the GMX-LR1 module 4 leds are present, 3 are used by the LoRaWAN stack to comunicate to the user it's actual state.<br/>
Here is a close up of the LEDs<br/>
<br/>
<img src="/docs/gmx_lr1_detail_small.png"/>
<br/>
* D4 **Blue** Led<br/>
This led signals a TX event, its connected to the low level LoRa stack, so just before there is a RadioTX this Led flashes.
* D3 **Green** Led<br/>
This led signals a RX event.
* D2 **Yellow** Led<br/>
Join status Led.<br/>
Slow flash interval the GMX_LR1 is Joining.<br/>
Fast flash interval the GMX_LR1 has Joined.<br/>
* D1 **Orange** Led<br/>
User controlled Led with the **gmxLR_Led()** function<br/>

# UPDATING FIRMWARE 
It is possible to update the firmware of the GMX-LR1 module via the Tuino 1 board and USB cable.<br/>
You will need the excellent STM32 Bootloader utility from Tomasz Watorowski, since the [ST](http://www.st.com/en/development-tools/flasher-stm32.html) original one dosen't really work well.<br/> 
You can find it here [STBootLib](https://github.com/MightyDevices/STBootLib) and the binary is available here [STBootLib windows binary](https://github.com/MightyDevices/STBootLib/releases) - download both the .exe and the .dll. It's only available  for windows....<br/>
<br/>
You will also need a tiny .ino script that has to be run on the Tuino 1. It simply sets the STM32L0 of the GMX-LR1 module in bootloader mode and redirects the USB serial to the GMX-LR1 serial for the external utility to work.<br/>
Here is the code - just copy paste it into a new script in the Arduino IDE:
```c

void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(115200,SERIAL_8E1);

  if(Serial1) {
    Serial1.begin(115200,SERIAL_8E1);
  } 
        
 
  // Boot in Bootloader Mode
  // Preproduction Tuino's used GPIO5 for BOOT0 pin of STM32 Micro
  // Production version ( rev. E and up ) use instead GPIO6
  pinMode(GMX_GPIO5,OUTPUT);
  digitalWrite(GMX_GPIO5,1);
  pinMode(GMX_GPIO6,OUTPUT);
  digitalWrite(GMX_GPIO6,1);


  // Reset 
  pinMode(GMX_RESET,OUTPUT);
  digitalWrite(GMX_RESET,HIGH);
  delay(100);
  digitalWrite(GMX_RESET,LOW);
  delay(100);
  digitalWrite(GMX_RESET,HIGH);
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  byte ch;

  if (Serial1.available()>0) 
  {
    Serial.write(Serial1.read());
  }

  if (Serial.available()>0) 
  {
    ch = Serial.read();
    Serial1.write(ch);
  }
  
}

```

We will post regular updates of the GMX-LR1 firmware as new features and/or bugs are added/resolved.
