#include "accented_character_impl.c"

char * get_accented_character(uint16_t keycode, uint16_t target_accent) {
  switch (target_accent) {
    case GKJ_ACUTE:
      return get_acute(keycode);
    case GKJ_GRAVE:
      return get_grave(keycode);
    case GKJ_CFLX:
      return get_circumflex(keycode);
    case GKJ_MCRN:
      return get_macron(keycode);
    case GKJ_TREMA:
      return get_trema(keycode);
    case GKJ_BAR:
      return get_vertical_bar(keycode);
    case GKJ_HACEK:
      return get_hacek(keycode);
    case GKJ_TILDE:
      return get_tilde(keycode);
    case GKJ_DOT:
      return get_dot(keycode);
    case GKJ_RING:
      return get_ring(keycode);
    case GKJ_RBLW:
      return get_ring_below(keycode);
    case GKJ_SMVL:
      return get_semivowel(keycode);
    case GKJ_UBLW:
      return get_u_below(keycode);
    case GKJ_CDLA:
      return get_cedilla(keycode);
    case GKJ_OGNK:
      return get_ogonek(keycode);
    case GKJ_BRV:
      return get_breve(keycode);
    case GKJ_SMTH:
      return get_smooth_breathing(keycode);
    case GKJ_ROUGH:
      return get_rough_breathing(keycode);
    case GKJ_IOTA:
      return get_iota_subscript(keycode);
    default:
      return "";
  }
}
