# TUINO 1
TUINO 1 is an Arduino Uno compatible board which has been developed for IoT applications, it has the form factor of the Arduino/Genuino Uno but with a series of additional features:<br/>
![TUINO](/docs/tuino-small.jpg?raw=true)

* ATMega1284P processor - which has **128K** of FLASH and **16Kb** of RAM. You can now build much more complex sketches.
* 5/3.3V switch - use 3.3V sensors without any problem.
* 4 [GROVE](http://wiki.seeed.cc/Grove_System/) connectors - no need for external shields to add sensors.
* [RTC](http://www.st.com/en/clocks-and-timers/m41t62.html) with battery back up - always useful in an IoT application.
* [NFC](http://www.st.com/en/nfc/m24sr04-y.html) chip - leverage NFC connectivity for enhanced connectivity with smart phones.
* LiPO charging section with [power gauge](https://www.maximintegrated.com/en/products/power/battery-management/MAX17048.html) - you can check the battery level from your sketches.<br/>

##TUINO 1 PINOUT
Here is the pinout of the Tuino 1<br/>
<img src="/docs/tuino_pinout.png"/>

##DIFFERENCES WITH ARDUINO UNO
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


##RTC
The RTC clock is based on the M41T62 chip.<br/>
<br/>

##NFC
The Tunio 1 one has an onboard NFC chip and a header to install an NFC antenna. The NFC chip is the M24SR04.<br/>
<br/>

##LiPO AND POWER GAUGE
The LiPO charging is driven by the MCP73831. A power gauge chip MAX17048 is present on the I2C bus so that you can always keep under control the charge level of the battery.<br/>
<br/> 


##GMX MODULES
The most important feature we have added is the GMX bus - this is an additional bus that exploits the additional I/O pins of the 1284P and with which you can add different RF modules. - leveraging different technologies for your IoT projects.<br/>
Here's the pinout<br/>
<img src="/docs/gmx_pinout2.png"/>

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
You are now ready to add the Tuino 1 to your IDE.<br/> 
Go to Tools->Board->Board Manager and look for the Tuino board, and finally click on install...
<br>

More info coming up very soon... Stay tuned!
