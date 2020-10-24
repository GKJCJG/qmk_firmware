// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "custom_keycodes.c"
#include "greek_characters.c"
#include "russian_characters.c"
#include "exotic_characters.c"
#include "get_foreign_letter.c"
#include "get_accented_character.c"

#define DVORAK 0 // default layer
#define DV_WORK 1
#define QWERTY 2
#define ANKI 3
#define ARABIC_MAIN 4
#define ARABIC_AUX 5
#define GREEK 6
#define RUSSIAN 7
#define SYMB 8 // symbols
#define ACCENTS 9 // Various accents and foreign characters

bool awaiting_letter = false;

uint16_t target_accent = PLACEHOLDER;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  | BckSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   '  |   ,  |   .  |   P  |   Y  |   \  |           |  =   |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------|      |           |MOAcnt|------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | MOSymb |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | LCtl | LAlt | LGui |                                       |  Up  | Down |MOAcnt| RAlt |DFQWERT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | `Grv |       | Home |       |      |
 *                                 | Spce | Enter|------|       |------| Left  |Right |
 *                                 |      |      |  Del |       |  End |       |      |
 *                                 `--------------------'       `---------------------'
 * 
 * 
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DVORAK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,       KC_1,         KC_2,    KC_3,    KC_4,   KC_5,   KC_PGUP,
        KC_TAB,       KC_QUOT,      KC_COMM, KC_DOT,  KC_P,   KC_Y,   KC_BSLASH,
        KC_RSFT,      KC_A,         KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT,      KC_SCLN,      KC_Q,    KC_J,    KC_K,   KC_X,   KC_LBRC,
        KC_BSPC,      KC_GRV,       KC_LCTL, KC_LALT, KC_LGUI,
                                                      KC_LPRN, KC_RPRN,
                                                               KC_GRV,
                                              KC_SPC,KC_ENTER, KC_DEL,
        // right hand
             KC_PGDN,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
             KC_EQL,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,    KC_SLSH,
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,    KC_MINS,
             MO(ACCENTS), KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,    MO(SYMB),
                                  KC_UP,  KC_DOWN,MO(ACCENTS),KC_RALT,DF(QWERTY),
             KC_LCBR, KC_RCBR,
             KC_HOME,
             KC_END,  KC_LEFT, KC_RGHT
    ),

[DV_WORK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,       KC_1,         KC_2,    KC_3,    KC_4,   KC_5,   KC_PGUP,
        KC_TAB,       KC_QUOT,      KC_COMM, KC_DOT,  KC_P,   KC_Y,   KC_BSLASH,
        KC_RSFT,      KC_A,         KC_O,    KC_E,    KC_U,   KC_I,
        KC_LSFT,      KC_SCLN,      KC_Q,    KC_J,    KC_K,   KC_X,   KC_LBRC,
        KC_BSPC,      KC_GRV,       KC_LGUI, KC_LALT, KC_LCTL,
                                                      KC_LPRN, KC_RPRN,
                                                               KC_GRV,
                                              KC_SPC,KC_ENTER, KC_DEL,
        // right hand
             KC_PGDN,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
             KC_EQL,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,    KC_SLSH,
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,    KC_MINS,
             MO(ACCENTS), KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,    MO(SYMB),
                                  KC_UP,  KC_DOWN,MO(ACCENTS),KC_RALT,DF(DVORAK),
             KC_LCBR, KC_RCBR,
             KC_HOME,
             KC_END,  KC_LEFT, KC_RGHT
    ),


/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   \  |           |  =   |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BckSpc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |MOSymbol|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |MOSymb|      | LCtl | LAlt | LGui |                                       |  Up  | Down | RAlt |MOAcce|DFDVOR|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |   `  |       | Home |       |      |
 *                                 | Spce | Enter|------|       |------| Left  |Right |
 *                                 |      |      |  Del |       |  End |       |      |
 *                                 `--------------------'       `---------------------'
 * 
 * 
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWERTY] = LAYOUT_ergodox(  // layer 3 : Optional Default
        // left hand
        KC_ESC,       KC_1,         KC_2,    KC_3,    KC_4,   KC_5,   KC_PGUP,
        KC_TAB,       KC_Q,         KC_W,    KC_E,    KC_R,   KC_T,   KC_BSLASH,
        KC_BSPC,      KC_A,         KC_S,    KC_D,    KC_F,   KC_G,
        KC_LSFT,      KC_Z,         KC_X,    KC_C,    KC_V,   KC_B,   KC_LBRC,
        MO(SYMB),     KC_GRV,       KC_LCTL, KC_LALT, KC_LGUI,
                                              KC_LPRN, KC_RPRN,
                                                               KC_GRV,
                                              KC_SPC,KC_ENTER, KC_DEL,
        // right hand
             KC_PGDN,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS,
             KC_EQL,      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_RBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,
             MO(ACCENTS), KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, MO(SYMB),
                                  KC_UP,  KC_DOWN,MO(ACCENTS),KC_RALT,DF(DVORAK),
             KC_LCBR, KC_RCBR,
             KC_HOME,
             KC_END,  KC_LEFT, KC_RGHT
    ),

[ANKI] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_E,    KC_TRNS,    KC_Y,      KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,       KC_TRNS,                          KC_D,    KC_ENT,  KC_T,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, G(KC_Z), KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(ANKI),

                                                    KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                             KC_TRNS,     KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_ENT
),

