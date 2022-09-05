#ifndef TICKER_H
#define TICKER_H

class Ticker {

  public: 
    unsigned long lastTick = 0 ;
    void tick() {
      lastTick += 1 ;
    }

};


#endif