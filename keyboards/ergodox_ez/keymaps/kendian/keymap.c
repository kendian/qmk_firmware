
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "debug.h"
#include "ergodox_ez.h"
#include "version.h"

/*
Adapted from
https://github.com/qmk/qmk_firmware/tree/master/layouts/community/ergodox/qwerty_code_friendly

Base layer (0) is close to typical QWERTY

Only symbols are used on the top row (not numbers); the symbol layer's (1) number-pad layout can be used for numbers. Symbols match regular QWERTY. except for '()' which are grouped with other brackets. In their place -/= keys are placed, which almost matches a regular layout.

Brackets are placed symmetrically along the center edges, if using keys from both sides is inconvenient - the symbol layer (1) has macros at the same left key locations to type matching pairs.

The space-bar on the lower-left looks like it's in an obscure location, however using the larger thumb cluster ended up being more of a reach while typing.

Arrow keys follow VIM convention.
*/

/* custom strings for each character (layer 3) */
static char *custom_strings[26] = {
    /* a */    "",
    /* b */    "baldwin@bigml.com",
    /* c */    "",
    /* d */    "",
    /* e */    "kenneth.baldwin@gmail.com",
    /* f */    "",
    /* g */    "",
    /* h */    "Hello World",
    /* i */    "",
    /* j */    "",
    /* k */    "",
    /* l */    "",
    /* m */    "",
    /* n */    "",
    /* o */    "",
    /* p */    "",
    /* q */    "",
    /* r */    "",
    /* s */    "",
    /* t */    "",
    /* u */    "",
    /* v */    "",
    /* w */    "",
    /* x */    "",
    /* y */    "",
    /* z */    "",
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, /* can always be here */

  IN_CBR, IN_PRN, IN_BRC,
  STR_A, STR_B, STR_C, STR_D, STR_E, STR_F,
  STR_G, STR_H, STR_I, STR_J, STR_K, STR_L,
  STR_M, STR_N, STR_O, STR_P, STR_Q, STR_R,
  STR_S, STR_T, STR_U, STR_V, STR_W, STR_X,
  STR_Y, STR_Z,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* default layer */
[0] = LAYOUT_ergodox(
  /*
  .--------------------------------------------------.
  | Grave  |   1  |   2  |   3  |   4  |   5  |  -   |
  |--------+------+------+------+------+------+------|
  |  Tab   |   Q  |   W  |   E  |   R  |   T  |  (   |
  |--------+------+------+------+------+------|      |
  |  Esc   |   A  |   S  |   D  |   F  |   G  |------|
  |--------+------+------+------+------+------|  [   |
  | Shift  |   Z  |   X  |   C  |   V  |   B  |      |
  '--------+------+------+------+------+-------------'
    |      | Home |  End | PgUp | PgDn |
    '----------------------------------'
                                       .-------------.
                                       | Ctrl |  Del |
                                .------+------+------|
                                |      |      |  Alt |
                                | Space|BSpace|------|
                                |      |      |  Cmd |
                                '--------------------'
  */

  /* KC_NLCK */

  KC_GRV,  KC_1,    KC_2,    KC_3,      KC_4,   KC_5,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,   KC_T,    KC_LPRN,
  KC_ESC,  KC_A,    KC_S,    KC_D,      KC_F,   KC_G,
  OSM(MOD_LSFT), KC_Z, KC_X, KC_C,      KC_V,   KC_B,    KC_LBRC,
  XXXXXXX, KC_HOME, KC_END,  KC_PGUP,   KC_PGDN,

  OSM(MOD_LCTL), KC_DEL,
  OSM(MOD_LALT),
  KC_SPC, KC_BSPC, OSM(MOD_LGUI),

  /*
  .--------------------------------------------------.
  |  =   |   6  |   7  |   8  |   9  |   0  | BSpace |
  |------+------+------+------+------+------+--------|
  |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
  |      |------+------+------+------+------+--------|
  |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  |  ]   |------+------+------+------+------+--------|
  |      |   N  |   M  |   ,  |   .  |   /  | Shift  |
  '-------------+------+------+------+------+--------'
                | Left | Down |  Up  |Right |      |
                '----------------------------------'
  .-------------.
  |  Ins | ~L3  |
  |------+------+------.
  | ~L2  |      |      |
  |------|BSpace|Enter |
  | ~L1  |      |      |
  '--------------------'
  */

  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPC,
  KC_RPRN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   OSM(MOD_RSFT),
                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,   XXXXXXX,
  KC_INS, TT(3),
  TT(2),
  TT(1), KC_BSPC, KC_ENT
),

/* function keys, keypad, and brace sequences */
[1] = LAYOUT_ergodox(

  /*
  .--------------------------------------------------.
  |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
  |--------+------+------+------+------+------+------|
  |        |      |      |      |  {}  |      |      |
  |--------+------+------+------+------+------|      |
  |        |      |      |      |  ()  |      |------|
  |--------+------+------+------+------+------|      |
  |        |      |      |      |  []  |      |      |
  '--------+------+------+------+------+-------------'
    |      |      |      |      |      |
    '----------------------------------'
                                       .-------------.
                                       |      |      |
                                .------+------+------|
                                |      |      |      |
                                |      |      |------|
                                |      |      |      |
                                '--------------------'
  */
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,
  _______, _______, _______, _______, IN_CBR, _______, _______,
  _______, _______, _______, _______, IN_PRN, _______,
  _______, _______, _______, _______, IN_BRC, _______, _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______,

  /*
  .--------------------------------------------------.
  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
  |------+------+------+------+------+------+--------|
  |      |      |   7  |   8  |   9  |   +  |        |
  |      |------+------+------+------+------+--------|
  |------|      |   4  |   5  |   6  |   -  |        |
  |      |------+------+------+------+------+--------|
  |      |      |   1  |   2  |   3  |   *  |        |
  '-------------+------+------+------+------+--------'
                |   0  |   .  |   =  |   /  |      |
                '----------------------------------'
  .-------------.
  |      |      |
  |------+------+------.
  |      |      |      |
  |------|      |      |
  |      |      |      |
  '--------------------'

  */
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
  _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
           _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                    KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* mouse and media keys */
[2] = LAYOUT_ergodox(
  /*
  .--------------------------------------------------.
  |        |      |      |      |      |      |      |
  |--------+------+------+------+------+------+------|
  |        |      |      |      |      |      |      |
  |--------+------+------+------+------+------|      |
  |        |      |      |      |      |      |------|
  |--------+------+------+------+------+------|      |
  |        |      |      |      |      |      |      |
  '--------+------+------+------+------+-------------'
    |      |      |      |      |      |
    '----------------------------------'
                                       .-------------.
                                       |      |      |
                                .------+------+------|
                                |      |      |      |
                                |      |      |------|
                                |      |      |      |
                                '--------------------'
  */
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______,

  /*
  .--------------------------------------------------.
  | Mute | Play |      |      |      |      | Sleep  |
  |------+------+------+------+------+------+--------|
  |VolUp | Prev |MWhlUp| MsUp |MWhlDn|      | Wake   |
  |      |------+------+------+------+------+--------|
  |------| Next |MsLeft|MsDown|MsRght|      | BriUp  |
  |VolDn |------+------+------+------+------+--------|
  |      | Eject| Rclk | Mclk | Lclk |      | BriDn  |
  '-------------+------+------+------+------+--------'
                |      |      |      |      |      |
                '----------------------------------'
  .-------------.
  |      |      |
  |------+------+------.
  |      |      |      |
  |------|      |      |
  |      |      |      |
  '--------------------'
  */
  KC_MUTE, KC_MPLY, _______, _______, _______, _______, KC_SLEP,
  KC_VOLU, KC_MRWD, KC_WH_U, KC_MS_U, KC_WH_D, _______, KC_WAKE ,
           KC_MFFD, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_BRIU,
  KC_VOLD, KC_EJCT, KC_BTN2, KC_BTN3, KC_BTN1, _______, KC_BRID,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* user defined strings */
[3] = LAYOUT_ergodox(

  /*
  .--------------------------------------------------.
  |        |      |      |      |      |      |      |
  |--------+------+------+------+------+------+------|
  |        |   Q  |   W  |   E  |   R  |   T  |      |
  |--------+------+------+------+------+------|      |
  |        |   A  |   S  |   D  |   F  |   G  |------|
  |--------+------+------+------+------+------|      |
  |        |   Z  |   X  |   C  |   V  |   B  |      |
  '--------+------+------+------+------+-------------'
    |      |      |      |      |      |
    '----------------------------------'
                                       .-------------.
                                       |      |      |
                                .------+------+------|
                                |      |      |      |
                                |      |      |------|
                                |      |      |      |
                                '--------------------'
  */

  _______, _______, _______, _______, _______, _______, _______,
  _______, STR_Q,   STR_W,   STR_E,   STR_R,   STR_T,   _______,
  _______, STR_A,   STR_S,   STR_D,   STR_F,   STR_G,
  _______, STR_Z,   STR_X,   STR_C,   STR_V,   STR_B,   _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______,

  /*
  .--------------------------------------------------.
  |      |      |      |      |      |      |        |
  |------+------+------+------+------+------+--------|
  |      |   Y  |   U  |   I  |   O  |   P  |        |
  |      |------+------+------+------+------+--------|
  |------|   H  |   J  |   K  |   L  |      |        |
  |      |------+------+------+------+------+--------|
  |      |   N  |   M  |      |      |      |        |
  '-------------+------+------+------+------+--------'
                |      |      |      |      |      |
                '----------------------------------'
  .-------------.
  |      |      |
  |------+------+------.
  |      |      |      |
  |------|      |      |
  |      |      |      |
  '--------------------'
  */

  _______, _______, _______, _______, _______, _______, _______,
  _______, STR_Y,   STR_U,   STR_I,   STR_O,   STR_P,   _______,
           STR_H,   STR_J,   STR_K,   STR_L,   _______, _______,
  _______, STR_N,   STR_M,   _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),
};

#define WITHOUT_MODS(...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {;
    case IN_CBR:  /* {} */
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case IN_PRN:  /* () */
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case IN_BRC:  /* [] */
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
        return false;
      }
      break;
    case STR_A...STR_Z:
    {
      const char *s = custom_strings[keycode - STR_A];
      if (record->event.pressed) {
        if (*s) {
          WITHOUT_MODS({
              send_string(s);
            });
        }
        return false;
      }
      break;
    }
  }

  return true;
}


uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_led_all_off();

  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;

};
