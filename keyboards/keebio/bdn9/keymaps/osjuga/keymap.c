#include QMK_KEYBOARD_H
#include "osjuga.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_SLEP, MO(2),   DF(1),
        KC_MUTE,  KC_MPLY, KC_PGUP,
        KC_MPRV, KC_MNXT, KC_PGDN
    ),
    [1] = LAYOUT(
        XXXXXXX, MO(2), DF(0),
        KC_1, XXXXXXX, KC_K,
        KC_D, KC_F, KC_J
    ),
    [2] = LAYOUT(
        SELFFLSH,_______, _______,
        RESET,   _______, _______,
        _______, _______, _______
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        tap_code(clockwise ? KC_VOLD : KC_VOLU);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SELFFLSH:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb keebio/bdn9 -km osjuga\n");
                SEND_STRING("qmk flash -kb keebio/bdn9 -km osjuga -bl dfu\n");
                reset_keyboard();
            }
            return false;
        default:
            return true;
    }
}