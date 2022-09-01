/***************************************************************************************
 * FranckEinstein90
****************************************************************************************/


int secondLightPin = 2; 
int seconds = 0; 

int halfTimeLightPin = 12; 
int totalTimePeriodMinutes = 20; 
int minutes = 0; 



class TimeSignal {

  private: 
    byte pin; 
    bool state;
       
  public: 
  
    TimeSignal( byte pin )
    {
      this->pin = pin; 
      init(); 
    }

    void init()
    {
      pinMode(this->pin, OUTPUT); 
      this->on(); 
    }

    void flip()
    {
      if(this->state == false){
        this->on(); 
        return ;
      }
      this->off(); 
    }

    private: 

      void on()
      {
        this->state = true; 
        digitalWrite(this->pin, HIGH);
      }
    
      void off()
      {
        this->state = false; 
        digitalWrite(this->pin, LOW); 
      }
};


TimeSignal*  half; 
void setup() {

  half = new TimeSignal(halfTimeLightPin); 
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
 
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite( 2, !( seconds % 2 ) ? HIGH : LOW );  
  
  if( minutes == (int)( totalTimePeriodMinutes / 2 ) ) {
    half->flip();  
    minutes = 0;   
  } 
  
  delay(1000);            
  seconds += 1; 
  if(seconds % 60 == 0) {
    minutes += 1; 
  }
 }
