/***************************************************************************************
   FranckEinstein90
****************************************************************************************/
#include "Clock.h"
#include "TimeSignal.h"

TimeSignal::TimeSignal( byte pin, Clock* clock )
{
  this->pin = pin ;
  init( ) ;
}

void TimeSignal::init( )
{
  pinMode( this->pin, OUTPUT ) ;
  this->on( ) ;
}

void TimeSignal::flip( )
{
  if ( this->state == false )
  {
    this->on( ) ;
    return ;
  }
  this->off( );
}

void TimeSignal::on( )
{
  this->state = true ;
  digitalWrite( this->pin, HIGH ) ;
}

void TimeSignal::off( )
{
  this->state = false ;
  digitalWrite( this->pin, LOW ) ;
}

TimeSignal::~TimeSignal( )
{
  this->off( ) ;
}



int quarterTimeLightPin = 3 ;
int halfTimeLightPin = 12 ;
int secondsLightPin = 2 ;
int totalTimePeriodMinutes = 100 ;
Clock* clock = new Clock( totalTimePeriodMinutes * 60 ) ;

TimeSignal*  halfSignal ;
TimeSignal*  quarterSignal ;
TimeSignal*  secondSignal ;

void setup() {

  halfSignal    = new TimeSignal( halfTimeLightPin, clock ) ;
  quarterSignal = new TimeSignal( 3 );
  secondSignal  = new TimeSignal( secondsLightPin );

}

// the loop function runs over and over again forever
void loop( ) {

  if ( ! clock->isRunning( ) ) {

    if ( halfSignal ) {
      delete halfSignal ;
      halfSignal = NULL ;
    }

    if ( quarterSignal ) {
      delete quarterSignal ;
      quarterSignal = NULL ;
    }

    if ( secondSignal ) {
      delete secondSignal ;
      secondSignal = NULL ;
    }

    return ;

  }

  secondSignal->flip( );

  if ( (! clock->firstHalf( ) ) && halfSignal->isOn( ) ) {
    halfSignal->flip( ) ;
    clock->minuteCounter = 0 ;
  }

  delay( 1000 ) ;
  clock->tick( ) ;

}
