#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <Arduino.h>

class EdgeDetector {
  public:
    EdgeDetector(uint8_t pin, uint16_t debounceMs = 50);
    void update();
    bool rising();
    bool falling();

  private:
    uint8_t _pin;
    uint16_t _debounceMs;
    bool _lastState;
    bool _rising;
    bool _falling;
    unsigned long _lastChangeTime;

    volatile uint8_t* _portInputReg;
    uint8_t _bitMask;
};

#endif // EDGE_DETECTOR_H
