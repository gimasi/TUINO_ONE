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


