/**
 * @file draw.cpp
 * @author Sean Kyer (github.com/seankyer)
 */

#include <iostream>
#include <fstream>
#include <string>
#include "draw.h"

using namespace std;

// Constructor
Draw::Draw(string fp, int w, int h) {
    imgFilePath = fp;
    imgWidth = w;
    imgHeight = h;
    createCanvas();
    cout << "Created Draw object with variables:\n" << 
        "filepath: " << imgFilePath << "\n" << 
        "width: " << imgWidth << "\n" << 
        "height: " << imgHeight << endl;

}


// Public functions:
int Draw::placePixel(int x, int y, int r, int g, int b) {
    // TODO: Places pixel at specified x,y coordinates in image. Returns 1 if successful
    // Check coordinates are inbounds
    if (x > imgWidth || y > imgHeight || x < 0 || y < 0) {
        cerr << "Draw::placePixel: Coordinates are out of bounds!" << endl;
        return 0;
    }
    // Open two images, one in, one out
    ifstream img(imgFilePath);
    ofstream temp("images/temp.ppm");

    string line;
    int lineNum = 0;
    int targetLine = (y * imgHeight) + x;

    for (int x = 0; x < headerSize; x++) {
        getline(img, line);
        temp << line << "\n";
    }

    while (getline(img, line)) {
        if (lineNum == targetLine) {
            temp << r << " " << g << " " << b << "\n";
        } else {
            temp << line << "\n";
        }
        lineNum = lineNum + 1;
    }

    temp.close();
    img.close();
    replaceFile("images/temp.ppm");
    
    return 1;
}


void Draw::getPixel(int x, int y){
    // TODO: implement this

}


void Draw::drawRainbow() {
    // Draw onto the image
    // Open two images, one in, one out
    ifstream img(imgFilePath);
    ofstream temp("images/temp.ppm");

    string line;
    int lineNum = 0;

    for (int x = 0; x < headerSize; x++) {
        getline(img, line);
        temp << line << "\n";
    }

    for (int x = 0; x < imgWidth; x++) {
        for (int y = 0; y < imgHeight; y++) {
            int r = x % 256;
            int g = y % 256;
            int b = x * y % 256;

            temp << r << " " << g << " " << b << "\n";
        }
    }

    temp.close();
    img.close();
    replaceFile("images/temp.ppm");
}


// Private functions:
void Draw::createCanvas() {
    // Creates entirely white canvas of specified width x height
    ofstream img(imgFilePath);
    img << "P3" << endl;
    img << imgWidth << " " << imgHeight << endl;
    img << "255" << endl;
    img.close();
    drawBlankImage();
}


void Draw::drawBlankImage() {
    // Populates canvas with all white values
    fstream img(imgFilePath);
    img.seekg(0, ios::end);
    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            img << 255 << " " << 255 << " " << 255 << endl;
        }
    }
    img.close();
}


void Draw::replaceFile(string temp) {
    // Replace old file with updated one
    int result;
    result = remove(imgFilePath.c_str());
    if (result != 0) {
        cerr << "Error removing file" << endl;
        exit(1);
    }
    result = rename(temp.c_str(), imgFilePath.c_str());
    if (result != 0) {
        cerr << "Error renaming file" << endl;
        exit(1);
    }
}