[ARABIC_MAIN] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, S(KC_H), KC_TRNS, KC_U,    KC_RBRC,    KC_D,      KC_TRNS,     KC_TRNS,  KC_T,    KC_Y,    KC_E,    KC_N,    KC_G,    KC_TRNS,
  KC_TRNS, KC_H,    S(KC_V), S(KC_D), S(KC_C),    S(KC_N),                          KC_V,    KC_I,    KC_J,    KC_K,    KC_S,    KC_TRNS,
  KC_TRNS, S(KC_B), KC_R,    KC_LBRC, KC_SCLN,    KC_O,      KC_TRNS,     KC_TRNS,  KC_F,    KC_L,    KC_M,    S(KC_M), KC_B,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                               MO(ARABIC_AUX), MO(ACCENTS),KC_UP,  KC_DOWN, TG(ARABIC_MAIN),

                                                    KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                             KC_TRNS,     KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_ENT
),

[ARABIC_AUX] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, S(KC_W), KC_TRNS, KC_TRNS, S(KC_Y),    S(KC_R),   KC_TRNS,     KC_TRNS,  KC_Z,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, S(KC_Q), S(KC_U), S(KC_I), S(KC_T),    S(KC_E),                          KC_Q,    KC_P,    KC_X,    KC_TRNS, KC_W,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_C,    KC_TRNS, KC_TRNS, KC_TRNS, KC_A,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                    KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                             KC_TRNS,     KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_ENT
),

[GREEK] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GK_P,    GK_TH,   KC_TRNS,     KC_TRNS,  GK_PH,   GK_G,    GK_KS,   GK_R,    GK_L,    KC_TRNS,
  KC_TRNS, GK_A,    GK_O,    GK_E,    GK_Y,    GK_I,                           GK_D,    GK_H,    GK_T,    GK_N,    GK_S,    KC_TRNS,
  KC_TRNS, KC_TRNS, GK_OO,   GK_PS,   GK_K,    GK_KH,   GKJ_IOTA,    GKJ_TREMA,GK_B,    GK_M,    GK_W,    GK_SF,   GK_Z,    KC_TRNS,
  GK_HH,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GREEK),

                                              GKJ_ACUTE,GKJ_GRAVE,   GKJ_SMTH, GKJ_ROUGH,
                                                        GKJ_MCRN,    GKJ_CFLX,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

[RUSSIAN] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, R_YA,    KC_TRNS, R_E,     R_YU,    KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, R_P,     R_Y,     KC_TRNS,     KC_TRNS,  R_F,     R_G,     R_C,     R_R,     R_L,     KC_TRNS,
  KC_TRNS, R_A,     R_O,     R_JE,    R_U,     R_I,                            R_D,     R_H,     R_T,     R_N,     R_S,     KC_TRNS,
  KC_TRNS, KC_TRNS, R_SHCH,  R_SO,    R_K,     R_CH,    R_HA,        KC_TRNS,   R_B,     R_M,     R_SH,    R_V,     R_Z,     KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(RUSSIAN),

                                               R_IA,    R_IE,        R_EN,    R_ON,
                                                        R_IEN,       R_ION,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   -  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   =  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   <  |   >  |                                       |      |      |   0  |   .  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+-------.
 *                                 |      |      |      |       |      |      |       |
 *                                 |      |      |------|       |------|KC_INS|KC_PENT|
 *                                 |      |      |      |       |      |      |       |
 *                                 `--------------------'       `---------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_LT,KC_GT,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_MINS, KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_EQL,  KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_0,    KC_DOT,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_INS,  KC_PENT
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |TGANKI|TGRUSS| TGGREEK|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  BAR | OGNK | DOT  |      |      |      |           |      | UBLW |GRAVE | CFLX | RING | LBAR | ACUTE  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ASH | OBAR |      |  UE  | IDOT |------|           |------|  ETH | HBAR | THRN |TILDE |  SZ  | TREMA  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | OKINA|  OE  |      |      |  BRV |      |           |      | BBAR |      |      |HACEK | SMVL |  MCRN  |
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
[ACCENTS] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, GKJ_BAR,   GKJ_OGNK,GKJ_DOT, KC_TRNS, KC_TRNS, GKJ_BAR,
       KC_TRNS, GKJ_ASH,   GKJ_OBAR,KC_TRNS, GKJ_UE,  GKJ_IDOT,
       KC_TRNS, GKJ_OKINA, GKJ_OE,  KC_TRNS, KC_TRNS, GKJ_BRV, KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS, GKJ_CDLA,GKJ_RBLW,
                                           GKJ_IOTA,UC_M_LN,
                                                    UC_M_WI,
                                  GKJ_SMTH,GKJ_ROUGH,UC_M_MA,
    // right hand
       KC_TRNS,  KC_TRNS, TG(ARABIC_MAIN),  DF(DV_WORK), TG(ANKI), TG(RUSSIAN), TG(GREEK),
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
    char * to_send;
    if (awaiting_letter) {
      to_send = get_accented_character(keycode, target_accent, !!(get_mods() & MOD_MASK_SHIFT));
      if (strcmp(to_send, "") != 0) {
        send_unicode_string(to_send);
        return false;
      }
    }
    if (keycode > GKJ_START && keycode < R_END) {
      if (get_mods() & MOD_MASK_SHIFT) {
        to_send = get_foreign_letter(keycode + 1);
        send_unicode_string(to_send);
      } else {
        to_send = get_foreign_letter(keycode);
        send_unicode_string(to_send);
      }
    }
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!(record->event.pressed) && (keycode < QK_MOMENTARY || keycode > QK_MOMENTARY_MAX)) { // Will fire after the release of the character after the accent is triggered.
    if (awaiting_letter) {
      target_accent = PLACEHOLDER;
      awaiting_letter = false;
    } else if (keycode > ACC_START && keycode < ACC_END) {
      target_accent = keycode;
      awaiting_letter = true;
    } 
  }
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case ANKI:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case ARABIC_MAIN:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case ARABIC_AUX:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case GREEK:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case RUSSIAN:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case SYMB:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case ACCENTS:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
