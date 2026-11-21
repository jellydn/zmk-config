// Corne v4.1 (crkbd/rev4_1/standard): Graphite Miryoku layout, synced with the
// Silakka54 keymap. Generated from corne-v4.1-graphite.vil; keep both in sync.
// Combos, key overrides and macro M0 live in Vial (load the .vil).
#include QMK_KEYBOARD_H

enum layers { _BASE, _NAV, _MOUSE, _SYM, _NUM, _FN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
              KC_LBRC,          KC_B,          KC_L,          KC_D,          KC_W,          KC_Z,       KC_LEFT,         KC_RIGHT,       KC_QUOT,          KC_F,          KC_O,          KC_U,          KC_J,       KC_RBRC,
               KC_ESC,  LGUI_T(KC_N),  LALT_T(KC_R),  LCTL_T(KC_T),  LSFT_T(KC_S),          KC_G,       KC_MPLY,          KC_MNXT,          KC_Y,  RSFT_T(KC_H),  RCTL_T(KC_A),  RALT_T(KC_E),  RGUI_T(KC_I),       KC_COMM,
               KC_F13,          KC_Q,          KC_X,          KC_M,          KC_C,          KC_V,                                            KC_K,          KC_P,        KC_DOT,       KC_MINS,       KC_SLSH,        KC_DEL,
                                                            KC_EQL, LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),    LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC),       KC_SCLN
    ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
              XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_VOLD,          KC_VOLU,        KC_TAB,       KC_BSPC,         KC_UP,        KC_DEL,       XXXXXXX,       XXXXXXX,
               KC_ESC,       KC_LGUI,       KC_LALT,       KC_LCTL,       KC_LSFT,      OSL(_FN),       KC_MUTE,          KC_MNXT,        KC_ENT,       KC_LEFT,       KC_DOWN,      KC_RIGHT,       KC_CAPS,       XXXXXXX,
              XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                                          KC_ESC,        KC_TAB,       KC_HOME,        KC_END,       XXXXXXX,       XXXXXXX,
                                                           XXXXXXX,       XXXXXXX,       XXXXXXX,          KC_PGUP,       KC_PGDN,       QK_LLCK
    ),

    [_MOUSE] = LAYOUT_split_3x6_3_ex2(
              XXXXXXX,       XXXXXXX,    LGUI(KC_W),    LGUI(KC_C),    LGUI(KC_V),    LGUI(KC_X),       KC_VOLD,          KC_VOLU,        KC_TAB,       XXXXXXX,         MS_UP,       XXXXXXX,       XXXXXXX,       XXXXXXX,
               KC_ESC,       KC_LGUI,       KC_LALT,       KC_LCTL,       KC_LSFT, C(S(G(KC_4))),       KC_MUTE,          KC_MNXT,        KC_ENT,       MS_LEFT,       MS_DOWN,       MS_RGHT,       KC_CAPS,       XXXXXXX,
              XXXXXXX,       XXXXXXX,    LGUI(KC_Q),    LGUI(KC_S),    LGUI(KC_A),      OSL(_FN),                                          KC_ESC,       MS_WHLL,       MS_WHLD,       MS_WHLU,       MS_WHLR,       XXXXXXX,
                                                           XXXXXXX,       XXXXXXX,       XXXXXXX,          MS_BTN1,       MS_BTN2,       QK_LLCK
    ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
              XXXXXXX, LSFT(KC_LBRC),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9), LSFT(KC_RBRC),       XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
              XXXXXXX, LSFT(KC_SCLN),    LSFT(KC_4),    LSFT(KC_5),    LSFT(KC_6),  LSFT(KC_EQL),       XXXXXXX,          XXXXXXX,        KC_ENT,       KC_RSFT,       KC_RCTL,       KC_RALT,       KC_RGUI,       XXXXXXX,
              XXXXXXX,  LSFT(KC_GRV),    LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3), LSFT(KC_BSLS),                                          KC_ESC, LSFT(KC_COMM),  LSFT(KC_DOT), LSFT(KC_SLSH),       XXXXXXX,       XXXXXXX,
                                                        LSFT(KC_9),    LSFT(KC_0), LSFT(KC_MINS),           KC_ENT,       KC_BSPC,       QK_LLCK
    ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
              XXXXXXX,       KC_LBRC,          KC_7,          KC_8,          KC_9,       KC_RBRC,       KC_VOLD,          KC_VOLU,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
              XXXXXXX,       KC_SCLN,          KC_4,          KC_5,          KC_6,        KC_EQL,       KC_MUTE,          KC_MNXT,        KC_ENT,       KC_RSFT,       KC_RCTL,       KC_RALT,       KC_RGUI,       XXXXXXX,
              XXXXXXX,        KC_GRV,          KC_1,          KC_2,          KC_3,       KC_BSLS,                                          KC_ESC,       KC_COMM,        KC_DOT,       KC_SLSH,       XXXXXXX,       XXXXXXX,
                                                              KC_9,          KC_0,       KC_MINS,           KC_ENT,       KC_BSPC,       QK_LLCK
    ),

    [_FN] = LAYOUT_split_3x6_3_ex2(
              XXXXXXX,        KC_F12,         KC_F7,         KC_F8,         KC_F9,       KC_MUTE,       XXXXXXX,          XXXXXXX,       XXXXXXX,       KC_MPRV,       KC_MPLY,       KC_MNXT,       XXXXXXX,       XXXXXXX,
              XXXXXXX,        KC_F11,         KC_F4,         KC_F5,         KC_F6,       KC_VOLU,       XXXXXXX,          XXXXXXX,       XXXXXXX,       KC_RSFT,       KC_RCTL,       KC_RALT,       KC_RGUI,       XXXXXXX,
              XXXXXXX,        KC_F10,         KC_F1,         KC_F2,         KC_F3,       KC_VOLD,                                         XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
                                                            KC_F13,        KC_SPC,        KC_TAB,          XXXXXXX,       XXXXXXX,       QK_LLCK
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_NAV] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_MOUSE] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_SYM] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_NUM] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

