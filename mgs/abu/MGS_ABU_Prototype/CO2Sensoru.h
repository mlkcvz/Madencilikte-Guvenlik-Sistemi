#ifndef MY_CO2SENSORU_H
#define MY_CO2SENSORU_H
#include "Sensor.h"
#include <Arduino.h>

class CO2Sensoru : public Sensor {
  public:
    void runAlgorithm() override;
    CO2Sensoru( byte pin, byte tip );
    byte pin;
    byte tip;
    int seviye;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif
