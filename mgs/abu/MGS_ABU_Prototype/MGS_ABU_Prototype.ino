#include "Alarm.h"             //----------------------
#include "ABU.h"               //--------------------||
#include "SicaklikSensoru.h"   //       classlar     ||
#include "CO2Sensoru.h"        //--------------------||
#include "CH4Sensoru.h"        //--------------------||
#include "COSensoru.h"         //--------------------||
#include "NemSensoru.h"        //--------------------||
#include "Zamanlama.h"         //--------------------||
#include "Transfer.h"          //----------------------
#include "Havalandirma.h"      //----------------------
#include "BasincSensoru.h"     //----------------------
#include "O2Sensoru.h"        //--------------------||

/* KILL ALL RF24 STUFF! jUST SERIAL CONNECTION! 
#include  <SPI.h>     // -------------------------------
#include "nRF24L01.h" // transfer modül kütüphaneleri ||
#include "RF24.h"     //--------------------------------

const uint64_t kanal = 0xE8E8F0F0E1LL; // transfer iletişim kanalı
RF24 trans(9,10);                      // transfer kütüphane pinleri  

*/
String transferThis[1];                // transfer edilecek bilgiler
String incomingMsg = "";
String lastTransferMsg = "";
byte pinAlarm = 8;  //alarm pini
byte pinFan = 6; 


Zamanlama timerCO2(1);              // timer (1) dakikaya ayarlı...
Zamanlama timerTemp(1);             // timer (1) dakikaya ayarlı...
Zamanlama timerCH4(1);              // timer (1) dakikaya ayarlı
Zamanlama timerHumd(1);             // timer (1) dakikaya ayarlı...
Zamanlama timerPressure(1);         // timer (1) dakikaya ayarlı...
Zamanlama timerCO(1);               // timer (1) dakikaya ayarlı...
Zamanlama timerO2(1);               // timer (1) dakikaya ayarlı...
Alarm alarm(pinAlarm);           // alarm (pinAlarm) pininde çalışıyor
Havalandirma fan(pinFan);                 // fan, (pinFan) pininde çalıışıyor
ABU abu(true);                   // ABU class initialize et
Transfer transferControl(false); // Transfer kontrolü (false) değeriyle initialize et

// <<<< tüm sensör objelerini başlat ----
SicaklikSensoru tempature(A1, 06);
CO2Sensoru co2(A0, 02);
NemSensoru humid(2, 05);
CH4Sensoru ch4(A2, 03);
BasincSensoru pressure(A1, 04);
COSensoru co(A3, 07);
O2Sensoru o2(A3, 01);
//// Sensör objeleri başlat----------->>>>

void setup() {
 trans.begin();                 // nrf transfer başlat
 trans.openWritingPipe(kanal);  // iletişim kanalını aç

 humid.initDHT();
 alarm.init(); // alarm output ayarı
 fan.init();
 Serial.begin(9600);

}

void loop() { 
  

 //<<<<<<<tüm sensör objeleri için timer oluştur-
 timerTemp.countTime(tempature, transferControl); 
 timerCO2.countTime(co2, transferControl);
 timerCH4.countTime(ch4, transferControl);
 timerHumd.countTime(humid, transferControl);
 timerPressure.countTime(pressure, transferControl);
 timerCO.countTime(co, transferControl);
 timerO2.countTime(o2, transferControl);
 ////sensör objeleri timerlar----------------->>>

 
 //<<<<tüm sensör objeleri için runAlgorithm() çalıştır----
 tempature.runAlgorithm();
 co2.runAlgorithm();
 humid.runAlgorithm();
 ch4.runAlgorithm();
 pressure.runAlgorithm();
 co.runAlgorithm();
 o2.runAlgorithm();
////sensör objeleri runAlgorithm()-------------------->>>>>>


//<<<<tüm sensör objeleri için isImportant() methodu çağır---
abu.isImportant(tempature, alarm, fan, transferControl);
abu.isImportant(co2, alarm, fan , transferControl);
abu.isImportant(ch4, alarm, fan , transferControl);
abu.isImportant(humid, alarm, fan , transferControl);
abu.isImportant(pressure, alarm, fan , transferControl);
abu.isImportant(co, alarm, fan , transferControl);
abu.isImportant(o2, alarm, fan , transferControl);
////sensör objeleri isImportant()---------------------->>>>>>

alarm.runAlarm();

//------------------GELEN TRANSFER------------------
//--------------------------------------------------
incomingMsg = Serial.readString();
if(incomingMsg.compareTo("") != 0) {
  if(incomingMsg.compareTo("alarm+0") == 0){
    alarm.turnOffAlarm();
  }
  if(incomingMsg.compareTo("alarm+1") == 0){
    alarm.turnOnAlarm(2);
  }
  if(incomingMsg.compareTo("fan+0") == 0){
    fan.turnOffFan();
   }
  if(incomingMsg.compareTo("fan+1") == 0){
    fan.turnOnFan(1);
  }
  if(incomingMsg.compareTo("fan+2") == 0){
    fan.turnOnFan(2);
  }
  if(incomingMsg.compareTo("fan+3") == 0){
    fan.turnOnFan(3);
  }
  if(incomingMsg.compareTo("fan+4") == 0){
    fan.turnOnFan(4);
  }
  if(incomingMsg.compareTo("fan+5") == 0){
    fan.turnOnFan(5);
  }
  incomingMsg= "";
}
//--------------------------------------------------------//
}
