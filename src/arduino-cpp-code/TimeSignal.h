#ifndef TIME_SIGNAL_H
#define TIME_SIGNAL_H 
#include <Arduino.h>
#include "Clock.h"



class TimeSignal {
    
  private: 

    byte pin; 
    bool state;
    Clock* clock;
    void init(); 

  public: 
  
    TimeSignal( byte pin, Clock* clock = nullptr ) ;
    
    boolean isOn( )
    {
      return state ;
    } ; 

    boolean isOff( )
    {
      return !state ;
    } ; 


    void on( )     ; 
    void off( )    ; 
    void flip( )   ;
    ~TimeSignal( ) ; 
};

#endif
