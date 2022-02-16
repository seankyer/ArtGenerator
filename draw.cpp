/**
 * @file draw.cpp
 * @author Sean Kyer (github.com/seankyer)
 */

#include <iostream>
#include <fstream>
#include <string>
#include "draw.h"

using namespace std;

void Draw::drawImage(string fp, int offset, int width, int height) {
    // Draw an image starting at specified offset point
    cout << "Drawing at offset!" << endl;
    
    // Open file, skip metadeta ()
    fstream img(fp);
    img.seekg(metaData, ios::beg);

    // Seek to specified offset, filling 0s along the way
    for (int y = 0; y < offset; y++) {
        img << 255 << " " << 255 << " " << 255 << endl;
    }

    // Draw image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int r = x % 256;
            int g = y % 256;
            int b = y * x % 256;

            img << r << " " << g << " " << b << endl;
        }
    }

    img.close();
}

void Draw::drawImage(string fp, int width, int height) {
    // Draw an image starting at end of file

    cout << "Drawing at end!" << endl;

    fstream img(fp);
    img.seekg(0, ios::end);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int r = x % 256;
            int g = y % 256;
            int b = y * x % 256;

            img << r << " " << g << " " << b << endl;
        }
    }

    img.close();
}

void Draw::createCanvas(string fp, int width, int height) {
    
    cout << "Creating canvas" << endl;
    ofstream img(fp);

    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;

    img.close();
}