char * get_foreign_letter(uint16_t keycode) {
  if (keycode > R_START) {
    return russian_finder(keycode);
  }
  if (keycode > GK_START) {
    return greek_finder(keycode);
  }
  if (keycode > GKJ_START) {
    return exotic_finder(keycode);
  }
  return "";
}
