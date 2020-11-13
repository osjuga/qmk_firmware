#include QMK_KEYBOARD_H
#include "osjuga.h"

enum alt_keycodes {
    U_T_AUTO = NEW_SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    MD_BOOT,               //Restart into bootloader after hold timeout
};

int layoutState = 0; // 0 qwerty, 1 game, 2 colemak

keymap_config_t keymap_config;
#define EXPAND_LAYOUT(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_HOME,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP,   KC_PGDN,
        LAYER2,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, LAYER1,  KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_GAME] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_HOME,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        LAYER2,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, LAYER1,  KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[_LAYER1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, KC_BRIU, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,   KC_END,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, KC_BRID, QWERTY,  GAME,    _______, _______, _______,          _______, KC_VOLU,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLD,
        _______, _______, _______,                            NK_TOGG,                            _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),
    [_LAYER2] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PWR,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, _______, MD_BOOT, _______,
        _______, _______, _______, _______, RAYEBAN, GGWP,    _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,          _______, _______,
        _______, _______, _______,                            KC_P0,                              KC_PDOT, KC_PPLS, _______, _______, _______
    ),
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case GGWP:
            if (record->event.pressed) {
                SEND_STRING("ggwp thanks for the game\n");
            }
            return false;
        case RAYEBAN:
            if (record->event.pressed) {
                SEND_STRING(":rayeban:\n");
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                layoutState = 0;
            }
            return true;
        case GAME:
            if (record->event.pressed) {
                layoutState = 1;
            }
            return true;
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                        break;
                    case LED_FLAG_KEYLIGHT: {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    }
                        break;
                    case LED_FLAG_UNDERGLOW: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    }
                        break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    }
                        break;
                }
            }
            return false;
        default:
            return true;
    }
}

#ifdef RGB_MATRIX_KEYPRESSES
void rgb_matrix_indicators_user() {
    if (rgb_matrix_get_flags() != LED_FLAG_NONE) {
        switch (layoutState) {
            case 0:
                rgb_matrix_set_color(0, RGB_ORANGE);
                break;
            case 1:
                rgb_matrix_set_color(0, RGB_GOLDENROD);
                break;
        }
    } else {
        rgb_matrix_set_color(0, 0, 0, 0);
    }
}
#endif

