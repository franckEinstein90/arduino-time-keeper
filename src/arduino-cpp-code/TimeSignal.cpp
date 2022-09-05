/*******************************************************************************
   FranckEinstein90 made this
*******************************************************************************/
#include "TimeSignal.h"
/******************************************************************************/

void TimeSignal::init( )
{
  pinMode( this->pin, OUTPUT ) ;
  this->on( ) ;
}

TimeSignal::TimeSignal( 
    byte pin, 
    Clock* clock )
{
  this->pin = pin ;
  init( ) ;
}

TimeSignal::~TimeSignal( )
{
  this->off( ) ;
}
/******************************************************************************/

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

