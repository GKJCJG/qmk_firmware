#define CHARACTER_WITH_CASE(keycode, value_l, value_u) case keycode: \
  if (should_shift) {                                                \
    return value_u;                                                  \
  } else {                                                           \
    return value_l;                                                  \
  }                                                                  \

#define CHARACTER_NO_CASE(keycode, value) case keycode: return value;

char * get_acute(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "́")
    CHARACTER_WITH_CASE(KC_A, "á", "Á")
    CHARACTER_WITH_CASE(KC_C, "ć", "Ć")
    CHARACTER_WITH_CASE(KC_E, "é", "É")
    CHARACTER_WITH_CASE(KC_G, "ǵ", "Ǵ")
    CHARACTER_WITH_CASE(KC_I, "í", "Í")
    CHARACTER_WITH_CASE(KC_K, "ḱ", "Ḱ")
    CHARACTER_WITH_CASE(KC_N, "ń", "Ń")
    CHARACTER_WITH_CASE(KC_R, "ŕ", "Ŕ")
    CHARACTER_WITH_CASE(KC_S, "ś", "Ś")
    CHARACTER_WITH_CASE(KC_O, "ó", "Ó")
    CHARACTER_WITH_CASE(KC_U, "ú", "Ú")
    CHARACTER_WITH_CASE(KC_Y, "ý", "Ý")
    CHARACTER_WITH_CASE(GKJ_ASH, "ǽ", "Ǽ")
    CHARACTER_WITH_CASE(GKJ_OBAR, "ǿ", "Ǿ")
    CHARACTER_WITH_CASE(GK_A, "ά", "Ά")
    CHARACTER_WITH_CASE(GK_E, "έ", "Έ")
    CHARACTER_WITH_CASE(GK_H, "ή", "Ή")
    CHARACTER_WITH_CASE(GK_I, "ί", "Ί")
    CHARACTER_WITH_CASE(GK_O, "ό", "Ό")
    CHARACTER_WITH_CASE(GK_Y, "ύ", "ϓ")
    CHARACTER_WITH_CASE(GK_OO, "ώ", "Ώ")
    default:
      return "";
  }
}
char * get_grave(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̀")
    CHARACTER_WITH_CASE(KC_A, "à", "À")
    CHARACTER_WITH_CASE(KC_E, "è", "È")
    CHARACTER_WITH_CASE(KC_I, "ì", "Ì")
    CHARACTER_WITH_CASE(KC_O, "ò", "Ò")
    CHARACTER_WITH_CASE(KC_U, "ù", "Ù")

    default:
      return "";
  }
}
char * get_circumflex(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̂")
    CHARACTER_WITH_CASE(KC_A, "â", "Â")
    CHARACTER_WITH_CASE(KC_E, "ê", "Ê")
    CHARACTER_WITH_CASE(KC_I, "î", "Î")
    CHARACTER_WITH_CASE(KC_O, "ô", "Ô")
    CHARACTER_WITH_CASE(KC_U, "û", "Û")
    CHARACTER_NO_CASE(GK_A, "ᾶ")
    CHARACTER_NO_CASE(GK_H, "ῆ")
    CHARACTER_NO_CASE(GK_I, "ῖ")
    CHARACTER_NO_CASE(GK_Y, "ῦ")
    CHARACTER_NO_CASE(GK_OO, "ῶ")
    default:
      return "";
  }
}
char * get_macron(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̄")
    CHARACTER_WITH_CASE(KC_A, "ā", "Ā")
    CHARACTER_WITH_CASE(KC_E, "ē", "Ē")
    CHARACTER_WITH_CASE(KC_I, "ī", "Ī")
    CHARACTER_WITH_CASE(KC_O, "ō", "Ō")
    CHARACTER_WITH_CASE(KC_U, "ū", "Ū")
    CHARACTER_WITH_CASE(KC_Y, "ȳ", "Ȳ")
    CHARACTER_WITH_CASE(GKJ_ASH, "ǣ", "Ǣ")
    CHARACTER_WITH_CASE(GKJ_OBAR, "ø̄", "Ø̄")
    CHARACTER_WITH_CASE(GKJ_OE, "œ̄", "Œ̄")
    CHARACTER_WITH_CASE(GK_A, "ᾱ", "Ᾱ")
    CHARACTER_WITH_CASE(GK_I, "ῑ", "Ῑ")
    CHARACTER_WITH_CASE(GK_Y, "ῡ", "Ῡ")
    default:
      return "";
  }
}
char * get_trema(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̈")
    CHARACTER_WITH_CASE(KC_A, "ä", "Ä")
    CHARACTER_WITH_CASE(KC_E, "ë", "Ë")
    CHARACTER_WITH_CASE(KC_I, "ï", "Ï")
    CHARACTER_WITH_CASE(KC_O, "ö", "Ö")
    CHARACTER_WITH_CASE(KC_U, "ü", "Ü")
    CHARACTER_WITH_CASE(KC_Y, "ÿ", "Ÿ")
    CHARACTER_WITH_CASE(GK_I, "ϊ", "Ϊ")
    CHARACTER_WITH_CASE(GK_Y, "ϋ", "Ϋ")
    default:
      return "";
  }
}
char * get_vertical_bar(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̍")
    CHARACTER_WITH_CASE(KC_A, "a̍", "A̍")
    CHARACTER_WITH_CASE(KC_E, "e̍", "E̍")
    CHARACTER_WITH_CASE(KC_I, "i̍", "I̍")
    CHARACTER_WITH_CASE(KC_O, "o̍", "O̍")
    CHARACTER_WITH_CASE(KC_U, "u̍", "U̍")
    default:
      return "";
  }
}
char * get_hacek(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̌")
    CHARACTER_WITH_CASE(KC_A, "ǎ", "Ǎ")
    CHARACTER_WITH_CASE(KC_C, "č", "Č")
    CHARACTER_WITH_CASE(KC_E, "ě", "Ě")
    CHARACTER_WITH_CASE(KC_I, "ǐ", "Ǐ")
    CHARACTER_WITH_CASE(KC_O, "ǒ", "Ǒ")
    CHARACTER_WITH_CASE(KC_U, "ǔ", "Ǔ")
    CHARACTER_WITH_CASE(GKJ_UE, "ǚ", "Ǚ")
    default:
      return "";
  }
}
char * get_tilde(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̃")
    default:
      return "";
  }
}
char * get_dot(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̇")
    default:
      return "";
  }
}
char * get_ring(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̊")
    CHARACTER_WITH_CASE(KC_A, "å", "Å")
    default:
      return "";
  }
}
char * get_ring_below(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̥")
    default:
      return "";
  }
}
char * get_semivowel(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̯")
    default:
      return "";
  }
}
char * get_u_below(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̮")
    default:
      return "";
  }
}
char * get_cedilla(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̧")
    default:
      return "";
  }
}
char * get_ogonek(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̨")
    default:
      return "";
  }
}
char * get_breve(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̆")
    default:
      return "";
  }
}
char * get_smooth_breathing(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̓")
    CHARACTER_WITH_CASE(GK_A, "ἀ", "Ἀ")
    CHARACTER_WITH_CASE(GK_E, "ἐ", "Ἐ")
    CHARACTER_WITH_CASE(GK_H, "ἠ", "Ἠ")
    CHARACTER_WITH_CASE(GK_I, "ἰ", "Ἰ")
    CHARACTER_WITH_CASE(GK_O, "ὀ", "Ὀ")
    CHARACTER_NO_CASE(GK_Y, "ὐ")
    CHARACTER_WITH_CASE(GK_OO, "ὠ", "Ὠ")
    default:
      return "";
  }
}
char * get_rough_breathing(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "̔")
    CHARACTER_WITH_CASE(GK_A, "ἁ", "Ἁ")
    CHARACTER_WITH_CASE(GK_E, "ἑ", "Ἑ")
    CHARACTER_WITH_CASE(GK_H, "ἡ", "Ἡ")
    CHARACTER_WITH_CASE(GK_I, "ἱ", "Ἱ")
    CHARACTER_WITH_CASE(GK_O, "ὁ", "Ὁ")
    CHARACTER_WITH_CASE(GK_Y, "ὑ", "Ὑ")
    CHARACTER_WITH_CASE(GK_OO, "ὡ", "Ὡ")
    default:
      return "";
  }
}
char * get_iota_subscript(uint16_t keycode, bool should_shift) {
  switch(keycode) {
    CHARACTER_NO_CASE(KC_SPC, "ͅ")
    default:
      return "";
  }
}
