#ifndef CLOCK_H
#define CLOCK_H
#include <Arduino.h>


class Ticker {

  public: 
    unsigned long lastTick = 0 ;
    void tick() {
      lastTick += 1 ;
    }

};


class Clock {

 private: 

  unsigned long durationSeconds ;  
  Ticker ticker ;

  public:
    int minuteCounter = 0 ;

    Clock( unsigned long durationSeconds ): durationSeconds( durationSeconds ) { 

    }; 

    boolean isRunning( ){
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
