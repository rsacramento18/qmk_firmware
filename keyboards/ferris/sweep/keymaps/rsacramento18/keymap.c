#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"

const uint16_t PROGMEM qw_combo[] = {PT_Q, PT_W, COMBO_END};
const uint16_t PROGMEM df_combo[] = {MT(MOD_LALT, PT_D), MT(MOD_LCTL, PT_F), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {MT(MOD_LCTL, PT_J), MT(MOD_LALT, PT_K), COMBO_END};
const uint16_t PROGMEM ui_combo[] = {PT_U, PT_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {PT_I, PT_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {MT(MOD_LALT, PT_K), LT(3, PT_L), COMBO_END};

combo_t key_combos[] = {
    COMBO(qw_combo, KC_TAB),    // Q+W → Tab
    COMBO(df_combo, KC_ESC),    // D+F → Esc
    COMBO(jk_combo, KC_ENT),    // J+K → Enter
    COMBO(ui_combo, PT_SLSH),   // U+I → /
    COMBO(io_combo, PT_ACUT),   // I+O → ´
    COMBO(kl_combo, PT_TILD),   // K+L → ~
};

// Hold layer 1 + layer 2 together to reach layer 4 (extra controls).
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 4);
}


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
        MT(MOD_LSFT, PT_A), LT(3, PT_S),        MT(MOD_LALT, PT_D), MT(MOD_LCTL, PT_F), PT_G,                               PT_H,               MT(MOD_LCTL, PT_J), MT(MOD_LALT, PT_K), LT(3, PT_L),        MT(MOD_LSFT, PT_CCED),
        PT_Z,               PT_X,               PT_C,               PT_V,               PT_B,                               PT_N,               PT_M,               PT_COMM,            PT_DOT,             PT_MINS,
                                                                     KC_BSPC,            MO(1),                              MO(2),              KC_SPC
    ),

    /*
     * Symbols
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │F1 │Hom│PgD│PgU│End│       │ ◀ │ ▼ │ ▲ │ ▶ │F12│
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │F2 │F3 │F4 │F5 │F6 │       │F7 │F8 │F9 │F10│F11│
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │   ├───┐   ┌───┤   │
     *               └───┤   │   │   ├───┘
     *                   └───┘   └───┘
     */
    [1] = LAYOUT_split_3x5_2(
        PT_1,               PT_2,               PT_3,               PT_4,               PT_5,                               PT_6,               PT_7,               PT_8,               PT_9,               PT_0,
        KC_F1,              KC_HOME,            KC_PGDN,            KC_PGUP,            KC_END,                             KC_LEFT,            KC_DOWN,            KC_UP,              KC_RGHT,            KC_F12,
        KC_F2,              KC_F3,              KC_F4,              KC_F5,              KC_F6,                              KC_F7,              KC_F8,              KC_F9,              KC_F10,             KC_F11,
                                                                 KC_TRNS,            KC_TRNS,                            KC_TRNS,            KC_TRNS
    ),

    /*
     * Navigation
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ + │ [ │ { │ ( │ & │       │ = │ ) │ } │ ] │ * │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ ! │ | │ \ │ $ │ " │       │ ' │ % │   │   │ ? │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │ < │ > │   │       │   │   │   │   │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │del├───┐   ┌───┤   │
     *               └───┤   │   │   ├───┘
     *                   └───┘   └───┘
     */
    [2] = LAYOUT_split_3x5_2(
        PT_PLUS,            PT_LBRC,            PT_LCBR,            PT_LPRN,            PT_AMPR,                            PT_EQL,             PT_RPRN,            PT_RCBR,            PT_RBRC,            PT_ASTR,
        PT_EXLM,            PT_PIPE,            PT_BSLS,            PT_DLR,             PT_DQUO,                            PT_QUOT,            PT_PERC,            KC_TRNS,            KC_TRNS,            PT_QUES,
        KC_TRNS,            KC_TRNS,            PT_LABK,            PT_RABK,            KC_TRNS,                            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,
                                                                 KC_DEL,             KC_TRNS,                            KC_TRNS,            KC_TRNS
    ),

    /*
     * Tiling
     *
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │⌘1 │⌘2 │⌘3 │⌘4 │⌘5 │       │⌘6 │⌘7 │⌘8 │⌘9 │⌘0 │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │⇧  │   │   │⌘F │⌘Q │       │⌘H │⌘J │⌘K │⌘L │⇧  │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │⌘B │       │   │   │   │   │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │   ├───┐   ┌───┤   │
     *               └───┤   │   │⌘⏎ ├───┘
     *                   └───┘   └───┘
     */
    [3] = LAYOUT_split_3x5_2(
        LGUI(KC_1),         LGUI(KC_2),         LGUI(KC_3),         LGUI(KC_4),         LGUI(KC_5),                         LGUI(KC_6),         LGUI(KC_7),         LGUI(KC_8),         LGUI(KC_9),         LGUI(KC_0),
        KC_LSFT,            KC_TRNS,            KC_TRNS,            LGUI(PT_F),         LGUI(PT_Q),                         LGUI(KC_H),         LGUI(KC_J),         LGUI(KC_K),         LGUI(KC_L),         KC_LSFT,
        KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            LGUI(PT_B),                         KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,
                                                                 KC_TRNS,            KC_TRNS,                            LGUI(KC_ENT),       KC_TRNS
    ),

    /*
     * Extra Controls (hold layer 1 + layer 2)
     *
     * ┌────┬────┬────┬────┬────┐       ┌───┬───┬───┬───┬───┐
     * │ Q  │ W  │ E  │ R  │ T  │       │ Y │ U │ I │ O │ P │
     * ├────┼────┼────┼────┼────┤       ├───┼───┼───┼───┼───┤
     * │ A  │ S  │prev│next│paus│       │Mut│Vo-│Vo+│ L │ ç │
     * ├────┼────┼────┼────┼────┤       ├───┼───┼───┼───┼───┤
     * │ Z  │ X  │ C  │ V  │ B  │       │ N │ M │ , │ . │ - │
     * └────┴────┴────┴────┴────┘       └───┴───┴───┴───┴───┘
     *               ┌───┐           ┌───┐
     *               │Bsp├───┐   ┌───┤Spc│
     *               └───┤ 1 │   │ 2 ├───┘
     *                   └───┘   └───┘
     */
    [4] = LAYOUT_split_3x5_2(
        PT_Q,               PT_W,               PT_E,               PT_R,               PT_T,                               PT_Y,               PT_U,               PT_I,               PT_O,               PT_P,
        MT(MOD_LSFT, PT_A), LT(3, PT_S),        KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,             KC_AUDIO_MUTE,      KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,    LT(3, PT_L),        MT(MOD_LSFT, PT_CCED),
        PT_Z,               PT_X,               PT_C,               PT_V,               PT_B,                               PT_N,               PT_M,               PT_COMM,            PT_DOT,             PT_MINS,
                                                                     KC_BSPC,            MO(1),                              MO(2),              KC_SPC
    )
};
// clang-format on
