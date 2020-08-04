#ifndef OLED_H
#define OLED_H

#include <Arduino.h>

class Oled {
  public: 
    Oled();
    void showVar(String var, int x, int y);
    void showString(String myString, int x, int y);
}

#endif;
