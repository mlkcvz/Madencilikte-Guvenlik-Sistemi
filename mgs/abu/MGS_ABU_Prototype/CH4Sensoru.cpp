#include "CH4Sensoru.h"

CH4Sensoru::CH4Sensoru(byte pin, byte tip):Sensor(pin, tip){
  init(); 
  this->tip = 04;
}

void CH4Sensoru::runAlgorithm() {
  seviye = analogRead(A2);   
  if (seviye !=0) {
    
  if (seviye >= 700 && seviye <= 1200)
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
  }
  else if (seviye >= 100 && seviye < 700 )
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye > 50   && seviye < 100)
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

int CH4Sensoru::getSeviye(){
  return this->seviye;
}

byte CH4Sensoru::getBelirtec(){
  return this->belirtec;
}
byte CH4Sensoru::getTip(){
  return this->tip;
}
