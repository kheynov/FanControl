#pragma once

#include <Arduino.h>
#include "config.h"

// =============================================================================
// FanControl - PWM Fan Driver (no tachometer)
// =============================================================================

class FanControl {
public:
    /// Initialize PWM output
    void begin();

    /// Set fan duty cycle (0-255)
    void setDuty(uint8_t duty);

    /// Get current duty cycle
    uint8_t getDuty() const;

private:
    uint8_t _duty = 0;
};

extern FanControl fan;
