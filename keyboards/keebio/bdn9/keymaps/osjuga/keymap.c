#include QMK_KEYBOARD_H
#include "osjuga.h"

enum layer_number {
    _LAYER1 = 0,
    _LAYER2
};

enum bdn9_keycodes {
    TEST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER1] = LAYOUT(
        KC_SLEP, LAYER2,  KC_MUTE,
        KC_PWR,  KC_MPLY, KC_PGUP,
        KC_MPRV, KC_MNXT, KC_PGDN
    ),
    [_LAYER2] = LAYOUT(
        RESET  , _______, _______,
        _______, _______, _______,
        _______, _______, _______
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
