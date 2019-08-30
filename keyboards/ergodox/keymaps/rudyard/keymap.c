#include "action_layer.h"
#include "debug.h"
#include "ergodox.h"
#include "version.h"

#define LAYER0 0 // default layer
#define LAYER1 1 // parens, brackets, braces
#define LAYER2 2 // symbols
#define LAYER3 3 // numpad
#define LAYER4 4 // ???
#define LAYER5 5 // ???

// Macros
#define EXIT 16
#define WIZARD 17

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Abbreviations
#define DBL_QUOT LSFT(KC_QUOT)
#define SH_COL SFT_T(KC_SCLN)
#define CT_SLS CTL_T(KC_SLSH)
#define SH_QUOT SFT_T(DBL_QUOT)
#define CTL_ALT LCTL(KC_LALT)
#define CTL_GUI LCTL(KC_LGUI)
#define HYPER ALL_T(KC_NO)
#define C_b LCTL(KC_B)
#define G_SLSH GUI_T(KC_SLSH)
#define G_BSLS GUI_T(KC_BSLS)
#define A_SLSH ALT_T(KC_SLSH)
#define O_CTL OSM(MOD_LCTL)

// Hold LAYER1
#define HL1 MO(LAYER1)
// Toggle LAYER1
#define TG1 TG(LAYER1)
// One-Shot LAYER1
#define OS1 OSL(LAYER1)
// Hold LAYER2
#define HL2 MO(LAYER2)
// Toggle LAYER2
#define TG2 TG(LAYER2)
// Hold LAYER3
#define HL3 MO(LAYER3)
// Toggle LAYER3
#define TG3 TG(LAYER3)
// Hold LAYER4
#define HL4 MO(LAYER4)
// Toggle LAYER4
#define TG4 TG(LAYER4)
#define HL5 MO(LAYER5)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* LAYER0
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  ESC  │  1  │  2  │  3  │  4  │  5  │ HL4 │     │ TG4 │  6  │  7  │  8  │  9  │  0  │ LEADR │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   ~   │  q  │  w  │  e  │  r  │  t  │ C-G │     │ TG3 │  y  │  u  │  i  │  o  │  p  │   =   │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │  TAB  │  a  │  s  │  d  │  f  │  g  ├─────┤     ├─────┤  h  │  j  │  k  │  l  │ ;/S │   -   │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤ C-b │     │ C-b ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ SHIFT │  z  │  x  │  c  │  v  │  b  │     │     │     │  n  │  m  │  ,  │  .  │ //G │   '   │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │CAPLK│     │     │ GUI │ ALT │                             │ HL1 │  ←  │  ↓  │  ↑  │  →  │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ HL2 │ C-G │ │PG DN│PG UP│
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ ESC │ │     │     │     │
 *                             │O-CTL│ HL1 ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │ GUI │ │ BSP │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[LAYER0] = KEYMAP(
     // LEFT HAND
     // 0          1          2          3          4          5          6
        KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      HL4,
        KC_TILD,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      CTL_GUI,
        KC_TAB,    KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      /********/
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      C_b,
        KC_CAPS,   XXXXXXX,   XXXXXXX,   HYPER,     KC_LALT,   /********/ /********/
                                                    /********/ HL3,       CTL_GUI,
                                                    /********/ /********/ KC_ESC,
                                                    KC_LCTL,   HL2,       KC_LGUI,
     // RIGHT HAND
     // 7          8          9          10         11         12         13
        TG4,       KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_LEAD,
        TG3,       KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_EQL,
        /********/ KC_H,      KC_J,      KC_K,      KC_L,      SH_COL,    KC_MINS,
        C_b,       KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_QUOT,
                              HL1,       KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,
        KC_PGDN,   KC_PGUP,   /********/
        XXXXXXX,   /********/ /********/
        KC_BSPC,   KC_ENT,    KC_SPC
    ),


