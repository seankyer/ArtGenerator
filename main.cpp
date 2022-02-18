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
    d1.placePixel(5, 5, 5, 5, 5);
    d1.placePixel(5, 1, 55, 250, 0);
    d1.placePixel(1, 5, 5, 58, 43);
    d1.placePixel(0, 0, 75, 55, 77);
    map<char, int> p1 = d1.getPixel(0,0);
    cout << "R: " << p1['r'] << endl;
    cout << "G: " << p1['g'] << endl;
    cout << "B: " << p1['b'] << endl;

    string f2 = "images/rainbow.ppm";
    Draw d2(f2, 255, 255);
    d2.drawRainbow();
    map<char, int> p2 = d2.getPixel(100,100);
    cout << "R: " << p2['r'] << endl;
    cout << "G: " << p2['g'] << endl;
    cout << "B: " << p2['b'] << endl;

    return 0;
}