#include <U8glib.h>
//Initialize display.
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
void setup(void)
{
    u8g.setFont(u8g_font_unifont);
}
void loop(void)
{
    u8g.firstPage();
    do {
        draw();
    } while (u8g.nextPage());
    delay(3000);
}
void draw(void)
{
    u8g.setPrintPos(2, 15);
    u8g.print("Vel =");
    u8g.setPrintPos(55, 15);
    u8g.print(0);
    u8g.setPrintPos(88, 15);
    u8g.print("km/h");
}
