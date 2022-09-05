#ifndef TIME_SIGNAL_H
#define TIME_SIGNAL_H 
#include "Clock.h"


class TimeSignal {
    
  private: 

    byte pin; 
    bool state;
    Clock* clock;
    void init(); 

  public: 
  
    TimeSignal( byte pin, Clock* clock = nullptr ) ;
    
    bool isOn( )
    {
      return state ;
    } ; 

    bool isOff( )
    {
      return !state ;
    } ; 


    void on( )     ; 
    void off( )    ; 
    void flip( )   ;
    ~TimeSignal( ) ; 
};

#endif
