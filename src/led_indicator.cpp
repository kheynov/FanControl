#include "led_indicator.h"

// =============================================================================
// LedIndicator - WS2812 NeoPixel Implementation
// =============================================================================

LedIndicator ledIndicator;

void LedIndicator::begin() {
    _pixel.begin();
    _pixel.setBrightness(LED_BRIGHTNESS);
    _pixel.clear();
    _pixel.show();
}

void LedIndicator::showColor(uint32_t color) {
    _pixel.setPixelColor(0, color);
    _pixel.show();
    _showStart = millis();
    _active = true;
}

void LedIndicator::off() {
    _pixel.clear();
    _pixel.show();
    _active = false;
}

void LedIndicator::update() {
    if (_active && (millis() - _showStart >= LED_SHOW_DURATION_MS)) {
        off();
    }
}
