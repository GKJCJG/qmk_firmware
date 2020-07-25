char * exotic_finder(uint16_t keycode) {
  switch (keycode) {
    case GKJ_ASH:
      return "æ";
    case GKJ_U_ASH:
      return "Æ";
    case GKJ_OE:
      return "œ";
    case GKJ_U_OE:
      return "Œ";
    case GKJ_OBAR:
      return "ø";
    case GKJ_U_OBAR:
      return "Ø";
    case GKJ_ETH:
      return "ð";
    case GKJ_U_ETH:
      return "Ð";
    case GKJ_THRN:
      return "þ";
    case GKJ_U_THRN:
      return "Þ";
    case GKJ_SZ:
      return "ß";
    case GKJ_U_SZ:
      return "ẞ";
    case GKJ_LBAR:
      return "ł";
    case GKJ_U_LBAR:
      return "Ł";
    case GKJ_HBAR:
      return "ħ";
    case GKJ_U_HBAR:
      return "Ħ";
    case GKJ_BBAR:
      return "ƀ";
    case GKJ_U_BBAR:
      return "Ƀ";
    case GKJ_IDOT:
      return "ı";
    case GKJ_U_IDOT:
      return "İ";
    case GKJ_OKINA:
      return "ʻ";
    case GKJ_U_OKINA:
      return "ء";
    default:
      return "";
  }
}
