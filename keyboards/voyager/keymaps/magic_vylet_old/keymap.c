#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    MG_ECAUSE,
    MG_AN,
    MG_ON_QUOT_T,
    MG_ON,
    MG_UST,
    MG_EALLY,
    MG_MENT,
    MG_OU,
    MG_LL,
    MG_ALL
};

#define C_MAGIC QK_AREP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           MT(MOD_LALT, KC_RIGHT_GUI),
    KC_TAB,         KC_W,           KC_C,           KC_M,           KC_P,           KC_K,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_J,           KC_MINUS,       
    KC_BSPC,        KC_R,           KC_S,           KC_T,           KC_H,           KC_F,                                           KC_Y,           KC_N,           KC_A,           KC_E,           KC_I,           KC_COMMA,       
    OSM(MOD_LCTL),  KC_Q,           KC_V,           KC_G,           KC_D,           KC_B,                                           KC_Z,           C_MAGIC,        KC_QUOTE,       KC_SCLN,        KC_DOT,         KC_ENTER,       
                                                    KC_SPACE,       OSL(1),                                         TO(2),          OSM(MOD_RSFT)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_EQUAL,       KC_PLUS,        KC_SLASH,       
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_QUES,        
    KC_CAPS,        KC_GRAVE,       KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_PIPE,                                        KC_BSLS,        KC_RPRN,        KC_RBRC,        KC_RCBR,        KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, TO(0),                                          TO(0),          KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(4),          
    KC_NO,          KC_NO,          LCTL(LSFT(KC_TAB)),KC_UP,          LCTL(KC_TAB),   KC_PSCR,                                        KC_NO,          LCTL(KC_T),     LCTL(LSFT(KC_UP)),LCTL(LSFT(KC_T)),KC_NO,          TO(3),          
    KC_TRANSPARENT, KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_SYSTEM_SLEEP,                                KC_NO,          LCTL(LSFT(KC_LEFT)),LCTL(LSFT(KC_DOWN)),LCTL(LSFT(KC_RIGHT)),KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          RGB_TOG,        TOGGLE_LAYER_COLOR,LED_LEVEL,      
                                                    KC_TRANSPARENT, KC_LEFT_GUI,                                    TO(0),          LCTL(KC_W)
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_0,           TO(0),          
    KC_GRAVE,       KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_T,           KC_Y,           KC_UP,          KC_I,           KC_P,           KC_NO,          
    KC_NO,          KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,                                           KC_G,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    KC_NO,          KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_M,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_RIGHT_GUI,   
                                                    KC_SPACE,       KC_ENTER,                                       KC_RIGHT_SHIFT, KC_BSPC
  ),
  [4] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TO(0),          
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_GUI,   
                                                    KC_SPACE,       KC_ENTER,                                       KC_RIGHT_SHIFT, KC_BSPC
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {135,218,204}, {11,218,204}, {135,218,204}, {250,218,204}, {0,0,0}, {0,0,0}, {11,218,204}, {11,218,204}, {11,218,204}, {250,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {199,206,210}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,210,154}, {0,0,0}, {135,218,204}, {11,218,204}, {135,218,204}, {0,0,0}, {19,187,210}, {0,0,0}, {11,218,204}, {11,218,204}, {11,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,72,233}, {141,72,233}, {141,72,233}, {0,0,255}, {135,218,204} },

    [3] = { {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {139,210,154}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {139,210,154}, {139,210,154}, {139,210,154}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {0,0,255}, {19,187,210}, {19,187,210}, {139,210,154}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {139,210,154}, {139,210,154}, {139,210,154}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210}, {19,187,210} },

    [4] = { {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {0,0,255}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154}, {139,210,154} },

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

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A: return KC_L;
        case KC_B: return MG_ECAUSE;
        case KC_C: return MG_AN;
        case KC_D: return MG_ON_QUOT_T;
        case KC_E: return KC_U;
        case KC_G: return KC_T;
        case KC_I: return MG_ON;
        case KC_J: return MG_UST;
        case KC_K: return KC_S;
        case KC_M: return KC_B;
        case KC_N: return KC_L;
        case KC_O: return KC_A;
        case KC_P: return KC_H;
        case KC_R: return MG_EALLY;
        case KC_S: return KC_C;
        case KC_T: return MG_MENT;
        case KC_U: return KC_E;
        case KC_W: return KC_R;
        case KC_Y: return MG_OU;
        case KC_Z: return KC_L;
        case KC_QUOT: return MG_LL;
        case KC_SPC: return MG_ALL;
        case KC_1 ... KC_0: return KC_DOT;
    }
    return MG_ALL;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    int rep_count = get_repeat_key_count();
        switch (keycode) {
            case RGB_SLD:
                if (record->event.pressed) {
                    rgblight_mode(1);   
                }
                return false;
            case MG_ECAUSE:
                SEND_STRING("ecause");
                return false;
            case MG_AN:
                if (rep_count < -1) {
                    SEND_STRING("'t");
                } else {
                    SEND_STRING("an");
                }
                return false;
            case MG_ON_QUOT_T:
                SEND_STRING("on't");
                return false;
            case MG_ON:
                SEND_STRING("on");
                return false;
            case MG_UST:
                if (rep_count < -1) {
                    SEND_STRING("ment");
                } else {
                    SEND_STRING("ust");
                }
                return false;
            case MG_EALLY:
                SEND_STRING("eally");
                return false;
            case MG_MENT:
                SEND_STRING("ment");
                return false;
            case MG_OU:
                if (rep_count < -2) {
                    SEND_STRING("ll");
                    return false;
                }
                if (rep_count < -1) {
                    send_char('\'');
                    return false;
                }
                    SEND_STRING("ou");
                    return false;
            case MG_LL:
                SEND_STRING("ll");
                return false;
            case MG_ALL:
                SEND_STRING("all");
                return false;
            }
    }
    return true;
}