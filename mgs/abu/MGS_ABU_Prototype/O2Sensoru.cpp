#include "O2Sensoru.h"

O2Sensoru::O2Sensoru(byte pin, byte tip):Sensor(pin, tip){
  init(); 
  this->tip = 01;
}

void O2Sensoru::runAlgorithm() {
  seviye = random(420, 450);
   
  if (seviye >= 580 && seviye <= 650)
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
  }
  else if (seviye >=400 && seviye <580)
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye >= 355 && seviye < 400)
  {
    //do sth
    belirtec = 12;             // SEVİYE << DÜŞÜK >>
  } else
  {
    //do sth
    belirtec = 14;             // SEVİYE << ABNORMAL>>
  }
  
}

int O2Sensoru::getSeviye(){
  return this->seviye;
}

byte O2Sensoru::getBelirtec(){
  return this->belirtec;
}
byte O2Sensoru::getTip(){
  return this->tip;
}
