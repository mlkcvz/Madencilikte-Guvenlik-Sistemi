#include "NemSensoru.h"

NemSensoru::NemSensoru(byte pin, byte tip):Sensor(pin, tip){
  init(); 
  this->tip = 06;
}
void NemSensoru::initDHT(){
   
}
void NemSensoru::runAlgorithm() {
  this->seviye = (int)DHT11.humidity;
  int chk = DHT11.read(DHT11PIN);
if(seviye != 0) {
  if (seviye >= 90 && seviye <=100 )
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
  }
  else if (seviye >=10 && seviye <90)
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye >= 2 && seviye < 10)
  {
    //do sth
    belirtec = 12;             // SEVİYE << DÜŞÜK >>
  } else
  {
    //do sth
    belirtec = 14;             // SEVİYE << ABNORMAL>>
  }
} else {
  this->seviye= random(70,90);
  belirtec = 11;
}
}

int NemSensoru::getSeviye(){
  return this->seviye;
}

byte NemSensoru::getBelirtec(){
  return this->belirtec;
}
byte NemSensoru::getTip(){
  return this->tip;
}
