#include "COSensoru.h"
//A3 pin
COSensoru::COSensoru(byte pin, byte tip): Sensor(pin, tip) {
  init();
  this->tip = 05;
}

void COSensoru::runAlgorithm() {
  seviye = analogRead(A3);
  if (seviye >= 600 && seviye <= 750)
  {
    //do sth
    belirtec = 13;              //SEVİYE << YÜKSEK >>
  }
  else if (seviye >= 70 && seviye < 600)
  {
    //do sth
    belirtec = 11;              //SEVİYE << NORMAL >>
  } else if (seviye >= 10 && seviye < 70)
  {
    //do sth
    belirtec = 12;             // SEVİYE << DÜŞÜK >>
  } else
  {
    //do sth
    belirtec = 14;             // SEVİYE << ABNORMAL>>
  }

}

int COSensoru::getSeviye() {
  return this->seviye;
}

byte COSensoru::getBelirtec() {
  return this->belirtec;
}
byte COSensoru::getTip() {
  return this->tip;
}
