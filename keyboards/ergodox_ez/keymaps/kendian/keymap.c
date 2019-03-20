
#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "debug.h"
#include "ergodox_ez.h"
#include "version.h"


#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(MOD_LSFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

/* layers */
enum {
  BASE = 0,
  NUMS,
  FN,
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, /* can always be here */

  FOO,

  STR_A, STR_B, STR_C, STR_D, STR_E, STR_F,
  STR_G, STR_H, STR_I, STR_J, STR_K, STR_L,
  STR_M, STR_N, STR_O, STR_P, STR_Q, STR_R,
  STR_S, STR_T, STR_U, STR_V, STR_W, STR_X,
  STR_Y, STR_Z,
};

/* custom strings */
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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* default layer */
[BASE] = LAYOUT_ergodox(
  /*
  .--------------------------------------------------.
  | GrEsc  |   !  |   @  |   #  |   $  |   %  |  {   |
  |--------+------+------+------+------+------+------|
  |  Tab   |   Q  |   W  |   E  |   R  |   T  |  (   |
  |--------+------+------+------+------+------|      |
  |   _    |   A  |   S  |   D  |   F  |   G  |------|
  |--------+------+------+------+------+------|  [   |
  | Shift  |   Z  |   X  |   C  |   V  |   B  |      |
  '--------+------+------+------+------+-------------'
    | ~L1  | Home |  End | PgUp | PgDn |
    '----------------------------------'
                                       .-------------.
                                       | Ctrl |  Del |
                                .------+------+------|
                                |      |      |  Alt |
                                | Space|BSpace|------|
                                |      |      |  Cmd |
                                '--------------------'
  */

  KC_GESC, KC_EXLM, KC_AT,   KC_HASH,   KC_DLR, KC_PERC, KC_LCBR,
  KC_TAB,  KC_Q,    KC_W,    KC_E,      KC_R,   KC_T,    KC_LPRN,
  KC_UNDS, KC_A,    KC_S,    KC_D,      KC_F,   KC_G,
  OSM(MOD_LSFT), KC_Z, KC_X, KC_C,      KC_V,   KC_B,    KC_LBRC,
  OSL(NUMS), KC_HOME, KC_END,  KC_PGUP,   KC_PGDN,

  OSM(MOD_LCTL), KC_DEL,
  OSM(MOD_LALT),
  KC_SPC, KC_BSPC, OSM(MOD_LGUI),

  /*
  .--------------------------------------------------.
  |  }   |   ^  |   &  |   *  |   -  |   =  |   +    |
  |------+------+------+------+------+------+--------|
  |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
  |      |------+------+------+------+------+--------|
  |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  |  ]   |------+------+------+------+------+--------|
  |      |   N  |   M  |   ,  |   .  |   /  | Shift  |
  '-------------+------+------+------+------+--------'
                | Left | Down |  Up  |Right |  ~L2 |
                '----------------------------------'
  .-------------.
  |  Ins |      |
  |------+------+------.
  |      |      |      |
  |------|BSpace|Enter |
  |      |      |      |
  '--------------------'
  */

  KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,    KC_PLUS,
  KC_RPRN, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
  KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   OSM(MOD_RSFT),
                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,   OSL(FN),
  KC_INS, XXXXXXX,
  XXXXXXX,
  XXXXXXX, KC_BSPC, KC_ENT
),

/* numbers and user defined strings */
[NUMS] = LAYOUT_ergodox(

  /*
  .--------------------------------------------------.
  |        |   1  |   2  |   3  |   4  |   5  |      |
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
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
  _______, STR_Q,   STR_W,   STR_E,   STR_R,   STR_T,   _______,
  _______, STR_A,   STR_S,   STR_D,   STR_F,   STR_G,
  _______, STR_Z,   STR_X,   STR_C,   STR_V,   STR_B,   _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______,

  /*
  .--------------------------------------------------.
  |      |   6  |   7  |   8  |   9  |   0  |        |
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
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
  _______, STR_Y,   STR_U,   STR_I,   STR_O,   STR_P,   KC_F12,
           STR_H,   STR_J,   STR_K,   STR_L,   _______, _______,
  _______, STR_N,   STR_M,   _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* function keys, user defined strings */
[FN] = LAYOUT_ergodox(

  /*
  .--------------------------------------------------.
  |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |
  |--------+------+------+------+------+------+------|
  |        |      |MWhlUp| MsUp |MWhlDn|      |      |
  |--------+------+------+------+------+------|      |
  |        |      |MsLeft|MsDown|MsRght|      |------|
  |--------+------+------+------+------+------|      |
  |        |      | Rclk | Mclk | Lclk |      |      |
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
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______ ,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
  _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, _______,
  _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______,

  /*
  .--------------------------------------------------.
  |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
  |------+------+------+------+------+------+--------|
  |      |      | Mute | Prev | Eject|      |  F12   |
  |      |------+------+------+------+------+--------|
  |------|      |VolUp | Play |      |      | BriUp  |
  |      |------+------+------+------+------+--------|
  |      |      |VolDn | Next |      |      | BriDn  |
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

  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, KC_MUTE, KC_MPLY, KC_EJCT, _______, KC_F12,
           _______, KC_VOLU, KC_MRWD, _______, _______, KC_BRIU,
  _______, _______, KC_VOLD, KC_MFFD, _______, _______, KC_BRID,
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
    case FOO:
      if (record->event.pressed) {
        uint8_t _real_mods = get_mods();
        if ( _real_mods & MODS_SHIFT_MASK) {
          clear_mods();
          register_code(KC_1);
          unregister_code(KC_1);
          set_mods(_real_mods);
        } else {
          clear_mods();
          register_code(KC_2);
          unregister_code(KC_2);
          set_mods(_real_mods);
        }
        return false;
      }
      break;
    case STR_A...STR_Z:
    {
      const char *s = custom_strings[keycode - STR_A];
      if (record->event.pressed) {
        if (*s) {
          send_string(s);
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
