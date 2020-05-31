#include QMK_KEYBOARD_H
#include "osjuga.h"

//enum dz60_keycodes {
//    TEST = SAFE_RANGE
//};

enum layer_number {
    _QWERTY = 0,
    _GAME,
    _LAYER2,
    _LAYER1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSPO, XXXXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSPC, LAYER1,
        LAYER2, KC_LGUI, KC_LALT,           KC_SPC, KC_SPC, KC_SPC,             KC_LEFT, KC_DOWN,          XXXXXXX,          KC_UP, KC_RGHT
        ),
    [_GAME] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, LAYER1,
        LAYER2,  KC_LGUI, KC_LALT,          KC_SPC, KC_SPC, KC_SPC,             KC_LEFT, KC_DOWN,          XXXXXXX,          KC_UP, KC_RGHT
        ),
    [_LAYER1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, RGB_VAI, _______, RGB_HUI, RGB_SAI, KC_BRIU, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, KC_BRID, QWERTY,  GAME,    _______, _______, _______,          _______,
        _______, _______, RGB_TOG, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,          _______, _______, _______,          _______, _______,          _______,          _______, _______
        ),
    [_LAYER2] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,          _______, _______, _______,          _______, _______,          _______,          _______, _______
        )
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case TEST:
//            if (record->event.pressed) {
//                backlight_toggle();
//                rgblight_toggle();
//            }
//            return false;
//        default:
//            return true;
//    }
//}