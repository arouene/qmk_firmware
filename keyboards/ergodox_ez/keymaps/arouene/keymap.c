#include QMK_KEYBOARD_H
#include "version.h"

// This keymap is intented to work with US Int keymap

#define BASE 0 // default layer
#define FCNT 1 // function keys
#define GAME 2 // gaming layer
#define BEAKL 3 // beakl layer

// TODO test a BEAKL Layer

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

// Tap dance key definition
enum {
  TD_A = 0,
  TD_C,
  TD_E,
  TD_I,
  TD_W
};

/* Custom names for clarity */
#define CT_OR_Z CTL_T(KC_Z)
#define CT_OR_SL CTL_T(KC_SLSH)
#define META KC_LGUI

/* Custom Keycode */
#define UC_AGRAVE 0xe0
#define UC_CCEDIL 0xe7
#define UC_EGRAVE 0xe8
#define UC_EACUTE 0xe9
#define UC_ECIRCU 0xea
#define UC_ETREMA 0xeb
#define UC_ITREMA 0xef

/* Global variables */
bool leading_mode = false;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | FCNT |           |Reset |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/LALT|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '/RALT |
 * |--------+------+------+------+------+------| GAME |           |EEPROM|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   `  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Meta | Ins  |       | Del  | Meta |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| KC_  |Enter |
 *                                 |      |ace   | End  |       | PgDn | LEAD |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,       KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         _______,
  KC_TAB,       KC_Q,         TD(TD_W),     TD(TD_E),     KC_R,         KC_T,         OSL(FCNT),
  LALT_T(KC_ESC), TD(TD_A),   KC_S,         KC_D,         KC_F,         KC_G,
  KC_LSFT,      CT_OR_Z,      KC_X,         TD(TD_C),     KC_V,         KC_B,         TG(GAME),
  _______,      KC_GRAVE,     _______,      KC_LEFT,      KC_RIGHT,

                                                                        META,         KC_INS,
                                                                                      KC_HOME,
                                                          KC_SPC,       KC_BSPC,      KC_END,

  //  right hand
  _______,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,
  _______,      KC_Y,         KC_U,         TD(TD_I),     KC_O,         KC_P,         KC_BSLS,
                KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,      RALT_T(KC_QUOTE),
  _______,      KC_N,         KC_M,         KC_COMM,      KC_DOT,       CT_OR_SL,     KC_RSFT,
                              KC_UP,        KC_DOWN,      KC_LBRC,      KC_RBRC,      _______,

  KC_DEL,       META,
  KC_PGUP,
  KC_PGDN,      KC_LEAD,      KC_ENT
),

/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[FCNT] = LAYOUT_ergodox(
  // left hand
  _______,      KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F11,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,

                                                                        _______,      _______,
                                                                                      _______,
                                                          _______,      _______,      _______,

  //  right hand
  KC_F12,       KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
                _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
                              _______,      _______,      _______,      _______,      _______,

  _______,      _______,
  _______,
  _______,      _______,      _______
),

/* Keymap 2: Gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[GAME] = LAYOUT_ergodox(
  // left hand
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      KC_Q,         KC_W,         KC_E,         _______,      _______,      _______,
  _______,      KC_A,         KC_S,         KC_D,         _______,      _______,
  _______,      _______,      _______,      KC_C,         _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,

                                                                        _______,      _______,
                                                                                      _______,
                                                          _______,      _______,      _______,

  //  right hand
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
                _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
                              _______,      _______,      _______,      _______,      _______,

  _______,      _______,
  _______,
  _______,      _______,      _______
),

//  /* Keymap x: Test BEAKL Lafayette
//  *
//  * ,--------------------------------------------------.           ,--------------------------------------------------.
//  * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |  6   |  7   |  8   |  9   |  0   |        |
//  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
//  * |        |   J  |   Y  |   O  |   U  |   K  |      |           |      |  G   |  C   |  M   |  N   |  Z   |        |
//  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
//  * |        |   H  |   I  |   E  |   A  |      |------|           |------|  D   |  S   |  T   |  R   |  P   |        |
//  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
//  * |        |   Q  |      |      |      |   X  |      |           |      |  W   |  F   |  L   |  B   |  V   |        |
//  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
//  *   |      |      |      |      |      |                                       |      |      |      |      |      |
//  *   `----------------------------------'                                       `----------------------------------'
//  *                                        ,-------------.       ,-------------.
//  *                                        |      |      |       |      |        |
//  *                                 ,------|------|------|       |------+--------+------.
//  *                                 |      |      |      |       |      |        |      |
//  *                                 |      |      |------|       |------|        |      |
//  *                                 |      |      |      |       |      |        |      |
//  *                                 `--------------------'       `----------------------'
//  */
[BEAKL] = LAYOUT_ergodox(
  // left hand
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,

                                                                        _______,      _______,
                                                                                      _______,
                                                          _______,      _______,      _______,

  //  right hand
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
                _______,      _______,      _______,      _______,      _______,      _______,
  _______,      _______,      _______,      _______,      _______,      _______,      _______,
                              _______,      _______,      _______,      _______,      _______,

  _______,      _______,
  _______,
  _______,      _______,      _______
),

//    /* Keymap x: Blank layer as a template
//  *
//  * ,--------------------------------------------------.           ,--------------------------------------------------.
//  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
//  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
//  *   |      |      |      |      |      |                                       |      |      |      |      |      |
//  *   `----------------------------------'                                       `----------------------------------'
//  *                                        ,-------------.       ,-------------.
//  *                                        |      |      |       |      |        |
//  *                                 ,------|------|------|       |------+--------+------.
//  *                                 |      |      |      |       |      |        |      |
//  *                                 |      |      |------|       |------|        |      |
//  *                                 |      |      |      |       |      |        |      |
//  *                                 `--------------------'       `----------------------'
//  */
// [BLNK] = LAYOUT_ergodox(
//   // left hand
//   _______,      _______,      _______,      _______,      _______,      _______,      _______,
//   _______,      _______,      _______,      _______,      _______,      _______,      _______,
//   _______,      _______,      _______,      _______,      _______,      _______,
//   _______,      _______,      _______,      _______,      _______,      _______,      _______,
//   _______,      _______,      _______,      _______,      _______,
//
//                                                                         _______,      _______,
//                                                                                       _______,
//                                                           _______,      _______,      _______,
//
//   //  right hand
//   _______,      _______,      _______,      _______,      _______,      _______,      _______,
//   _______,      _______,      _______,      _______,      _______,      _______,      _______,
//                 _______,      _______,      _______,      _______,      _______,      _______,
//   _______,      _______,      _______,      _______,      _______,      _______,      _______,
//                               _______,      _______,      _______,      _______,      _______,
//
//   _______,      _______,
//   _______,
//   _______,      _______,      _______
// ),
};

void unicode_input_start(void) {
    unicode_saved_mods = get_mods();
    clear_mods();

    if (unicode_saved_mods & MOD_BIT(KC_RSHIFT)) {
      tap_code16(LCTL(RSFT(KC_E)));
    } else {
      tap_code16(LCTL(LSFT(KC_E)));
    }

    wait_ms(UNICODE_TYPE_DELAY);
}

void unicode_input_finish(void) {
    tap_code(KC_SPC);
    tap_code(KC_ENT);

    set_mods(unicode_saved_mods);
}

void send_unicode(unsigned int cp) {
  if (get_mods() & MOD_MASK_SHIFT) {
    cp -= 0x20;
  }

  unicode_input_start();
  register_hex(cp);
  unicode_input_finish();
}

void td_send_key_i(qk_tap_dance_state_t *state, void *user_data) {
  if (leading_mode)
    return;

  switch(state->count) {
  case 2:
    send_unicode(UC_ITREMA);
    break;
  default:
    tap_code(KC_I);
    break;
  }
}

void td_send_key_w(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 3:
    send_unicode(UC_ETREMA);
    break;
  case 2:
    send_unicode(UC_EACUTE);
    break;
  default:
    tap_code(KC_W);
    break;
  }
}

void td_send_key_e(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 3:
    send_unicode(UC_ECIRCU);
    break;
  case 2:
    send_unicode(UC_EGRAVE);
    break;
  default:
    tap_code(KC_E);
    break;
  }
}

void td_send_key_a(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 2:
    send_unicode(UC_AGRAVE);
    break;
  default:
    tap_code(KC_A);
    break;
  }
}

void td_send_key_c(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
  case 2:
    send_unicode(UC_CCEDIL);
    break;
  default:
    tap_code(KC_C);
    break;
  }
}

// Tap dancing !
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_A] = ACTION_TAP_DANCE_FN(td_send_key_a),
 [TD_C] = ACTION_TAP_DANCE_FN(td_send_key_c),
 [TD_E] = ACTION_TAP_DANCE_FN(td_send_key_e),
 [TD_I] = ACTION_TAP_DANCE_FN(td_send_key_i),
 [TD_W] = ACTION_TAP_DANCE_FN(td_send_key_w),
};

// Configuration at EEPROM Reset
void eeconfig_init_user(void) {
  // Unicode for Linux
  set_unicode_input_mode(UC_LNX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

LEADER_EXTERNS();

// Switch lights on when using leader mode
void leader_start(void) {
  leading_mode = true;
  ergodox_right_led_1_on();
  ergodox_right_led_2_on();
  ergodox_right_led_3_on();
}

// Switch lights off when  leader mode
void leader_end(void) {
  leading_mode = false;
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

    // Lock PC
    SEQ_ONE_KEY(KC_L) {
      SEND_STRING(SS_LCTL(SS_LALT("l")));
    }

    // Print screen
    SEQ_ONE_KEY(KC_P) {
      tap_code(KC_PSCR);
    }

    // QMK_RESET
    SEQ_TWO_KEYS(KC_Q, KC_R) {
      reset_keyboard();
    }

    // QMK INIT EEPROM
    SEQ_TWO_KEYS(KC_Q, KC_I) {
      eeconfig_init();
    }

    // CAPSLOCK
    SEQ_TWO_KEYS(KC_K, KC_K) {
      tap_code(KC_CAPS);
    }

    // CUSTOM Disable IME
    SEQ_TWO_KEYS(KC_K, KC_J) {
      //tap_code(KC_ZKHK);
      SEND_STRING(SS_LCTL("`"));
    }

    // Katakana
    SEQ_TWO_KEYS(KC_K, KC_U) {
      tap_code(KC_LANG3);
    }

    // Hiragana
    SEQ_TWO_KEYS(KC_K, TD(TD_I)) {
      tap_code(KC_LANG4);
    }

    leader_end();
  }
}


// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_led_all_set(LED_BRIGHTNESS_LO);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
