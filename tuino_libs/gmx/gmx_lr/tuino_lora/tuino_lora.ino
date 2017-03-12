/* _____  _____  __  __             _____  _____ 
  / ____||_   _||  \/  |    /\     / ____||_   _|
 | |  __   | |  | \  / |   /  \   | (___    | |  
 | | |_ |  | |  | |\/| |  / /\ \   \___ \   | |  
 | |__| | _| |_ | |  | | / ____ \  ____) | _| |_ 
  \_____||_____||_|  |_|/_/    \_\|_____/ |_____|
  (c) 2017 GIMASI SA                                               

 * tuino_lora.ino
 *
 *  Created on: March 11, 2017
 *      Author: Massimo Santoli
 *      Brief: Tuino Lora example
 *      Version: 1.0
 *
 *      License: it's free - do whatever you want! ( provided you leave the credits)
 */

#include "gmx_lr.h"

long int timer_period_to_tx = 20000;
long int timer_millis_lora_tx = 0;
int ledState = 0;

bool data_received=false;

void loraRx(){
  data_received = true;
}


void setup() {
  // put your setup code here, to run once:
  String DevEui;
  String AppEui;
  String AppKey;
  String loraClass;
 
  String adr,dcs;

  byte join_status;
  int join_wait;
  
  Serial.begin(9600);
  Serial.println("Starting");

  // GMX-LR init pass callback function
  gmxLR_init(&loraRx);

  // put here the correct numbers
  gmxLR_setDevEui("00:00:00:00:00:00:00:00");
  gmxLR_setAppEui("00:00:00:00:00:00:00:00");
  gmxLR_setAppKey("01:02:03:04:05:06:07:08:01:02:03:04:05:06:07:08");

  Serial.println("LoRaWAN Params:");
  gmxLR_getDevEui(DevEui);
  Serial.println("DevEui:"+DevEui);
  gmxLR_getAppEui(AppEui);
  Serial.println("AppEui:"+AppEui);
  gmxLR_getAppKey(AppKey);
  Serial.println("AppKey:"+AppKey);
  gmxLR_getClass(loraClass);
  Serial.println("Class:"+loraClass);
  adr = String( gmxLR_getADR() );
  Serial.println("ADR:"+adr);
  dcs = String( gmxLR_getDutyCycle() );
  Serial.println("DCS:"+dcs);
  
  
  Serial.println("Joining...");
  join_wait = 0; 
  while((join_status = gmxLR_isNetworkJoined()) != LORA_NETWORK_JOINED) {

  Serial.print("Join:");
  Serial.println(join_wait);
  
    if ( join_wait == 0 )
      gmxLR_Join();
    
    join_wait++;

    if (!( join_wait % 100 )) {
      gmxLR_Reset();
      join_wait = 0;
    }

    delay(5000);

  };
  

  Serial.println("Network Joined!");
 
}

void loop() {
  // put your main code here, to run repeatedly:

  long int delta_lora_tx;
  String RSSI;
  String SNR;
  String rx_data;
  int port;

   delta_lora_tx = millis() - timer_millis_lora_tx;
   
   // Transmit Period 
   if ( delta_lora_tx > timer_period_to_tx) {

    gmxLR_TXData("010203");
    
    gmxLR_getRSSI(RSSI);
    Serial.println("RSSI: "+RSSI);
    gmxLR_getSNR(SNR);
    Serial.println("SNR: "+SNR);

     timer_millis_lora_tx = millis();

     ledState = ~ledState;
     gmxLR_Led(ledState); 
   }

   if (data_received)
   {
      gmxLR_RXData(rx_data,&port);
      Serial.println("LORA RX DATA:"+rx_data);  
      Serial.print("LORA RX PORT:");
      Serial.println(port);
      
      data_received = false;
   }
  
}
