#ifndef BIT_COUNTER_H
#define BIT_COUNTER_H 

#include "TimeSignal.h"

class BitCounter {
    
    
    private: 

        bool bits[4] = {false, false, false, false} ;
        TimeSignal*  timeSignals[4] ;

        void setLight( bool onOff, TimeSignal* light ) 
        {
            onOff ?  light->on( ) : light->off( ) ; 
        } ; 

        unsigned long counter = 0 ;

    public: 
            BitCounter( int pinOne, int pinTwo, int pinThree, int pinFour ) {
                this->timeSignals[0] = new TimeSignal( pinOne ) ;
                this->timeSignals[1] = new TimeSignal( pinTwo ) ; 
                this->timeSignals[2] = new TimeSignal( pinThree ) ; 
                this->timeSignals[3] = new TimeSignal( pinFour );   
            } ; 

            ~BitCounter( ) {
                for ( int i = 0 ; i < 4 ; i++ ) {
                    delete this->timeSignals[i] ; 
                }
            } ;

            void changeLights( ){ 
                for(int i = 0; i < 4; i++ ) setLight( bits[i], timeSignals[i] ) ; 
            } ; 
    
            void tick( ) {
                this->counter++ ; 
                for(int i = 0; i < 4; i++ ) bits[i] = (this->counter >> i) & 1 ; 
                changeLights( ) ; 
            } ; 
};

#endif