/*
 * LAYER1
 *
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │ RESET │ F01 │ F02 │ F03 │ F04 │ F05 │     │     │     │ F06 │ F07 │ F08 │ F09 │ F10 │ RESET │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  1  │  2  │  3  │  4  │  5  │     │     │     │  6  │  7  │  8  │  9  │  0  │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │   `   │  "  │  {  │  [  │  (  │  |  ├─────┤     ├─────┤  |  │  )  │  ]  │  }  │  '  │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │  /  │  *  │  -  │  +  │     │     │     │     │     │  :  │     │     │  \  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │(HL1)│     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │ END │ HME │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │(HL1)├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[LAYER1] = KEYMAP(
    // LEFT HAND
    //  0          1          2          3          4          5          6
        RESET,     KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   _______,
        _______,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      _______,
        KC_GRV,    DBL_QUOT,  KC_LCBR,   KC_LBRC,   KC_LPRN,   KC_PIPE,   /********/
        _______,   KC_SLSH,   KC_ASTR,   KC_MINS,   KC_PLUS,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   /********/ /********/
                                                    /********/ _______,   _______,
                                                    /********/ /********/ _______,
                                                    _______,   _______,   _______,
    // RIGHT HAND
    //  7          8          9          10         11         12         13
        _______,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_F9,     KC_F10,    RESET,
        _______,   KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
        /********/ KC_PIPE,   KC_RPRN,   KC_RBRC,   KC_RCBR,   KC_QUOT,   M(EXIT),
        _______,   _______,   KC_COLN,   _______,   _______,   G_BSLS,    _______,
                              _______,   _______,   _______,   _______,   _______,
        KC_END,    KC_HOME,   /********/
        _______,   /********/ /********/
        _______,   _______,   _______
    ),

/* LAYER2
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │ RESET │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  !  │  @  │  #  │  $  │  %  │     │     │     │  ^  │  &  │  *  │     │     │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     ├─────┤     ├─────┤  ←  │  ↓  │  ↑  │  →  │  '  │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │     │     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[LAYER2] = KEYMAP(
    // LEFT HAND
    //  0          1          2          3          4          5          6
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   /********/
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   /********/ /********/
                                                    /********/ _______,   _______,
                                                    /********/ /********/ _______,
                                                    _______,   _______,   _______,
    // RIGHT HAND
    //  7          8          9          10         11         12         13
        _______,   _______,   _______,   _______,   _______,   _______,   RESET,
        _______,   KC_CIRC,   KC_AMPR,   KC_ASTR,   _______,   _______,   _______,
        /********/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_QUOT,   _______,
        _______,   _______,   _______,   _______,   _______,   KC_QUES,   _______,
                              _______,   KC_MUTE,   KC_VOLD,   KC_VOLU,   _______,
        KC_END,    KC_HOME,   /********/
        KC_INS,    /********/ /********/
        KC_DEL,    _______,   _______
    ),

/* LAYER3
 * numpad
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │ WIZ │     │     │     │  =  │  /  │  *  │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │  ↑  │     │     │     │     │     │  [  │  7  │  8  │  9  │  -  │   ]   │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │     │  ←  │  ↓  │  →  │     ├─────┤     ├─────┤  (  │  4  │  5  │  6  │  +  │   )   │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │  ,  │  1  │  2  │  3  │ RTN │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │  .  │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[LAYER3] = KEYMAP(
    // LEFT HAND
    //  0          1          2          3          4          5          6
        _______,   _______,   _______,   _______,   _______,   _______,   M(WIZARD),
        _______,   _______,   _______,   KC_UP,     _______,   _______,   _______,
        _______,   _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,   /********/
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   /********/ /********/
                                                    /********/ _______,   _______,
                                                    /********/ /********/ _______,
                                                    _______,   _______,   _______,
    // RIGHT HAND
    //  7          8          9          10         11         12         13
        _______,   _______,   KC_EQL,    KC_SLSH,   KC_ASTR,   _______,   _______,
        _______,   KC_LBRC,   KC_7,      KC_8,      KC_9,      KC_MINS,   KC_RBRC,
        /********/ KC_LPRN,   KC_4,      KC_5,      KC_6,      KC_PLUS,   KC_RPRN,
        _______,   KC_COMM,   KC_1,      KC_2,      KC_3,      KC_ENT,    _______,
                              KC_0,      KC_DOT,    _______,   _______,   _______,
        _______,   _______,   /********/
        _______,   /********/ /********/
        _______,   _______,   _______
    ),

