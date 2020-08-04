#include <Oled.h>
#include <Arduino.h>
#include <U8glib.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

Oled::Oled(){
  u8g.setFont(u8g_font_unifont);
}

void Oled::showVar(String var, int x, int y) {
  u8g.setPrintPos(x,y);
  u8g.print("Vel = ");
}
void Oled::showString(String cad, int x, int y) {
  u8g.setPrintPos(x,y);
  u8g.print(cad);
}
