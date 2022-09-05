#ifndef CLOCK_H
#define CLOCK_H
#include "Ticker.h"
#include <Arduino.h>
class Clock {

 private: 

  unsigned long durationSeconds ;  
  Ticker ticker ;

  public:
    int minuteCounter = 0 ;

    Clock( unsigned long durationSeconds ): durationSeconds( durationSeconds ) { 

    }; 

    bool isRunning( ){
      return ticker.lastTick < durationSeconds ; 
    }
 
    boolean firstHalf( ) {
      return ticker.lastTick < ( durationSeconds / 2 ) ;
    }    

    void tick( ) 
    {
      if( !this->isRunning( ) ) return ; 
      ticker.tick( );
      this->minuteCounter += ticker.lastTick % 60 ? 0 : 1 ;
    };
};

#endif
