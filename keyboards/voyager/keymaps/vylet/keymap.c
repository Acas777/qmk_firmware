#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#include "sequence_transform/sequence_transform.h"

/// qmk compile -kb voyager -km vylet

enum custom_keycodes {
    US_MAG1 = SAFE_RANGE,
    US_MAG2,
    US_MAG3,
    US_MAG4,
    US_D_UND, // other custom keycodes start here
    US_QUOT_S,
    RGB_SLD,
    HSV_193_230_116,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_PSCR,                                        KC_CAPS,        OSM(MOD_RSFT),  OSM(MOD_RCTL),  OSM(MOD_RALT),  OSM(MOD_RGUI),  RGB_TOG,        
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_B,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_V,           KC_G,           KC_D,           KC_K,                                           KC_Z,           US_MAG1,        KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                                                    KC_SPACE,       OSL(1),         RCTL(KC_BSPC),  OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_SLASH,       KC_QUES,        KC_TILD,        
    KC_TRNS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_PLUS,        
    KC_BSLS,        KC_PIPE,        KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_LABK,                                        KC_RABK,        KC_RPRN,        KC_RBRC,        KC_RCBR,        KC_EQUAL,       KC_TRNS, 
                                                                                    KC_TRNS,        TO(0),          KC_TRNS,        QK_LLCK
  ),
  [2] = LAYOUT_voyager(
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,          
    KC_TRNS,        HSV_193_230_116,KC_HOME,        KC_UP,          KC_END,         KC_PAGE_UP,                                     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       
    KC_TRNS,        KC_DELETE,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       
    KC_TRNS,        RGB_SAD,        RGB_SAI,        RGB_VAD,        RGB_VAI,        RGB_MODE_FORWARD,                               KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,       
                                                                                    OSM(MOD_LSFT),  OSM(MOD_LGUI),  KC_TRNS,        KC_TRNS
  ),
  [3] = LAYOUT_voyager(
    KC_TILD,        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,                                           KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS, 
    KC_GRAVE,       KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_T,           KC_M,           KC_UP,          KC_Y,           KC_P,           KC_NO, 
    KC_NO,          KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,                                           KC_G,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_I,           KC_NO,          
    KC_NO,          KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_B,           KC_H,           KC_J,           KC_K,           KC_L,           KC_ENTER,       
                                                    KC_SPACE,       KC_BSPC,                                        KC_RIGHT_GUI,   KC_RIGHT_SHIFT
  ),
  [4] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_RIGHT_GUI,   
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    KC_SPACE,       KC_LEFT_SHIFT,                                  KC_LEFT_ALT,    KC_BSPC
  ),
};

const uint16_t PROGMEM combo0[] = { KC_B, KC_F, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_PAGE_UP, KC_PGDN, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_ESCAPE, KC_TAB, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_GRAVE, KC_TILD, COMBO_END};
const uint16_t PROGMEM combo4[] = { OSM(MOD_LCTL), KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_LEFT_SHIFT, KC_LEFT_CTRL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TO(2)),
    COMBO(combo1, TO(0)),
    COMBO(combo2, TO(3)),
    COMBO(combo3, TO(0)),
    COMBO(combo4, TO(4)),
    COMBO(combo5, TO(0)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_sequence_transform(keycode, record, US_MAG1)) {
        return false;
    }
    switch (keycode) {
      case RGB_SLD:
        if (record->event.pressed) {
          rgblight_mode(1);
        }
        return false;
      case HSV_193_230_116:
        if (record->event.pressed) {
          rgblight_mode(1);
          rgblight_sethsv(193,230,116);
        }
        return false;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_sequence_transform();  // Add this line
}
