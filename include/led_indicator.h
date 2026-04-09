#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "config.h"

// =============================================================================
// LedIndicator - WS2812 NeoPixel feedback for mode changes
// =============================================================================

class LedIndicator {
public:
    /// Initialize NeoPixel
    void begin();

    /// Show a color for LED_SHOW_DURATION_MS then auto-off
    void showColor(uint32_t color);

    /// Force LED off immediately
    void off();

    /// Call from loop() to handle auto-off timing
    void update();

private:
    Adafruit_NeoPixel _pixel{LED_COUNT, PIN_LED_NEOPIXEL, NEO_GRB + NEO_KHZ800};
    bool     _active = false;
    uint32_t _showStart = 0;
};

extern LedIndicator ledIndicator;
