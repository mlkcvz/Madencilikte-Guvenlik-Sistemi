#ifndef MY_COSENSORU_H
#define MY_COSENSORU_H
#include "Sensor.h"
#include <Arduino.h>
class COSensoru : public Sensor {
  public:
    void runAlgorithm() override;
    COSensoru( byte pin, byte tip );
    byte pin;
    byte tip;
    int seviye;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif