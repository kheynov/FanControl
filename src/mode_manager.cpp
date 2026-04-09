#include "mode_manager.h"

// =============================================================================
// ModeManager - Simple static mode cycling
// =============================================================================

ModeManager modeManager;

uint8_t ModeManager::getCurrentModeIndex() const {
    return _currentMode;
}

const FanModeConfig& ModeManager::getCurrentMode() const {
    return FAN_MODES[_currentMode];
}

void ModeManager::nextMode() {
    _currentMode = (_currentMode + 1) % FAN_MODE_COUNT;
}

void ModeManager::setMode(uint8_t index) {
    if (index < FAN_MODE_COUNT) {
        _currentMode = index;
    }
}
