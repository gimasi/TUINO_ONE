# TUINO 1
TUINO 1 is an Arduino Uno compatible board which has been developed for IoT applications, it has the form factor of the Arduino/Genuino Uno but with a series of additional features:<br/>
![TUINO](/docs/tuino-small.jpg?raw=true)

* ATMega1284P processor - which has 192K of FLASH and 16Kb of RAM. You can now build much more complex sketches.
* 5/3.3V switch - use 3.3V sensors without any problems.
* 4 [GROVE](http://wiki.seeed.cc/Grove_System/) connectors - no need for external shields to add sensors.
* [RTC](http://www.st.com/en/clocks-and-timers/m41t62.html) with battery back up - always useful in an IoT application.
* [NFC](http://www.st.com/en/nfc/m24sr04-y.html) chip - leverage NFC connectivity for exchaning information with smart phones.
* LiPO charging section with [power gauge](https://www.maximintegrated.com/en/products/power/battery-management/MAX17048.html) - you can check the battery level from your sketch.<br/>

##GMX MODULES
The most important feature we have added is the GMX bus - this is an additional bus that exploits the additional I/O pins of the 1284P and with which you can add different RF modules. - leveraging different technologies for your IoT projects.<br/>
Here's the pinout<br/>
![GMX_PINOUT](/docs/gmx_pinout.png?raw=true)

The available RF GMX boards are:

* GMX-LR1 : LoRaWAN board, based on the [Murata](http://wireless.murata.com/eng/products/rf-modules-1/lpwa/type-abz.html) module
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

##ADDING TUINO 1 SUPPORT IN THE ARDUINO IDE
Update your Arduino IDE to the latest [version](https://www.arduino.cc/en/Main/Software) ( >= 1.6.4 ), go to preferences and add the Tuino Board Manager URL: <br/>
https://raw.githubusercontent.com/gimasi/TUINO_ONE/master/arduino_ide/package_tuino_index.json<br/>
<br/>
![ARDUINO-IDE](/docs/arduino_ide.png?raw=true)
<br>
You are now ready to add the Tuino 1 to your IDE. Go to Tools->Board->Board Manager and look for the Tuino board, and finally click on install...
<br>

More info coming up very soon... Stay tuned!
