#include "keymap_portuguese.h"
#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   !  |   +  |   [  |   {  |   (  |   &  |                    |   =  |   )  |   }  |   ]  |   *  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   a  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ç  |  ~   |
 * |------+------+------+------+------+------| Ctrl  |    |  Ctrl |------+------+------+------+------+------|
 * |LShift|   z  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ,  |   .  |   -  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |BackSP | /Alt   /       \Enter \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  PT_EXLM,  PT_PLUS, PT_LBRC, PT_LCBR, PT_LPRN, PT_AMPR,                 PT_EQL, PT_RPRN, PT_RCBR, PT_RBRC, PT_ASTR, PT_QUOT,
  KC_TAB,   PT_Q,    PT_W,    PT_E,    PT_R,    PT_T,                    PT_Y,   PT_U,    PT_I,    PT_O,    PT_P,    PT_ACUT,
  KC_ESC,   PT_A,    PT_S,    PT_D, LT(_RAISE,PT_F), PT_G,                    PT_H,   PT_J,    PT_K,    PT_L,    PT_CCED, PT_TILD,
  KC_LSFT,  PT_Z,    PT_X,    PT_C,    PT_V,    PT_B, KC_LCTL,  KC_LCTL,  PT_N,   PT_M,    PT_COMM, PT_DOT,  PT_MINS,  KC_LSFT,
                       PT_BSLS , PT_RABK, KC_BSPC, MO(_LOWER),  KC_ENT,  KC_SPC, PT_SLSH, PT_PERC
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |ALT(1)|ALT(2)|ALT(3)|ALT(4)|ALT(5)|                    |ALT(6)|ALT(7)|ALT(8)|ALT(9)|ALT(0)|ALT(')|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |ALT(q)|ALT(w)|ALT(e)|ALT(r)|ALT(t)|                    |ALT(y)|ALT(u)|ALT(i)|ALT(o)|ALT(p)|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |ALT(a)|ALT(s)|ALT(d)|ALT(f)|ALT(g)|-------.    ,-------|ALT(h)|ALT(j)|ALT(k)|ALT(l)|ALT(ç)|   -  |
 * |------+------+------+------+------+------| Ctrl  |    |  Ctrl |------+------+------+------+------+------|
 * |LShift|ALT(z)|ALT(x)|ALT(c)|ALT(v)|ALT(b)|-------|    |-------|ALT(n)|ALT(m)|ALT(,)|ALT(.)|ALT(-)|   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, LALT(PT_1), LALT(PT_2), LALT(PT_3), LALT(PT_4), LALT(PT_5),                   LALT(PT_6), LALT(PT_7), LALT(PT_8), LALT(PT_9), LALT(PT_0),    LALT(PT_QUOT),
  _______, LALT(PT_Q), LALT(PT_W), LALT(PT_E), LALT(PT_R), LALT(PT_T),                   LALT(PT_Y), LALT(PT_U), LALT(PT_I), LALT(PT_O), LALT(PT_P),    _______,
  _______, LALT(PT_A), LALT(PT_S), LALT(PT_D), LALT(PT_F), LALT(PT_G),                   LALT(PT_H), LALT(PT_J), LALT(PT_K), LALT(PT_L), LALT(PT_CCED), _______,
  _______, LALT(PT_A), LALT(PT_S), LALT(PT_D), LALT(PT_F), LALT(PT_G), _______, _______, LALT(PT_N), LALT(PT_M), LALT(PT_COMM), LALT(PT_DOT), LALT(PT_MINS), _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  XXXXXXX, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

const key_override_t one_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_PLUS, PT_1);
const key_override_t two_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_LBRC, PT_2);
const key_override_t three_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_LCBR, PT_3);
const key_override_t four_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_LPRN, PT_4);
const key_override_t five_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_AMPR, PT_5);
const key_override_t six_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_EQL, PT_6);
const key_override_t seven_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_RPRN, PT_7);
const key_override_t eight_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_RCBR, PT_8);
const key_override_t nine_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_RBRC, PT_9);
const key_override_t zero_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_ASTR, PT_0);
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_SLSH, PT_DQUO);
const key_override_t pound_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_PERC, PT_DLR);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &one_key_override,
    &two_key_override,
    &three_key_override,
    &four_key_override,
    &five_key_override ,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,
    &nine_key_override,
    &zero_key_override,
    NULL
};
