#include QMK_KEYBOARD_H
#include "version.h"

// This keymap is intented to work with US Int keymap

#define BASE 0 // default layer
#define FCNT 1 // function keys

// TODO test a BEAKL Layer

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,
  QUOTE,
  BQUOTE,
  EACUTE,
  EGRAVE,
  AGRAVE,
  CCEDIL
};

// Tap dance key definition
enum {
  TD_W = 0,
  TD_E,
  TD_A,
  TD_C
};

/* Custom names for clarity */
#define TMUX LCTL(KC_B)
#define CT_OR_Z CTL_T(KC_Z)
#define CT_OR_SL CTL_T(KC_SLSH)
#define META KC_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |Reset |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/LALT|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '/RALT |
 * |--------+------+------+------+------+------| Ctl_B|           |EEPROM|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | Grv  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
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
  KC_LSFT,      CT_OR_Z,      KC_X,         TD(TD_C),     KC_V,         KC_B,         _______,
  _______,      BQUOTE,       _______,      KC_LEFT,      KC_RIGHT,

                                                                        META,         KC_INS,
                                                                                      KC_HOME,
                                                          KC_SPC,       KC_BSPC,      KC_END,

  //  right hand
  _______,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_MINS,
  _______,      KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_BSLS,
                KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN,      QUOTE,
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

// /* Keymap x: Blank layer as a template
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

void send_string_without_mods(const char* str) {
  uint8_t mods = get_mods();
  clear_mods();
  send_string(str);
  set_mods(mods);
}

void send_key_eacute(void) {
  send_string_without_mods("'");
  SEND_STRING("e");
}

void td_send_key_eacute(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 2:
      send_key_eacute();
      break;
    default:
      SEND_STRING("w");
      break;
  }
}

void send_key_egrave(void) {
  send_string_without_mods("`");
  SEND_STRING("e");
}

void td_send_key_egrave(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 2:
      send_key_egrave();
      break;
    default:
      SEND_STRING("e");
      break;
  }
}

void send_key_agrave(void) {
  send_string_without_mods("`");
  SEND_STRING("a");
}

void td_send_key_agrave(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 2:
      send_key_agrave();
      break;
    default:
      SEND_STRING("a");
      break;
  }
}

void send_key_ccedil(void) {
  send_string_without_mods(SS_ALGR(","));
  SEND_STRING("c");
}

void td_send_key_ccedil(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 2:
      send_key_ccedil();
      break;
    default:
      SEND_STRING("c");
      break;
  }
}

// Tap dancing !
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_W] = ACTION_TAP_DANCE_FN(td_send_key_eacute),
 [TD_E] = ACTION_TAP_DANCE_FN(td_send_key_egrave),
 [TD_A] = ACTION_TAP_DANCE_FN(td_send_key_agrave),
 [TD_C] = ACTION_TAP_DANCE_FN(td_send_key_ccedil),
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
      case QUOTE:
        SEND_STRING("' ");
        return true;
      case BQUOTE:
        SEND_STRING("` ");
        return true;
      case EACUTE:
        send_key_eacute();
        return true;
      case EGRAVE:
        send_key_egrave();
        return true;
      case AGRAVE:
        send_key_agrave();
        return true;
      case CCEDIL:
        send_key_ccedil();
        return true;
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
  ergodox_right_led_1_on();
  ergodox_right_led_2_on();
  ergodox_right_led_3_on();
}

// Switch lights off when  leader mode
void leader_end(void) {
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

    // QMK_RESET
    SEQ_TWO_KEYS(KC_Q, KC_R) {
      reset_keyboard();
    }

    // QMK INIT EEPROM
    SEQ_TWO_KEYS(KC_Q, KC_I) {
      eeconfig_init();
    }

    // KEYBOARD JP INT1 ROMAJI
    SEQ_TWO_KEYS(KC_K, KC_R) {
      tap_code(KC_RO);
    }

    // KEYBOARD JP INT2 KANA {
    SEQ_TWO_KEYS(KC_K, KC_K) {
      tap_code(KC_KANA);
    }

    // KEYBOARD JP INT3 JYEN {
    SEQ_TWO_KEYS(KC_K, KC_J) {
      tap_code(KC_JYEN);
    }

    // KEYBOARD JP INT4 HENK {
    SEQ_TWO_KEYS(KC_K, KC_H) {
      tap_code(KC_HENK);
    }

    // KEYBOARD JP INT5 mhen {
    SEQ_TWO_KEYS(KC_K, KC_M) {
      tap_code(KC_MHEN);
    }

    // KEYBOARD JP LANG1
    SEQ_TWO_KEYS(KC_K, KC_1) {
      tap_code(KC_LANG1);
    }

    // KEYBOARD JP LANG2
    SEQ_TWO_KEYS(KC_K, KC_2) {
      tap_code(KC_LANG2);
    }

    // KEYBOARD JP LANG3
    SEQ_TWO_KEYS(KC_K, KC_3) {
      tap_code(KC_LANG3);
    }

    // KEYBOARD JP LANG4
    SEQ_TWO_KEYS(KC_K, KC_4) {
      tap_code(KC_LANG4);
    }

    // KEYBOARD JP LANG5
    SEQ_TWO_KEYS(KC_K, KC_5) {
      tap_code(KC_LANG5);
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
