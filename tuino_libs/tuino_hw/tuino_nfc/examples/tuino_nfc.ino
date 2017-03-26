#include "M24SR.h"
#include "NdefMessage.h"
#include "NdefRecord.h"

#define gpo_pin TUINO_INTERRUPT

M24SR m24sr04(gpo_pin);

void setup() {
 Serial.begin(9600);
   // for debug purpose
   //m24sr04._verbose = true;
   //m24sr04._cmds = true;

   // Start M24SR
   m24sr04._setup();

   NdefMessage message = NdefMessage();
   message.addUriRecord("http://www.gimasi.ch");          
   m24sr04.writeNdefMessage(&message);
   
   Serial.print(F("\r\nUse NFC phone/reader to read out NFC tag content!"));

}

void loop() {

     if (m24sr04.checkGPOTrigger()) {
        displayNDefRecord();
    }
    delay(200);
}

void displayNDefRecord() {
    //read NDef message from memory
    NdefMessage* pNDefMsg = m24sr04.getNdefMessage();
    
    if (pNDefMsg != NULL) {
       pNDefMsg->print();
       NdefRecord rec = pNDefMsg->getRecord(0);
       String txt = rec.toString();
       Serial.print(F("NDefRecord: "));
       Serial.println(txt);
       
       delete pNDefMsg;
    }
}

