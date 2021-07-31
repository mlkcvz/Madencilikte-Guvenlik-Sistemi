#include "Zamanlama.h" 

Zamanlama::Zamanlama(int period){
  this -> timeLast = millis();
  this -> period = period;
}

void Zamanlama::countTime(Sensor& ortam, Transfer& transferControl){                    // MAIN LOOPTA ÇALIŞTIR. 
  byte  belirtec = ortam.getBelirtec();
  int seviye = ortam.getSeviye();
  byte tip = ortam.getTip();
  this -> timeCurrent = millis();
  if ( (timeCurrent - timeLast) >= minToMilis() ) // <period> dakika dolduysa... 
  {
    this -> timeLast = this -> timeCurrent; //Şu andan yeniden ölçüm başlat.
    
    Zamanlama::trigger( tip,  seviye , belirtec, transferControl);             //tetikleyici çalıştır.
    
  }
}

void Zamanlama::trigger(byte tip, int seviye, byte belirtec, Transfer& transferControl ){
   String transferMsg = "timer+"+String(tip)+"+"+String(seviye)+"+"+String(belirtec)+"";
   transferControl.transferEt(transferMsg);
}


unsigned long Zamanlama::minToMilis()   
{
  return (this->period * 60000);
}
