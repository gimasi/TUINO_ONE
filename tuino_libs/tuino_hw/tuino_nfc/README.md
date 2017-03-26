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