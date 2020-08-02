#include <U8glib.h>
//Initialize display.
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);
void setup(void)
{
    //Set font.
    u8g.setFont(u8g_font_unifont);
}
void loop(void)
{
    u8g.firstPage();
    do {
        u8g.drawStr(2,15,"Vel = ");
        draw();
    } while (u8g.nextPage());
    //Delay before repeating the loop.
    delay(3000);
}
void draw(void)
{
    
    u8g.setPrintPos(55, 15);
    u8g.print(0);
    u8g.drawStr(85, 15, "km/h");
}
