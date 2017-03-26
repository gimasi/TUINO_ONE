# TUINO NFC

The Tunio 1 one has an onboard NFC chip and a header to install an NFC antenna. The NFC chip is the M24SR04.<br/>
The full specs of the chip can be found [here](http://www.st.com/en/nfc/m24sr04-g.html)<br/>
<br/>
To make life easier we have collected different libraries present on the web for this chip, and added a couple of tweaks here and there.<br/>
We are only implementing in our code the NDEF (NFC Data Exchange Format, if you want other RFID formats you should look around and tweak the code yourself ( at least for the time being)<br/>
<br/> 
The original libraries, with full credit to the original authors, are these:
* [https://github.com/rena2019/ArduinoM24SR](https://github.com/rena2019/ArduinoM24SR)<br/>
* [https://github.com/don/NDEF](https://github.com/don/NDEF)<br/>

## IMPORTANT

The M24SR can we written by the Tuino and read by an external device, but it can also be written by an external device and the Tuino can read it's content. This is very useful in developing headless IoT sensors ( like most sensors are ) to setup or acquire information from it.<br/>
The NFC is interrupt driven, so to have the Tuino being alerted when an external device is writes something to the NFC tag you need to connect correcly J4 jumper, and select the GPO output. This is valid for rev b of the current hardware, the next version rev c, will not have this jumper and the interrupt pin will be connected directly to the Tuino CPU.<br/>
