// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

bool awaiting_letter = false;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  GKJ_ACUTE, // /
  GKJ_GRAVE, // g
  GKJ_CFLX, // c
  GKJ_MCRN, // RShft
  GKJ_TREMA, // -
  GKJ_BAR, // '
  GKJ_BRV, // x
  GKJ_HACEK, // v
  GKJ_TILDE, // n
  GKJ_DOT, // .
  GKJ_RING, // r
  GKJ_RBLW, // ->
  GKJ_SMVL, // z
  GKJ_UBLW, // y
  GKJ_CDLA, // <-
  GKJ_OGNK, // ,
  GKJ_SMTH, // LTHUMB
  GKJ_ROUGH, // LTHUMB
  GKJ_IOTA, // LTHUMB

  GKJ_ASH, // a
  GKJ_OE, // q
  GKJ_OBAR, // o
  GKJ_ETH, // d
  GKJ_THRN, // t
  GKJ_SZ, // s
  GKJ_LBAR, // l
  GKJ_HBAR, // h
  GKJ_BBAR, // b
  GKJ_IDOT, // i
};

uint16_t char_to_send = PLACEHOLDER;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  | BckSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   '  |   ,  |   .  |   P  |   Y  |   \  |           |  =   |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BckSpc |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------|   [  |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |TTSymb|  Grv | LCtl | LAlt | LGui |                                       |  Up  | Down | RAlt |MOMdia|TTSymb|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   (  |   )  |       |   {  |    }   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |      |        |      |
 *                                 | LEFT | RIGHT|------|       |------|  Enter | Spce |
 *                                 |      |      | End  |       |  Del |        |      |
 *                                 `--------------------'       `----------------------'
 * 
 * 
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,       KC_1,         KC_2,    KC_3,    KC_4,   KC_5,   KC_PGUP,
        KC_TAB,       KC_QUOT,      KC_COMM, KC_DOT,  KC_P,   KC_Y,   KC_BSLASH,
        KC_BSPC,      KC_A,         KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT,      KC_SCLN,      KC_Q,    KC_J,    KC_K,   KC_X,   KC_LBRC,
        TT(SYMB),     KC_GRV,       KC_LCTL, KC_LALT, KC_LGUI,
                                              LSFT(KC_9),   LSFT(KC_0),
                                                            KC_HOME,
                                               KC_LEFT,KC_RGHT,KC_END,
        // right hand
             KC_PGDN,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
             KC_EQL,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,    KC_SLSH,
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,    KC_MINS,
             KC_RBRC     ,KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,    KC_RSFT,
                                  KC_UP,  KC_DOWN,MO(MDIA),KC_RALT,TT(SYMB),
             LSFT(KC_LBRC),LSFT(KC_RBRC),
             KC_GRV,
             KC_DEL,KC_ENTER, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  BAR | OGNK | DOT  |      |      |      |           |      | UBLW |GRAVE | CFLX | RING | LBAR | ACUTE  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ASH | OBAR |      |      | IDOT |------|           |------|  ETH | HBAR | THRN |TILDE |  SZ  | TREMA  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  OE  |      |      |  BRV |      |           |      | BBAR |      |      |HACEK | SMVL |  MCRN  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | CDLA | RBLW |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,-------------.
 *                                        |IOTATE|UC_M_LN|       |      |      |
 *                                 ,------|------|-------|       |------+------+------.
 *                                 |      |      |UC_M_WI|       |      |      |      |
 *                                 |SMOOTH|ROUGH |-------|       |------|      |      |
 *                                 |      |      |UC_M_MA|       |      |      |      |
 *                                 `---------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, GKJ_BAR, GKJ_OGNK,GKJ_DOT,KC_TRNS, KC_TRNS,  GKJ_BAR,
       KC_TRNS, GKJ_ASH, GKJ_OBAR,KC_TRNS, KC_TRNS, GKJ_IDOT,
       KC_TRNS, KC_TRNS, GKJ_OE,  KC_TRNS, KC_TRNS, GKJ_BRV, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, GKJ_CDLA, GKJ_RBLW,
                                           GKJ_IOTA,UC_M_LN,
                                                    UC_M_WI,
                                  GKJ_SMTH,GKJ_ROUGH,UC_M_MA,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  GKJ_UBLW,GKJ_GRAVE,GKJ_CFLX,GKJ_RING, GKJ_LBAR,GKJ_ACUTE,
                 GKJ_ETH, GKJ_HBAR, GKJ_THRN,GKJ_TILDE,GKJ_SZ,  GKJ_TREMA,
       KC_TRNS,  GKJ_BBAR,KC_TRNS,  KC_TRNS, GKJ_HACEK,GKJ_SMVL,GKJ_MCRN,
                          KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_MAC);
};

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_MAC);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (awaiting_letter && keycode == KC_SPC) {
      post_process_record_user(keycode, record);
      return false;
    }
    if (keycode > GKJ_IOTA && keycode <= GKJ_IDOT) {
      if (get_mods() & MOD_MASK_SHIFT) {
        switch (keycode) {
          case GKJ_ASH:
            send_unicode_string("Æ"); // æ
            break;
          case GKJ_OE:
            send_unicode_string("Œ"); // œ
            break;
          case GKJ_OBAR:
            send_unicode_string("Ø"); // ø
            break;
          case GKJ_ETH:
            send_unicode_string("Ð"); // ð
            break;
          case GKJ_THRN:
            send_unicode_string("Þ"); // þ
            break;
          case GKJ_SZ:
            send_unicode_string("ẞ"); // ß
            break;
          case GKJ_LBAR:
            send_unicode_string("Ł"); // ł
            break;
          case GKJ_HBAR:
            send_unicode_string("Ħ"); // ħ
            break;
          case GKJ_BBAR:
            send_unicode_string("Ƀ"); // ƀ
            break;
          case GKJ_IDOT:
            send_unicode_string("İ"); // ı
            break;
        } 
      } else {
        switch (keycode) {
          case GKJ_ASH:
            send_unicode_string("æ"); // Æ
            break;
          case GKJ_OE:
            send_unicode_string("œ"); // Œ
            break;
          case GKJ_OBAR:
            send_unicode_string("ø"); // Ø
            break;
          case GKJ_ETH:
            send_unicode_string("ð"); // Ð
            break;
          case GKJ_THRN:
            send_unicode_string("þ"); // Þ
            break;
          case GKJ_SZ:
            send_unicode_string("ß"); // ẞ
            break;
          case GKJ_LBAR:
            send_unicode_string("ł"); // Ł
            break;
          case GKJ_HBAR:
            send_unicode_string("ħ"); // Ħ
            break;
          case GKJ_BBAR:
            send_unicode_string("ƀ"); // Ƀ
            break;
          case GKJ_IDOT:
            send_unicode_string("ı"); // İ
            break;
        }
      }
    }
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (awaiting_letter) {
      switch (char_to_send) {
        case GKJ_ACUTE:
          send_unicode_string("́");
          break;
        case GKJ_GRAVE:
          send_unicode_string("̀");
          break;
        case GKJ_CFLX:
          send_unicode_string("̂");
          break;
        case GKJ_MCRN:
          send_unicode_string("̄");
          break;
        case GKJ_TREMA:
          send_unicode_string("̈");
          break;
        case GKJ_BAR:
          send_unicode_string("̍");
          break;
        case GKJ_HACEK:
          send_unicode_string("̌");
          break;
        case GKJ_DOT:
          send_unicode_string("̇");
          break;
        case GKJ_RING:
          send_unicode_string("̊");
          break;
        case GKJ_RBLW:
          send_unicode_string("̥");
          break;
        case GKJ_SMVL:
          send_unicode_string("̯");
          break;
        case GKJ_UBLW:
          send_unicode_string("̮");
          break;
        case GKJ_CDLA:
          send_unicode_string("̧");
          break;
        case GKJ_OGNK:
          send_unicode_string("̨");
          break;
        case GKJ_BRV:
          send_unicode_string("̆");
          break;
        case GKJ_SMTH:
          send_unicode_string("̓");
          break;
        case GKJ_ROUGH:
          send_unicode_string("̔");
          break;
        case GKJ_IOTA:
          send_unicode_string("ͅ");
          break;
      }
      char_to_send = PLACEHOLDER;
      awaiting_letter = false;
    } else if (keycode > PLACEHOLDER && keycode <= GKJ_IOTA) {
      char_to_send = keycode;
      awaiting_letter = true;
    } 
  }
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }
};
