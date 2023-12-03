#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>

#include <iostream>
#include <string>

class Xwindow {
    Display *d;
    Window w;
    int s;
    GC gc;
    unsigned long colours[14];

   public:
    Xwindow(int width = 500,
            int height = 500);  // Constructor; displays the window.
    ~Xwindow();                 // Destructor; destroys the window.

    enum { White = 0, Black, Red, Green, Blue, Yellow, Cyan, Magenta, SkyBlue, RoyalBlue, LimeGreen, DarkRed, DarkGreen, NavyBlue};  // Available colours.

    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, int colour = Black);

    // Draws a string
    void drawString(int x, int y, std::string msg, int colour = White);

    void setLargerFont(const std::string& inFont);
    void fillCircle(int x, int y, int radius, int colour = Black);
    void fillRoundedRectangle(int x, int y, int width, int height, int arcSize, int colour);
    void drawFilledRoundedRectangle(int x, int y, int width, int height, int arcSize,
                              int fillColour, int outlineColour);
};

#endif