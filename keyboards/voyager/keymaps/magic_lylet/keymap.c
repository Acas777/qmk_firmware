#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#include "features/magic.h"
#include "features/layer_lock.h"

/// qmk compile -kb voyager -km magic_vylet_v2

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    LLOCK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_B,                                           KC_Z,           US_AREP,        KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_L,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_V,           KC_G,           KC_D,           KC_K,                                           KC_X,           KC_R,           KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         RCTL(KC_BSPC),  OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ESCAPE,      KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_EQUAL,       KC_PLUS,        KC_QUES,        
    KC_BSPC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_SLASH,       
    KC_GRAVE,       KC_TILD,        KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_PIPE,                                        TO(2),          KC_RPRN,        KC_RBRC,        KC_RCBR,        KC_BSLS,        KC_RIGHT_GUI,       
                                                    KC_SPACE,       TO(0),                                          TO(0),          LLOCK
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(4),          LCTL(LSFT(KC_TAB)),LALT(KC_LEFT),  KC_UP,          LALT(KC_RIGHT), KC_PSCR,                                        RGB_VAI,        KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,LCTL(LSFT(KC_T)),TO(3),          
    KC_BSPC,        LCTL(KC_TAB),   KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_SYSTEM_SLEEP,                                RGB_VAD,        KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,LCTL(KC_T),     KC_CAPS,        
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
                                                    KC_SPACE,       KC_LEFT_GUI,                                    TO(0),          LCTL(KC_W)
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_0,           TO(0),          
    KC_TAB,         KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_T,           KC_Y,           KC_UP,          KC_I,           KC_P,           KC_NO,          
    KC_LEFT_SHIFT,  KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,                                           KC_G,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    KC_LEFT_CTRL,   KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_M,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_ENTER,       
                                                    KC_SPACE,       KC_RIGHT_GUI,                                   KC_BSPC,        KC_RIGHT_SHIFT
  ),
  [4] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_ENTER,       
                                                    KC_SPACE,       KC_RIGHT_GUI,                                   TO(0),          KC_RIGHT_SHIFT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_J, KC_MINUS, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, OSM(MOD_LALT)),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116} },

    [1] = { {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,210,154}, {135,218,204}, {97,135,168}, {101,219,215}, {97,135,168}, {141,75,215}, {250,143,163}, {135,218,204}, {101,219,215}, {101,219,215}, {101,219,215}, {141,75,215}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {250,143,163}, {193,230,116}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,75,215}, {101,219,215}, {101,219,215}, {101,219,215}, {135,218,204}, {139,210,154}, {141,75,215}, {97,135,168}, {97,135,168}, {97,135,168}, {135,218,204}, {250,143,163}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {250,143,163} },

    [3] = { {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {139,210,154}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {139,210,154}, {139,210,154}, {139,210,154}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {139,210,154}, {193,230,116}, {193,230,116}, {139,210,154}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {139,210,154}, {139,210,154}, {139,210,154}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116}, {193,230,116} },

    [4] = { {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {193,230,116}, {139,210,154} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_value;
    if (magic_pr(keycode, record, &return_value))
        return return_value;
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }
    switch (keycode) {
      case RGB_SLD:
        if (record->event.pressed) {
          rgblight_mode(1);
        }
        return false;
    }
    return true;
}
