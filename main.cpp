/**
 * @file main.cpp
 * @author Sean Kyer (github.com/seankyer)
 */

#include <iostream>
#include <string>
#include "draw.h"

using namespace std;

const int width = 255;
const int height = 255;
const int offset = 120;

int main() {

    string f1;
    string f2;

    f1 = "images/pic_offset.ppm";
    f2 = "images/pic_norm.ppm";

    Draw d; // Create the computer artist!
    d.createCanvas(f1, width, height);
    d.drawImage(f1, offset, width, height);

    d.createCanvas(f2, width, height);
    d.drawImage(f2, width, height);

    return 0;
}