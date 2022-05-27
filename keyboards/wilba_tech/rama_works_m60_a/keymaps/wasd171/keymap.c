// M60-A layout
#include QMK_KEYBOARD_H

#define MAIN 0
#define UTIL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Main layer
[MAIN] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT, KC_ENT,
	KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_RSPC, _______,
	         KC_LGUI, KC_LALT,                            LT(UTIL, KC_SPC),                     KC_RALT, _______),

// Util layer
[UTIL] = LAYOUT_60_hhkb(
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
	KC_CAPS, G(KC_Q), G(KC_W), _______, _______, G(KC_T), _______, _______, _______, G(KC_O),   G(KC_P), KC_UP,   _______, _______,
	_______, G(KC_A), G(KC_S), _______, G(KC_F), _______, _______, _______, _______, _______,   KC_LEFT, KC_RGHT, _______,
	_______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), _______, G(KC_N), _______, _______, G(KC_DOT), KC_DOWN, _______, _______,
	         _______, _______,                            _______,                              _______, _______),

};
