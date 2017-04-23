# TUINO HARDWARE
Here are a collection of libraries for the on-board Tuino Hardware features<br/>
## NFC
Check here [tuino_nfc](tuino_nfc)
<br>
## M41T62 RTC
To use the M41T62 on board RTC use this library from mozzwald [https://github.com/mozzwald/RTC_M41T62](https://github.com/mozzwald/RTC_M41T62).</br>
It works out of the box, on the Tuino 1 only the /IRQ pin is connected to the additional INT2 pin of the AtMega1284P, so you can test the Alarm examples of the library, but not the SQW Pin ones.<br>
Remember that the Tuino 1 board extension for the Arduino IDE you have the TUINO_INTERRUPT declared so to setup the interupt example modify it like this:<br/>

```c
 
 // Setup rtc interrupt input pin
  pinMode(TUINO_INTERRUPT, INPUT);
  attachInterrupt(digitalPinToInterrupt(TUINO_INTERRUPT), alarmIrq, FALLING);

```

## Battery Gauge - MAX17048
The chip that is used as battery gauge on the Tuino 1 is the [MAX17048](https://www.maximintegrated.com/en/datasheet/index.mvp/id/7636).<br/>
You can use this excellent library to read you battery level and state of charghe (SOC) from alikian [https://github.com/alikian/ArduinoLib_MAX17048](https://github.com/alikian/ArduinoLib_MAX17048). Remember that if the battery is not connected the gauge chip will always read 100% since it will read directly chargning voltage.