/* LAYER4
 * VIM
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     ├─────┤     ├─────┤  ←  │  ↓  │  ↑  │  →  │     │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │     │     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │ HL5 │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[LAYER4] = KEYMAP(
    // left hand
    //  0          1          2          3          4          5          6
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   /********/
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   /********/ /********/
                                                    /********/ _______,   _______,
                                                    /********/ /********/ _______,
                                                    HL5,       _______,   _______,
    // right hand
    //  7          8          9          10         11         12         13
        _______,   _______,   _______,   _______,   _______,   _______,   M(WIZARD),
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        /********/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
                              _______,   _______,   _______,   _______,   _______,
        _______,   _______,   /********/
        _______,   /********/ /********/
        _______,   _______,   _______
    ),

/* LAYER5
 * VIM (CTRL HELD)
 *
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │PG UP│     │     │     │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │     │     │PG DN│     │     ├─────┤     ├─────┤  ←  │  ↓  │  ↑  │  →  │     │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │     │     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │(HL5)│     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[LAYER5] = KEYMAP(
    // left hand
    //  0          1          2          3          4          5          6
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   /********/
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   /********/ /********/
                                                    /********/ _______,   _______,
                                                    /********/ /********/ _______,
                                                    _______,   _______,   _______,
    // right hand
    //  7          8          9          10         11         12         13
        _______,   _______,   _______,   _______,   _______,   _______,   M(WIZARD),
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
        /********/ KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,
                              _______,   _______,   _______,   _______,   _______,
        _______,   _______,   /********/
        _______,   /********/ /********/
        _______,   _______,   _______
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [LAYER1] = ACTION_LAYER_TAP_TOGGLE(LAYER1) // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
            if (record->event.pressed) {
              SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;
        case 1:
            if (record->event.pressed) { // For resetting EEPROM
              eeconfig_init();
            }
            break;
        case EXIT:
            if (record->event.pressed) {
                return MACRO(D(LCTL), T(C), U(LCTL), T(ENT), END);
            }
            break;
        case WIZARD:
            if (record->event.pressed) {
                return MACRO(
                    T(LGUI),
                    WAIT(250),
                    T(C), T(H), T(R), T(O), T(M), T(E),
                    WAIT(100),
                    T(ENT),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    // https://youtu.be/tKNhPpUR0Pg?t=1m36s
                    T(H), T(T), T(T), T(P), T(S), D(LSFT), T(SCLN), U(LSFT), T(SLSH), T(SLSH), T(Y), T(O), T(U), T(T), T(U), T(DOT), T(B), T(E), T(SLSH), T(T), D(LSFT), T(K), T(N), U(LSFT), T(H), D(LSFT), T(P), U(LSFT), T(P), D(LSFT), T(U), T(R), U(LSFT), T(0), D(LSFT), T(P), U(LSFT), T(G), D(LSFT), T(SLSH), U(LSFT), T(T), T(EQL), T(1), T(M), T(3), T(6), T(S), T(ENT),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    WAIT(250),
                    D(LCTL), T(W), U(LCTL),
                    END
                );
            }
            break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
                #endif
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
    // uint8_t layer = biton32(layer_state);
    /*
    switch (layer) {
        case LAYER0:
            lcd_backlight_hal_color(0x1000, 0x1000, 0x1000);
            break;
        case LAYER1:
            lcd_backlight_hal_color(0x1000, 0x0000, 0x0000);
            break;
        case LAYER2:
            lcd_backlight_hal_color(0x0000, 0x1000, 0x0000);
            break;
        case LAYER3:
            lcd_backlight_hal_color(0x0000, 0x0000, 0x1000);
            break;
        case LAYER4:
            lcd_backlight_hal_color(0x0000, 0x1000, 0x1000);
            break;
        default:
            break;
    }
    */
};