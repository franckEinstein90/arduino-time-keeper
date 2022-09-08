/*******************************************************************************
   FranckEinstein90
*******************************************************************************/
#include "Clock.h"
#include "TimeSignal.h"
#include "BitCounter.h"

int halfTimeLightPin = 12 ;


int secondsPinOne   = 2 ;
int secondsPinTwo   = 3 ;
int secondsPinThree = 4 ;
int secondsPinFour  = 5 ;



int totalTimePeriodMinutes = 6;
Clock* clock = new Clock( totalTimePeriodMinutes * 60 ) ;
TimeSignal*  halfSignal ;
BitCounter* bc ; 

void setup() {
  halfSignal = new TimeSignal( halfTimeLightPin, clock ) ; 
  bc = new BitCounter( secondsPinOne, secondsPinTwo, secondsPinThree, secondsPinFour ) ; 
}

void loop( ) {
 /* secondSignalOne->flip( );
  if(secondSignalOne->isOn( )){
    secondSignalTwo->off( );
    secondSignalThree->off( );
  } else {
    secondSignalTwo->on( ); 
    secondSignalThree->on( );
  }

  if ( (! clock->firstHalf( ) ) && halfSignal->isOn( ) ) {
    halfSignal->flip( ) ;
    clock->minuteCounter = 0 ;
  }
*/
  
  delay( 1000 ) ;
  bc->tick( ); 
  clock->tick( ) ;

}
