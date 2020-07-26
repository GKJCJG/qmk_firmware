#include "accented_character_impl.c"

#define GET_ACCENT(accent_code, function_name) case accent_code: return function_name(keycode, should_shift);

char * get_accented_character(uint16_t keycode, uint16_t target_accent, bool should_shift) {
  switch (target_accent) {
    GET_ACCENT(GKJ_ACUTE, get_acute)
    GET_ACCENT(GKJ_GRAVE, get_grave)
    GET_ACCENT(GKJ_CFLX, get_circumflex)
    GET_ACCENT(GKJ_MCRN, get_macron)
    GET_ACCENT(GKJ_TREMA, get_trema)
    GET_ACCENT(GKJ_BAR, get_vertical_bar)
    GET_ACCENT(GKJ_HACEK, get_hacek)
    GET_ACCENT(GKJ_TILDE, get_tilde)
    GET_ACCENT(GKJ_DOT, get_dot)
    GET_ACCENT(GKJ_RING, get_ring)
    GET_ACCENT(GKJ_RBLW, get_ring_below)
    GET_ACCENT(GKJ_SMVL, get_semivowel)
    GET_ACCENT(GKJ_UBLW, get_u_below)
    GET_ACCENT(GKJ_CDLA, get_cedilla)
    GET_ACCENT(GKJ_OGNK, get_ogonek)
    GET_ACCENT(GKJ_BRV, get_breve)
    GET_ACCENT(GKJ_SMTH, get_smooth_breathing)
    GET_ACCENT(GKJ_ROUGH, get_rough_breathing)
    GET_ACCENT(GKJ_IOTA, get_iota_subscript)
    default:
      return "";
  }
}
