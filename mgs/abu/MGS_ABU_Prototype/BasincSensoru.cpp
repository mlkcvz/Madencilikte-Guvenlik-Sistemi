#include "BasincSensoru.h"

BasincSensoru::BasincSensoru(byte pin, byte tip):Sensor(pin, tip){
  init(); 
  this->tip = 03;
}

void BasincSensoru::runAlgorithm() {
  seviye = random(954,963);  
  if (seviye !=0) {
   
  if (seviye >= 1200 && seviye <= 12000)
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
  }
  else if (seviye >= 700 && seviye < 1200 )
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye > 50   && seviye < 700)
  {
    //do sth
    belirtec = 12;             // SEVİYE << DÜŞÜK >>
  } else
  {
    //do sth
    belirtec = 14;             // SEVİYE << ABNORMAL>>
  }
  }
}

int BasincSensoru::getSeviye(){
  return this->seviye;
}

byte BasincSensoru::getBelirtec(){
  return this->belirtec;
}
byte BasincSensoru::getTip(){
  return this->tip;
}
