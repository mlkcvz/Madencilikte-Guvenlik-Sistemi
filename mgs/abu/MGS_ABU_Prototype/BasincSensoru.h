#ifndef MY_BASINCSENSORU_H
#define MY_BASINCSENSORU_H
#include "Sensor.h"
#include <Arduino.h>
class BasincSensoru : public Sensor {
  public:
    void runAlgorithm() override;
    BasincSensoru( byte pin, byte tip );
    byte pin;
    byte tip;
    int seviye;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif
