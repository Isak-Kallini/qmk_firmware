/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

/*
enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};
*/

enum layers {
    _COLEMAK_DH = 0,
    _COLEMAK_DH_MAC,
    _NAV,
    _SYM,
    _SYM_MAC,
    _FUNCTION,
    _ADJUST,
    _NUM,
};


// Aliases for readability
#define QWERTY      DF(_QWERTY)
#define COLEMAK     DF(_COLEMAK_DH)
#define COLEMAK_MAC DF(_COLEMAK_DH_MAC)
#define DVORAK      DF(_DVORAK)
 
#define SYM       MO(_SYM)
#define NAV       MO(_NAV)
#define FKEYS     MO(_FUNCTION)
#define ADJUST    MO(_ADJUST)
#define MAC_NAV   MO(_NAV_MAC)
#define MAC_SYM   MO(_SYM_MAC)
#define MAC_FKEYS MO(_FUNCTION_MAC)
#define NUM       MO(_NUM)
#define MAC_NUM   MO(_NUM)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, SE_SCLN)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define SE_SECT KC_GRV  // §
#define SE_1    KC_1    // 1
#define SE_2    KC_2    // 2
#define SE_3    KC_3    // 3
#define SE_4    KC_4    // 4
#define SE_5    KC_5    // 5
#define SE_6    KC_6    // 6
#define SE_7    KC_7    // 7
#define SE_8    KC_8    // 8
#define SE_9    KC_9    // 9
#define SE_0    KC_0    // 0
#define SE_PLUS KC_MINS // +
#define SE_ACUT KC_EQL  // ´ (dead)
#define SE_Q    KC_Q    // Q
#define SE_W    KC_W    // W
#define SE_E    KC_E    // E
#define SE_R    KC_R    // R
#define SE_T    KC_T    // T
#define SE_Y    KC_Y    // Y
#define SE_U    KC_U    // U
#define SE_I    KC_I    // I
#define SE_O    KC_O    // O
#define SE_P    KC_P    // P
#define SE_ARNG KC_LBRC // Å
#define SE_DIAE KC_RBRC // ¨ (dead)
#define SE_A    KC_A    // A
#define SE_S    KC_S    // S
#define SE_D    KC_D    // D
#define SE_F    KC_F    // F
#define SE_G    KC_G    // G
#define SE_H    KC_H    // H
#define SE_J    KC_J    // J
#define SE_K    KC_K    // K
#define SE_L    KC_L    // L
#define SE_ODIA KC_SCLN // Ö
#define SE_ADIA KC_QUOT // Ä
#define SE_QUOT KC_NUHS // '
#define SE_LABK KC_NUBS // <
#define SE_Z    KC_Z    // Z
#define SE_X    KC_X    // X
#define SE_C    KC_C    // C
#define SE_V    KC_V    // V
#define SE_B    KC_B    // B
#define SE_N    KC_N    // N
#define SE_M    KC_M    // M
#define SE_COMM KC_COMM // ,
#define SE_DOT  KC_DOT  // .
#define SE_MINS KC_SLSH // -
#define SE_HALF S(SE_SECT) // ½
#define SE_EXLM S(SE_1)    // !
#define SE_DQUO S(SE_2)    // "
#define SE_HASH S(SE_3)    // #
#define SE_CURR S(SE_4)    // ¤
#define SE_PERC S(SE_5)    // %
#define SE_AMPR S(SE_6)    // &
#define SE_SLSH S(SE_7)    // /
#define SE_LPRN S(SE_8)    // (
#define SE_RPRN S(SE_9)    // )
#define SE_EQL  S(SE_0)    // =
#define SE_QUES S(SE_PLUS) // ?
#define SE_GRV  S(SE_ACUT) // ` (dead)
#define SE_CIRC S(SE_DIAE) // ^ (dead)
#define SE_ASTR S(SE_QUOT) // *
#define SE_RABK S(SE_LABK) // >
#define SE_SCLN S(SE_COMM) // ;
#define SE_COLN S(SE_DOT)  // :
#define SE_UNDS S(SE_MINS) // _
#define SE_AT   ALGR(SE_2)    // @
#define SE_PND  ALGR(SE_3)    // £
#define SE_DLR  ALGR(SE_4)    // $
#define SE_EURO ALGR(SE_5)    // €
#define SE_LCBR ALGR(SE_7)    // {
#define SE_LBRC ALGR(SE_8)    // [
#define SE_RBRC ALGR(SE_9)    // ]
#define SE_RCBR ALGR(SE_0)    // }
#define SE_BSLS ALGR(SE_PLUS) // (backslash)
#define SE_TILD ALGR(SE_DIAE) // ~ (dead)
#define SE_PIPE ALGR(SE_LABK) // |
#define SE_MICR ALGR(SE_M)    // µ

#define MAC_SE_SECT KC_GRV  // §
#define MAC_SE_1    KC_1    // 1
#define MAC_SE_2    KC_2    // 2
#define MAC_SE_3    KC_3    // 3
#define MAC_SE_4    KC_4    // 4
#define MAC_SE_5    KC_5    // 5
#define MAC_SE_6    KC_6    // 6
#define MAC_SE_7    KC_7    // 7
#define MAC_SE_8    KC_8    // 8
#define MAC_SE_9    KC_9    // 9
#define MAC_SE_0    KC_0    // 0
#define MAC_SE_PLUS KC_MINS // +
#define MAC_SE_ACUT KC_EQL  // ´ (dead)
#define MAC_SE_Q    KC_Q    // Q
#define MAC_SE_W    KC_W    // W
#define MAC_SE_E    KC_E    // E
#define MAC_SE_R    KC_R    // R
#define MAC_SE_T    KC_T    // T
#define MAC_SE_Y    KC_Y    // Y
#define MAC_SE_U    KC_U    // U
#define MAC_SE_I    KC_I    // I
#define MAC_SE_O    KC_O    // O
#define MAC_SE_P    KC_P    // P
#define MAC_SE_ARNG KC_LBRC // Å
#define MAC_SE_DIAE KC_RBRC // ¨ (dead)
#define MAC_SE_A    KC_A    // A
#define MAC_SE_S    KC_S    // S
#define MAC_SE_D    KC_D    // D
#define MAC_SE_F    KC_F    // F
#define MAC_SE_G    KC_G    // G
#define MAC_SE_H    KC_H    // H
#define MAC_SE_J    KC_J    // J
#define MAC_SE_K    KC_K    // K
#define MAC_SE_L    KC_L    // L
#define MAC_SE_ODIA KC_SCLN // Ö
#define MAC_SE_ADIA KC_QUOT // Ä
#define MAC_SE_QUOT KC_NUHS // '
#define MAC_SE_LABK KC_NUBS // <
#define MAC_SE_Z    KC_Z    // Z
#define MAC_SE_X    KC_X    // X
#define MAC_SE_C    KC_C    // C
#define MAC_SE_V    KC_V    // V
#define MAC_SE_B    KC_B    // B
#define MAC_SE_N    KC_N    // N
#define MAC_SE_M    KC_M    // M
#define MAC_SE_COMM KC_COMM // ,
#define MAC_SE_DOT  KC_DOT  // .
#define MAC_SE_MINS KC_SLSH // -
#define MAC_SE_DEG  S(SE_SECT) // °
#define MAC_SE_EXLM S(SE_1)    // !
#define MAC_SE_DQUO S(SE_2)    // "
#define MAC_SE_HASH S(SE_3)    // #
#define MAC_SE_EURO S(SE_4)    // €
#define MAC_SE_PERC S(SE_5)    // %
#define MAC_SE_AMPR S(SE_6)    // &
#define MAC_SE_SLSH S(SE_7)    // /
#define MAC_SE_LPRN S(SE_8)    // (
#define MAC_SE_RPRN S(SE_9)    // )
#define MAC_SE_EQL  S(SE_0)    // =
#define MAC_SE_QUES S(SE_PLUS) // ?
#define MAC_SE_GRV  S(SE_ACUT) // `
#define MAC_SE_CIRC S(SE_DIAE) // ^ (dead)
#define MAC_SE_ASTR S(SE_QUOT) // *
#define MAC_SE_RABK S(SE_LABK) // >
#define MAC_SE_SCLN S(SE_COMM) // ;
#define MAC_SE_COLN S(SE_DOT)  // :
#define MAC_SE_UNDS S(SE_MINS) // _
#define MAC_SE_PILC A(SE_SECT) // ¶
#define MAC_SE_COPY A(SE_1)    // ©
#define MAC_SE_TM   A(SE_2)    // ™
#define MAC_SE_PND  A(SE_3)    // £
#define MAC_SE_DLR  A(SE_4)    // $
#define MAC_SE_INFN A(SE_5)    // ∞
#define MAC_SE_PIPE A(SE_7)    // |
#define MAC_SE_LBRC A(SE_8)    // [
#define MAC_SE_RBRC A(SE_9)    // ]
#define MAC_SE_AEQL A(SE_0)    // ≈
#define MAC_SE_PLMN A(SE_PLUS) // ±
#define MAC_SE_BULT A(SE_Q)    // •
#define MAC_SE_OMEG A(SE_W)    // Ω
#define MAC_SE_EACU A(SE_E)    // É
#define MAC_SE_REGD A(SE_R)    // ®
#define MAC_SE_DAGG A(SE_T)    // †
#define MAC_SE_MICR A(SE_Y)    // µ
#define MAC_SE_UDIA A(SE_U)    // Ü
#define MAC_SE_DLSI A(SE_I)    // ı
#define MAC_SE_OE   A(SE_O)    // Œ
#define MAC_SE_PI   A(SE_P)    // π
#define MAC_SE_DOTA A(SE_ARNG) // ˙
#define MAC_SE_TILD A(SE_DIAE) // ~ (dead)
#define MAC_SE_APPL A(SE_A)    //  (Apple logo)
#define MAC_SE_SS   A(SE_S)    // ß
#define MAC_SE_PDIF A(SE_D)    // ∂
#define MAC_SE_FHK  A(SE_F)    // ƒ
#define MAC_SE_CEDL A(SE_G)    // ¸
#define MAC_SE_OGON A(SE_H)    // ˛
#define MAC_SE_SQRT A(SE_J)    // √
#define MAC_SE_FORD A(SE_K)    // ª
#define MAC_SE_FI   A(SE_L)    // ﬁ
#define MAC_SE_OSTR A(SE_ODIA) // Ø
#define MAC_SE_AE   A(SE_ADIA) // Æ
#define MAC_SE_AT   A(SE_QUOT) // @
#define MAC_SE_LTEQ A(SE_LABK) // ≤
#define MAC_SE_DIV  A(SE_Z)    // ÷
#define MAC_SE_CCED A(SE_C)    // Ç
#define MAC_SE_LSAQ A(SE_V)    // ‹
#define MAC_SE_RSAQ A(SE_B)    // ›
#define MAC_SE_LSQU A(SE_N)    // ‘
#define MAC_SE_RSQU A(SE_M)    // ’
#define MAC_SE_SLQU A(SE_COMM) // ‚
#define MAC_SE_ELLP A(SE_DOT)  // …
#define MAC_SE_NDSH A(SE_MINS) // –
#define MAC_SE_IEXL S(A(SE_1))    // ¡
#define MAC_SE_YEN  S(A(SE_3))    // ¥
#define MAC_SE_CENT S(A(SE_4))    // ¢
#define MAC_SE_PERM S(A(SE_5))    // ‰
#define MAC_SE_BSLS S(A(SE_7))    // (backslash)
#define MAC_SE_LCBR S(A(SE_8))    // {
#define MAC_SE_RCBR S(A(SE_9))    // }
#define MAC_SE_NEQL S(A(SE_0))    // ≠
#define MAC_SE_IQUE S(A(SE_PLUS)) // ¿
#define MAC_SE_DACU S(A(SE_W))    // ˝
#define MAC_SE_DDAG S(A(SE_T))    // ‡
#define MAC_SE_STIL S(A(SE_Y))    // ˜
#define MAC_SE_DCIR S(A(SE_I))    // ˆ
#define MAC_SE_NARP S(A(SE_P))    // ∏
#define MAC_SE_RNGA S(A(SE_ARNG)) // ˚
#define MAC_SE_LOZN S(A(SE_A))    // ◊
#define MAC_SE_NARS S(A(SE_S))    // ∑
#define MAC_SE_INCR S(A(SE_D))    // ∆
#define MAC_SE_INTG S(A(SE_F))    // ∫
#define MAC_SE_MACR S(A(SE_G))    // ¯
#define MAC_SE_BREV S(A(SE_H))    // ˘
#define MAC_SE_NOT  S(A(SE_J))    // ¬
#define MAC_SE_MORD S(A(SE_K))    // º
#define MAC_SE_FL   S(A(SE_L))    // ﬂ
#define MAC_SE_GTEQ S(A(SE_LABK)) // ≥
#define MAC_SE_FRSL S(A(SE_Z))    // ⁄
#define MAC_SE_CARN S(A(SE_X))    // ˇ
#define MAC_SE_LDAQ S(A(SE_V))    // «
#define MAC_SE_RDAQ S(A(SE_B))    // »
#define MAC_SE_LDQU S(A(SE_N))    // “
#define MAC_SE_RDQU S(A(SE_M))    // ”
#define MAC_SE_DLQU S(A(SE_COMM)) // „
#define MAC_SE_MDDT S(A(SE_DOT))  // ·
#define MAC_SE_MDSH S(A(SE_MINS)) // —

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   Ä  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  LAlt  |   A  |  R   |S/SHFT|  T   |   G  |                              |   M  |  N   |E/SHFT|   I  |   O  |   Ö    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  LCTRL |   Z  |   X  |   C  |   D  |   V  | tab  |F-keys|  |CapsLk|RAlt  |   K  |   H  | ,  < | . >  | /  ? | RCTRL  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI |      | Space| Sym  |  | Nav  |remove|      | NUM  | Menu |
 *                        |      |      | Enter|      |      |  |      |      |  del |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_ESC  , SE_Q ,  SE_W   ,  SE_F  ,               SE_P ,   SE_B ,                                     SE_J,   SE_L ,  SE_U ,   SE_Y , SE_ADIA, SE_ARNG,
     KC_LALT , SE_A ,   SE_R   ,  MT(MOD_LSFT,SE_S)  ,  SE_T ,   SE_G ,                                     SE_M,   SE_N ,  MT(MOD_RSFT,SE_E) , SE_I ,  SE_O , SE_ODIA,
     KC_LCTL , SE_Z ,  SE_X   ,  SE_C  ,   SE_D ,   SE_V , KC_TAB,FKEYS,               KC_CAPS  , KC_RALT, SE_K,   SE_H ,SE_COMM, SE_DOT ,SE_MINS, KC_RCTL,
                                 ADJUST, KC_LGUI, KC_ENT, KC_SPC , SYM   ,               NAV    , KC_BSPC ,KC_DEL, NUM, KC_APP
    ),
    /*
  * Base Layer: Colemak DH MAC
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   Ä  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  LAlt  |   A  |  R   |S/SHFT|  T   |   G  |                              |   M  |  N   |E/SHFT|   I  |   O  |   Ö    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  LCTRL |   Z  |   X  |   C  |   D  |   V  | tab  |F-keys|  |CapsLk|RAlt  |   K  |   H  | ,  < | . >  | /  ? | RCTRL  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI |      | Space| Sym  |  | Nav  |remove|      | NUM  | Menu |
 *                        |      |      | Enter|      |      |  |      |      |  del |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH_MAC] = LAYOUT(
     KC_ESC  , MAC_SE_Q ,  MAC_SE_W   ,  MAC_SE_F  ,               MAC_SE_P ,   MAC_SE_B ,                                     MAC_SE_J,   MAC_SE_L ,  MAC_SE_U ,   MAC_SE_Y , MAC_SE_ADIA, MAC_SE_ARNG,
     KC_LALT , MAC_SE_A ,   MAC_SE_R   ,  MT(MOD_LSFT,MAC_SE_S)  ,  MAC_SE_T ,   MAC_SE_G ,                                     MAC_SE_M,   MAC_SE_N ,  MT(MOD_RSFT,MAC_SE_E) , MAC_SE_I ,  MAC_SE_O , MAC_SE_ODIA,
     KC_LSFT , MAC_SE_Z ,  MAC_SE_X   ,  MAC_SE_C  ,   MAC_SE_D ,   MAC_SE_V , KC_TAB,FKEYS,               KC_CAPS  , KC_RALT, MAC_SE_K,   MAC_SE_H ,MAC_SE_COMM, MAC_SE_DOT ,MAC_SE_MINS, KC_RCTL,
                                 ADJUST, KC_LGUI, KC_ENT, KC_SPC , MAC_SYM   ,               NAV    , KC_BSPC ,KC_DEL, NUM, KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Shift| Ctrl |      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LSFT,KC_LCTL , _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),



 /*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  §   |  @   |  #   |  $   |  %   |                              |   &  |  /   |  \   |  ~   |  ?   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  -   |  [   |  (   |  {   |  !   |                              |   =  |  }   |  )   |   ]  |  +   |    ^   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  <   |  >   |  _   |  '   |  |   |      |      |  |      |      |   `  |  "   |  ;   |  :   |  *   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______ ,   SE_SECT ,   SE_AT ,   SE_HASH ,   SE_DLR ,   SE_PERC ,                                       SE_AMPR ,   SE_SLSH ,   SE_BSLS ,   SE_TILD ,  SE_QUES , _______ ,
     _______ , SE_MINS,  SE_LBRC , SE_LPRN,  SE_LCBR, SE_EXLM,                                     SE_EQL, SE_RCBR, SE_RPRN, SE_RBRC, SE_PLUS,  SE_CIRC,
     _______ , SE_LABK, SE_RABK, SE_UNDS, SE_QUOT, SE_PIPE, _______, _______, _______, _______, SE_GRV, SE_DQUO, SE_SCLN,  SE_COLN, SE_ASTR, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM_MAC] = LAYOUT(
      _______ ,   MAC_SE_SECT ,   MAC_SE_AT ,   MAC_SE_HASH ,   MAC_SE_DLR ,   MAC_SE_PERC ,                                       MAC_SE_AMPR ,   MAC_SE_SLSH ,   MAC_SE_BSLS ,   MAC_SE_TILD ,   MAC_SE_QUES , _______ ,
     _______ , MAC_SE_MINS,  MAC_SE_LBRC , MAC_SE_LPRN,  MAC_SE_LCBR, MAC_SE_EXLM,                                     MAC_SE_EQL, MAC_SE_RCBR, MAC_SE_RPRN, MAC_SE_RBRC, MAC_SE_PLUS, MAC_SE_CIRC,
     _______ , MAC_SE_LABK, MAC_SE_RABK, MAC_SE_UNDS, MAC_SE_QUOT, MAC_SE_PIPE, _______, _______, _______, _______, MAC_SE_GRV, MAC_SE_DQUO, MAC_SE_SCLN,  MAC_SE_COLN, MAC_SE_ASTR, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, COLEMAK , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, COLEMAK_MAC , _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),


/*
* NUM
*
* ,-------------------------------------------.                              ,-------------------------------------------.
* |        |      |      |      |      |      |                              |      |  1   |  2   |  3   |      |        |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                              |  0   |  4   |  5   |  6   |      |        |
* |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |      |  |      |      |      |  7   |  8   |  9   |      |        |
* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        `----------------------------------'  `----------------------------------'
*/
   [_NUM] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                     _______, SE_1, SE_2, SE_3, _______, _______,
     _______, _______, _______, _______, _______, _______,                                     SE_0   , SE_4, SE_5, SE_6, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_7, SE_8, SE_9, _______, _______,
                                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
   ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(SE_VOLU);
        } else {
            tap_code(SE_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(SE_PGDN);
        } else {
            tap_code(SE_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */