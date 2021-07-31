#include "SicaklikSensoru.h"
#include "NemSensoru.h"

SicaklikSensoru::SicaklikSensoru(byte pin, byte tip):Sensor(pin, tip){
  init();
  this->tip = 07; 
}

void SicaklikSensoru::runAlgorithm( ){
  
  seviye = (int)DHT11.temperature;
  int chk = DHT11.read(DHT11PIN);
if(seviye =! 0) {
  if(seviye = 1){
    seviye = random(20, 30);
  }
  if (seviye >=40  && seviye <= 90)
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
   
  }
  else if (seviye >=0 && seviye <40)
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye >= -20 && seviye <0)
  {
    //do sth
    belirtec = 12;             // SEVİYE << DÜŞÜK >>
  } else
  {
    //do sth
    belirtec = 14;             // SEVİYE << ABNORMAL>>
  }
}else {
  this->seviye = random(20,30);
  this->belirtec = 11;
}
}


int SicaklikSensoru::getSeviye(){
  return this->seviye;
}
byte SicaklikSensoru::getBelirtec(){
  return this->belirtec;
}
byte SicaklikSensoru::getTip(){
  return this->tip;
}
 
