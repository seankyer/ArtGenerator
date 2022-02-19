/**
 * @file main.cpp
 * @author Sean Kyer (github.com/seankyer)
 */

#include <iostream>
#include <string>
#include "draw.h"

using namespace std;

int main() {

    string f1 = "images/dots.ppm";

    Draw d1(f1, 10, 10); // Create the computer artist!
    d1.placePixel(1, 5, 5, 58, 43);
    map<char, int> p1 = d1.getPixel(1,5);
    cout << "R: " << p1['r'] << endl;
    cout << "G: " << p1['g'] << endl;
    cout << "B: " << p1['b'] << endl;

    // Box development
    string f2 = "images/rainbow.ppm";
    Draw d2(f2, 255, 255);
    d2.drawRainbow();
    int result = d2.placeBox(254, 254, 1, 1, 7, 7, 7);
    cout << result << endl;

    return 0;
}