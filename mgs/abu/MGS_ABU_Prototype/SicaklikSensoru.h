#ifndef MY_SICAKLIKSENSORU_H
#define MY_SICAKLIKSENSORU_H
#include "Sensor.h"
#include <Arduino.h>
#include <dht11.h>  
#define DHT11PIN 7 

class SicaklikSensoru : public Sensor {
  public:
    SicaklikSensoru( byte pin, byte tip );
    void runAlgorithm()override ;
    byte pin;
    byte tip;
    int seviye;
     dht11 DHT11;
    byte belirtec;
    int getSeviye();
    byte getBelirtec();
    byte getTip(); 
};

#endif
