<hr>
**<b>If you are Looking for the onboard HW or GMX Modules libraries for the Tuino 1 navigate into the tuino_libs directory and find them there. Have Fun!</b>**
<hr/>

# QUICK SETUP

To start using the Tuino 1 you need to install the Arduino IDE ( >= 1.6.4 ).<br/> 
Find the latest version on the official Arduino website [www.arduino.cc](https://www.arduino.cc/).<br/>
Once you have installed the IDE you need to load the board manager file for the Tuino 1. Here the steps:<br/>
1) Launch the Arduino IDE<br/>
2) Open the Menu File, and go to Preferences<br/> 
<br/>
`https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`
<img src="/docs/arduino_ide_1.png">
`https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`
<br/>
3) Inside the dialog that appears, go to the 'Additional Boards Manager URLs' text box and copy the following URL inside the text box: `https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`<br/>

<br/>
`https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`
<img src="/docs/arduino_ide_2.png">
`https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`
<br/>
`https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`
4) Click Ok.<br/>
`https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json`
5) Now to go to the '<b>Tools</b>' menu, select the '<b>Board…</b>'' menu item, another menu will open on the right, select '<b>Boards Manager</b>'<br/>
<br/>
<img src="/docs/arduino_ide_3.png">
<br/>
The Board Manager dialog box will appear, type in the search text box the word Tuino. The Tuino board files will appear, click on the text to select it and the '<b>Install</b>' button will appear.<br/>
<br/>
<img src="/docs/arduino_ide_4.png">
<br/>
6) Click Install... Once the installation has finished you can close the dialog.<br/>
7) Reopen the '<b>Tool</b>' menu, select the '<b>Board...</b>' menu item, on the menu that opens on the right you should see at the bottom the '<b>Tuino 1</b>'... Select it<br/>
<br/>
<img src="/docs/arduino_ide_5.png">
<br/>
8) You are now ready to start working with your first examples<br/>
9) Here some initial sketches you can start playing with:<br/>
For the LoRaWAN GMX-LR1<br/>
For the GMX-NBIoT module<br/>
<br/>
<br/>
[pollo](https://github.com/gimasi/GMX-NBIOT/tree/master/tuino_nbiot/)

# TUINO 1


TUINO 1 is an Arduino Uno compatible board which has been developed for IoT applications, it has the form factor of the Arduino/Genuino Uno but with a series of additional features:<br/>
<br/>
<img src="/docs/tuino_revE.jpg"/>

* ATMega1284P processor - which has **128K** of FLASH and **16Kb** of RAM. You can now build much more complex sketches.
* 5/3.3V switch - use 3.3V sensors without any problem.
* 4 [GROVE](http://wiki.seeed.cc/Grove_System/) connectors - no need for external shields to add sensors.
* [RTC](http://www.st.com/en/clocks-and-timers/m41t62.html) with battery back up - always useful in an IoT application.
* [NFC](http://www.st.com/en/nfc/m24sr04-y.html) chip - leverage NFC for enhanced connectivity with smart phones.
* LiPO charging section with [power gauge](https://www.maximintegrated.com/en/products/power/battery-management/MAX17048.html) - you can check the battery level from your sketches.<br/>
* ON/OFF/RESET [Power Control](http://www.linear.com/product/LTC2955). You can switch on, switch off and reset the Tuino 1 all from 1 single button.
* SD Card slot - fully compatinle with the [Arduino SD](https://www.arduino.cc/en/reference/SD) library. Store your sensor data on SD card 

## TUINO 1 PINOUT
Here is the pinout of the Tuino 1<br/>

### TOP 
<img src="/docs/top_layer.png"/>

### HEADERS
* J4 - connection for external on/off/reset pushbutton
* J12 - fitted with header - NFC antenna connection 
* J13 - connection for external +5V power supply
* J14 - fitted with header - automatic power on. If jumper is fitted the board turns on automatically as soon as power is supplied.
* J15 - connection for external LiPO battery

### BOTTOM 
<img src="/docs/bottom_layer.png"/>


## DIFFERENCES WITH ARDUINO UNO
While the Tuino 1 is 100% software compatible with the Arduino Uno, there are two differences in the hardware pinout on the expansion shield connectors, and this could lead with some compatibility problems with some existing shields.<br/>

1. We only have 4 Analog Lines
  * A0
  * A1
  * A2
  * A3
  
  To maintain compatibility with the Arduino Uno shield pinout we added the I2C **SDA** and **SCL** on the **A4** and **A5** pins, but on the ATMega1284P these pins are not analog but only digital, thus we loose two analog inputs and gain two additional digital ones, **D14** and **D15**.<br/>
<br/>
2. Pins **D2/INT0** and **D3/INT1**, again due to the pinout of the AtMega1284P, are shared with the second serial. 
   The second serial is used for the **GMX** bus, and in case you are using a **GMX** module that is interfaced via UART, you cannot use these two pins.

   But if you aren't using the **GMX** bus you have a second serial on the expansion shield pinout and this could be convenient for many project!

## ATMega1284P Schematic
Here is the ATMega1284P connection on the Tuino 1 board. For reference and for better understanding of its functionalities.

<img src="/docs/schematic_cpu_tuino.png"/>


## RTC
The RTC clock is based on the M41T62 chip.<br/>
Check the [Tuino HW](https://github.com/gimasi/TUINO_ONE/tree/master/tuino_libs/tuino_hw) section for software drivers.
<br/>

## NFC
The Tunio 1 one has an onboard NFC chip and a header to install an NFC antenna. The NFC chip is the M24SR04.<br/>
Check the [Tuino HW](https://github.com/gimasi/TUINO_ONE/tree/master/tuino_libs/tuino_hw) section for software drivers.
<br/>

## LiPO AND POWER GAUGE
The LiPO charging is driven by the MCP73831. A power gauge chip MAX17048 is present on the I2C bus so that you can always keep under control the charge level of the battery.<br/>
Check the [Tuino HW](https://github.com/gimasi/TUINO_ONE/tree/master/tuino_libs/tuino_hw) section for software drivers.
<br/> 

## microSD Card Slot
The Tuino 1 is compatible with the [Arduino SD](https://www.arduino.cc/en/reference/SD) library.

## GMX MODULES
The most important feature we have added is the GMX bus - this is an additional bus that exploits the additional I/O pins of the 1284P and with which you can add different RF modules. - leveraging different technologies for your IoT projects.<br/>
Here's the pinout<br/>
<br/>
<img src="/docs/gmx_pinout2.png"/>

The available RF GMX boards are:

* GMX-LR1 : LoRaWAN board, based on the [Murata](http://wireless.murata.com/eng/products/rf-modules-1/lpwa/type-abz.html) module
   The Tuino 1 libraries for the GMX-LR1 are [here](https://github.com/gimasi/TUINO_ONE/tree/master/tuino_libs/gmx/gmx_lr)
* GMX-LR1-GPS : LoRaWAN and GPS on same module
* GMX-BLUE : BLE 4.2 board  
* GMX-WIFI : WINC1500 based board 
* GMX-ZIGBEE: ETRX357 based board
* GMX-WMBUS: 868Mhz and 169Mhz Wireless MBUS board (coming soon)
* ...and more will come ( NBIoT is the next one...)

The GMX modules - especially the GMX-LR1 or GMX-LR1-GPS can be used standalone, check the [GMX-LR1](https://github.com/gimasi/GMX-LR1) project  more information.<br/>
Here is a picture:<br/>
![GMX-LR1](/docs/gmx-lr1-small.jpg?raw=true)

And here the TUINO ONE with the GMX-LR1 board<br/>
![TUINO-GMX-LR1](/docs/tuino_with_gmx-small.jpg?raw=true)
 <br/>

## ADDING TUINO 1 SUPPORT IN THE ARDUINO IDE
Update your Arduino IDE to the latest [version](https://www.arduino.cc/en/Main/Software) ( >= 1.6.4 ), go to preferences and add the Tuino Board Manager URL: <br/>
https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json<br/>
<br/>
![ARDUINO-IDE](/docs/arduino_ide.png?raw=true)
<br>
You are now ready to add the Tuino 1 to your IDE.<br/> 
Go to Tools->Board->Board Manager and look for the Tuino board, and finally click on install...
<br>

## PINS_ARDUINO.H
Here the pin definitions in the Tuino 1 board file.

```c

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SCL= 28;
static const uint8_t SDA= 29;

static const uint8_t LED_BUILTIN = 13;

static const uint8_t D0 = 0;
static const uint8_t D1 = 1;
static const uint8_t D2 = 2;
static const uint8_t D3 = 3;
static const uint8_t D4 = 4;
static const uint8_t D5 = 5;
static const uint8_t D6 = 6;
static const uint8_t D7 = 7;
static const uint8_t D8 = 8;
static const uint8_t D9 = 9;
static const uint8_t D10 = 10;
static const uint8_t D11 = 11;
static const uint8_t D12 = 12;
static const uint8_t D13 = 13;

static const uint8_t D14 = 28;
static const uint8_t D15 = 29;

static const uint8_t GMX_GPIO1 = 14;
static const uint8_t GMX_GPIO2 = 15;
static const uint8_t GMX_GPIO3 = 16;
static const uint8_t GMX_GPIO4 = 17;
static const uint8_t GMX_GPIO5 = 18;
static const uint8_t GMX_GPIO6 = 19;
static const uint8_t GMX_GPIO7 = 20;
static const uint8_t GMX_RESET = 21;
static const uint8_t GMX_INT   = 31;

static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;

static const uint8_t TUINO_INTERRUPT = 30;
static const uint8_t TUINO_RTC_INTERRUPT = 30;
static const uint8_t TUINO_NFC_INTERRUPT = 22;

```

If you want to order a Tuino 1 board visit our website [http://www.tuino.io](http://www.tuino.io])
