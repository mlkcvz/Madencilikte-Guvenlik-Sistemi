#ifndef MY_HAVALANDIRMA_H
#define MY_HAVALANDIRMA_H

#include <Arduino.h>
class Havalandirma {
  private:
    
 
  public:
   byte pin;
   Havalandirma(byte pin);
    
    byte level;
    int fanSpeed;
    
   void setFanSpeed();  //1-5 level değerleri 50-250 hıza çevirir. aksi durumlarda hızı 0 belirler
                        //levelin değiştiği durumlardan sonra MUTLAKA ÇALIŞTIR. SPEED DEĞİŞTİR.
    void fanSpeedUp();  //level bir artırır.
    void fanSpeedDown();//level 1 düşürür.
    void init();        //pinleri ve initialize değerleri ayarlar.
    void turnOnFan(byte fanlevel); //1-5 arası değer alır
    void turnOffFan();  //level = 0
    byte getFanLevel(); //byte olarak obje level değerini döndürür.
    
};

#endif
