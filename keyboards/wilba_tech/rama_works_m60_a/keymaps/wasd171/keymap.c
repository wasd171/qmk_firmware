// M60-A layout
#include QMK_KEYBOARD_H

enum layers {
	MAIN,
	MAIN_NORMAL,
	UTIL,
	FUNC
};

// See https://skip.house/blog/qmk-globe-key
enum my_keycodes {
 // Apple globe key
 APPLE_GLOBE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case APPLE_GLOBE:
    host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
    return false;
  }

  return true;
};

// See https://docs.qmk.fm/features/combo
const uint16_t PROGMEM lshift_rshift[] = {SC_LSPO, SC_RSPC, COMBO_END};
const uint16_t PROGMEM lshift_space_rshift[] = {SC_LSPO, KC_SPC, SC_RSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(lshift_rshift, DF(MAIN_NORMAL)),
    COMBO(lshift_space_rshift, DF(MAIN)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Main layer
[MAIN] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT, KC_ENT,
	SC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, SC_RSPC, MO(FUNC),
	         KC_LGUI, KC_LALT,                            LT(UTIL, KC_SPC),              		KC_RALT, APPLE_GLOBE),

// Main (normal) layer (normal Space key)
[MAIN_NORMAL] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT, KC_ENT,
	SC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, SC_RSPC, MO(FUNC),
	         KC_LGUI, KC_LALT,                            KC_SPC,                     			KC_RALT, APPLE_GLOBE),

// Util layer
[UTIL] = LAYOUT_60_hhkb(
	KC_ESC,  KC_BRID, KC_BRIU, _______, _______, BL_DOWN, BL_UP,   KC_MPRV, KC_MPLY,    KC_MNXT,   KC_MUTE, KC_VOLD, KC_VOLU,  LCTL(LCMD(KC_Q)),  KC_DEL,
	KC_CAPS, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T), G(KC_Y), G(KC_U), G(KC_I),    G(KC_O),   G(KC_P), KC_UP,   _______, _______,
	_______, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G), G(KC_H), G(KC_J), G(KC_K),    G(KC_L),   KC_LEFT, KC_RGHT, _______,
	_______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), G(KC_N), G(KC_M), G(KC_COMM), G(KC_DOT), KC_DOWN, _______, _______,
	         _______, _______,                            _______,                                 _______, _______),

// Func layer
[FUNC] = LAYOUT_60_hhkb(
	KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	         _______, _______,                            _______,                            _______, _______),

};
