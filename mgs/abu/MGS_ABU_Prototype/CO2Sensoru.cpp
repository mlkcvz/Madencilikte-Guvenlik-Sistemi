#include "CO2Sensoru.h"

CO2Sensoru::CO2Sensoru(byte pin, byte tip):Sensor(pin, tip){
  init(); 
  this->tip = 02;
}

void CO2Sensoru::runAlgorithm() {
  seviye = analogRead(A0);   

  if (seviye >= 700 && seviye <= 900)
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
  }
  else if (seviye >= 150 && seviye < 700)
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye >= 100  && seviye < 150 )
  {
    //do sth
    belirtec = 12;             // SEVİYE << DÜŞÜK >>
  } else
  {
    //do sth
    belirtec = 14;             // SEVİYE << ABNORMAL>>
  }
  
}

int CO2Sensoru::getSeviye(){
  return this->seviye;
}

byte CO2Sensoru::getBelirtec(){
  return this->belirtec;
}
byte CO2Sensoru::getTip(){
  return this->tip;
}