// Combos fire only on the base layer, like the Silakka54 ZMK combos. Without
// this, "." and "-" on the Num layer would trigger the sticky Meh combo.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return get_highest_layer(layer_state) == _BASE;
}

// Flow Tap (150 ms in the .vil) turns a home-row mod into a tap when it follows
// a typing key within the term, like require-prior-idle-ms on the Silakka54.
// Vial asks is_flow_tap_key about both keys: the tap-hold key being decided and
// the key before it, which QMK records only when it was tapped. Space/Nav counts
// as the key before, but is never forced to a tap itself, so holding it for Nav
// right after a letter still works (ZMK's layer-taps have no idle rule either).
// It is the key being decided exactly while it is held down.
static bool space_nav_held;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LT(_NAV, KC_SPC)) {
        space_nav_held = record->event.pressed;
    }
    return true;
}

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // a hotkey, not typing (QMK's default rule)
    }
    if (keycode == LT(_NAV, KC_SPC)) {
        return !space_nav_held;
    }
    if (IS_QK_LAYER_TAP(keycode)) {
        return false;
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC: // plain Space, e.g. on the Fn layer
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// The .vil holds no LED settings, so select Typing Heatmap when Vial resets its
// EEPROM (first boot of each new build). Changes made in Vial stay until then.
static bool vial_eeprom_was_reset;

void via_init_kb(void) {
    vial_eeprom_was_reset = !via_eeprom_is_valid();
}

void keyboard_post_init_user(void) {
    if (vial_eeprom_was_reset) {
        rgb_matrix_enable(); // the setters below do nothing while RGB is off
        rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
        rgb_matrix_sethsv(RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL);
    }
}
