/*******************************************************************************
   FranckEinstein90
*******************************************************************************/
#include "Clock.h"
#include "TimeSignal.h"

int halfTimeLightPin = 12 ;


int secondsPinOne   = 2 ;
int secondsPinTwo   = 3 ;
int secondsPinThree = 4 ;
int secondsPinFour = 5 ;

TimeSignal*  secondSignalOne ;
TimeSignal*  secondSignalTwo ;
TimeSignal*  secondSignalThree ;
TimeSignal*  secondSignalFour ;

int totalTimePeriodMinutes = 6;
Clock* clock = new Clock( totalTimePeriodMinutes * 60 ) ;

TimeSignal*  halfSignal ;

class BitCounter {


  setLight(bool onOff, TimeSignal* light) {
      if( onOff ) {
        light->on( ); 
      } else {
        light->off(); 
      }
  }
  
  bool bitOne = false;   
  bool bitTwo = false; 
  bool bitThree = false; 
  bool bitFour = false; 

  public: 
    int counter = 0 ;

    void changeLights( ){ 
      this->setLight( this->bitOne, secondSignalOne ) ;    
      this->setLight( this->bitTwo, secondSignalTwo ) ;    
      this->setLight( this->bitThree , secondSignalThree ) ;    
      this->setLight( this->bitFour, secondSignalFour ) ;    
    }
    
    void tick( ) {
      this->bitOne    = this->counter % 2 ; 
      this->bitTwo    = ( this->counter / 2 ) % 2 ; 
      this->bitThree  = ( this->counter / 4 ) % 2 ; 
      this->bitFour = ( this->counter / 8 ) % 2 ; 

      this->changeLights( ); 
      this->counter += 1 ;
    } 
};

BitCounter* bc ; 

void setup() {

  halfSignal = new TimeSignal( halfTimeLightPin, clock ) ;
  bc = new BitCounter( ) ; 
  secondSignalOne   = new TimeSignal( secondsPinOne ) ;
  secondSignalTwo   = new TimeSignal( secondsPinTwo ) ;
  secondSignalThree = new TimeSignal( secondsPinThree ) ;
  secondSignalFour = new TimeSignal( secondsPinFour ) ;
}

// the loop function runs over and over again forever
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
