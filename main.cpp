/**
 * @file main.cpp
 * @author Sean Kyer (github.com/seankyer)
 */

#include <iostream>
#include <string>
#include "draw.h"

using namespace std;

int main() {

    string f1;
    string f2;

    f1 = "images/dots.ppm";
    f2 = "images/rainbow.ppm";

    Draw d1(f1, 10, 10); // Create the computer artist!
    d1.placePixel(5, 5, 5, 5, 5);
    d1.placePixel(5, 1, 5, 5, 5);
    d1.placePixel(1, 5, 5, 5, 5);
    d1.placePixel(0, 0, 5, 5, 5);

    Draw d2(f2, 255, 255);
    d2.drawRainbow();

    return 0;
}