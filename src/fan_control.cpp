#include "fan_control.h"

// =============================================================================
// FanControl - PWM Fan Driver Implementation (no tachometer)
// =============================================================================

FanControl fan;

void FanControl::begin() {
    pinMode(PIN_FAN_PWM, OUTPUT);
    analogWriteFreq(FAN_PWM_FREQUENCY);
    analogWriteRange(FAN_PWM_MAX);
    analogWrite(PIN_FAN_PWM, 0);
    _duty = 0;
}

void FanControl::setDuty(uint8_t duty) {
    _duty = duty;
    analogWrite(PIN_FAN_PWM, _duty);
}

uint8_t FanControl::getDuty() const {
    return _duty;
}
