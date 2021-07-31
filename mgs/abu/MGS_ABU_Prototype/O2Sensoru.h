#ifndef MY_O2SENSORU_H
#define MY_O2SENSORU_H
#include "Sensor.h"
#include <Arduino.h>
class O2Sensoru : public Sensor {
  public:
    void runAlgorithm() override;
    O2Sensoru( byte pin, byte tip );
    byte pin;
    byte tip;
    int seviye;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif