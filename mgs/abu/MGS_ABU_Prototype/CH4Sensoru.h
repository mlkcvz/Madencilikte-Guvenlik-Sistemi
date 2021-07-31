#ifndef MY_CH4SENSORU_H
#define MY_CH4SENSORU_H
#include "Sensor.h"
#include <Arduino.h>
class CH4Sensoru : public Sensor {
  public:
    void runAlgorithm() override;
    CH4Sensoru( byte pin, byte tip );
    byte pin;
    byte tip;
    int seviye;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif