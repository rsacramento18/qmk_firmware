#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"

const uint16_t PROGMEM er_combo[] = {PT_E, PT_R, COMBO_END};
const uint16_t PROGMEM df_combo[] = {MT(MOD_LALT, PT_D), MT(MOD_LCTL, PT_F), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {MT(MOD_LCTL, PT_J), MT(MOD_LALT, PT_K), COMBO_END};
const uint16_t PROGMEM ui_combo[] = {PT_U, PT_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {PT_I, PT_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {MT(MOD_LALT, PT_K), LT(4, PT_L), COMBO_END};

combo_t key_combos[] = {
    COMBO(er_combo, KC_TAB),   // E+R → Tab
    COMBO(df_combo, KC_ESC),   // D+F → Esc
    COMBO(jk_combo, KC_ENT),   // J+K → Esc
    COMBO(ui_combo, PT_SLSH),   // U+I → /
    COMBO(io_combo, PT_ACUT),   // I+O → ´
    COMBO(kl_combo, PT_TILD),   // K+L → ~
                                // q
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ç │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ - │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │Bsp├───┐   ┌───┤Spc│
     *               └───┤ 1 │   │ 2 ├───┘
     *                   └───┘   └───┘
     */
    [0] = LAYOUT_split_3x5_2(
        PT_Q,               PT_W,               PT_E,               PT_R,               PT_T,                               PT_Y,               PT_U,               PT_I,               PT_O,               PT_P,
        MT(MOD_LSFT, PT_A), LT(3, PT_S),        MT(MOD_LALT, PT_D), MT(MOD_LCTL, PT_F), PT_G,                               PT_H,               MT(MOD_LCTL, PT_J), MT(MOD_LALT, PT_K), LT(4, PT_L),        MT(MOD_LSFT, PT_CCED),
        PT_Z,               PT_X,               PT_C,               PT_V,               PT_B,                               PT_N,               PT_M,               PT_COMM,            PT_DOT,             PT_MINS,
                                                                    KC_BSPC,            MO(1),                              MO(2),              KC_SPC
    ),

    /*
     * Symbols
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ ! │ # │ ( │ ) │ ? │       │ & │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ @ │ $ │ { │ } │ " │       │ / │ 4 │ 5 │ 6 │ ⇧ │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ \ │ < │ [ │ ] │ % │       │ * │ 1 │ 2 │ 3 │ 0 │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │   ├───┐   ┌───┤   │
     *               └───┤   │   │ = ├───┘
     *                   └───┘   └───┘
     */
    [1] = LAYOUT_split_3x5_2(
        PT_EXLM,             PT_HASH,             PT_LPRN,             PT_RPRN,             PT_QUES,                               PT_AMPR,             PT_7,             PT_8,             PT_9,             PT_PLUS,
        PT_AT,               PT_DLR,              PT_LCBR,             PT_RCBR,             PT_DQUO,                               PT_SLSH,             PT_4,             PT_5,             PT_6,             KC_LSFT,
        PT_BSLS,             PT_LABK,             PT_LBRC,             PT_RBRC,             PT_PERC,                               PT_ASTR,             PT_1,             PT_2,             PT_3,             PT_0,
                                                                       KC_TRNS,             KC_TRNS,                               PT_EQL,              KC_TRNS
    ),

    /*
     * Navigaton
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │       │   │Mut│Vo-│Vo+│   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │Hom│PgD│PgU│End│   │       │ ◀ │ ▼ │ ▲ │ ▶ │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │   │   │   │   │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │   ├───┐   ┌───┤   │
     *               └───┤   │   │   ├───┘
     *                   └───┘   └───┘
     */
    [2] = LAYOUT_split_3x5_2(
        KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,                               KC_TRNS,             KC_AUDIO_MUTE,       KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_TRNS,
        KC_TRNS,             KC_HOME,             KC_PGDN,             KC_PGUP,             KC_END,                                KC_LEFT,             KC_DOWN,             KC_UP,               KC_RGHT,             KC_TRNS,
        KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,                               KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,
                                                                       KC_TRNS,             KC_TRNS,                               KC_TRNS,             KC_TRNS
    ),

    /*
     * Tiling
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │⌘Q │   │   │⌘R │   │       │   │⌘7 │⌘8 │⌘9 │⌘P │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │⇧  │   │   │⌘F │   │       │   │⌘4 │⌘5 │⌘6 │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │⌘B │       │   │⌘1 │⌘2 │⌘3 │ 0 │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │   ├───┐   ┌───┤   │
     *               └───┤   │   │⌘⏎ ├───┘
     *                   └───┘   └───┘
     */
    [3] = LAYOUT_split_3x5_2(
        LGUI(KC_Q),          KC_TRNS,             KC_TRNS,             LGUI(PT_R),          KC_TRNS,                               KC_TRNS,             LGUI(KC_7),             LGUI(KC_8),             LGUI(KC_9),             LGUI(KC_P),
        KC_LSFT,             KC_TRNS,             KC_TRNS,             LGUI(PT_F),          KC_TRNS,                               KC_TRNS,             LGUI(KC_4),             LGUI(KC_5),             LGUI(KC_6),             KC_TRNS,
        KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             LGUI(PT_B),                            KC_TRNS,             LGUI(KC_1),             LGUI(KC_2),             LGUI(KC_3),             KC_0,
                                                                       KC_TRNS,             KC_TRNS,                               LGUI(KC_ENT),        KC_TRNS
    ),

    /*
     * Tiling 2
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │⌘Q │   │⌘K │   │   │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │⌘H │⌘J │⌘L │   │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │⌘B │       │   │   │   │   │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │   ├───┐   ┌───┤   │
     *               └───┤   │   │⌘⏎ ├───┘
     *                   └───┘   └───┘
     */
    [4] = LAYOUT_split_3x5_2(
        LGUI(KC_Q),          KC_TRNS,             LGUI(KC_K),             KC_TRNS,             KC_TRNS,                               KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,
        KC_TRNS,             LGUI(KC_H),          LGUI(KC_J),             LGUI(KC_L),          KC_TRNS,                               KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_LSFT,
        KC_TRNS,             KC_TRNS,             KC_TRNS,                KC_TRNS,             LGUI(PT_B),                            KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,
                                                                          KC_TRNS,             KC_TRNS,                               LGUI(KC_ENT),        KC_TRNS
    )
};
// clang-format on
