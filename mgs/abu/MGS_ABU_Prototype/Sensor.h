#ifndef MY_SENSOR_H
#define MY_SENSOR_H

#include "Alarm.h"
#include <Arduino.h>
class Sensor {
   
  public:
    byte pin;
    byte tip;
    int seviye;
    byte belirtec; 
    Sensor( byte pin, byte tip );
    void init();
    virtual void runAlgorithm() = 0;
    virtual int getSeviye();
    virtual byte getBelirtec();
    virtual byte getTip(); 
    
};

#endif
