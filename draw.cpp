/**
 * @file draw.cpp
 * @author Sean Kyer (github.com/seankyer)
 */

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "draw.h"

using namespace std;

// Constructor
Draw::Draw(string fp, const int w, const int h) {
    if (w <= 0 || h <= 0) {
        throw invalid_argument("width or height cannot be less than 1");
    }
    if (!hasFileExtension(fp)) {
        fp = fp + ".ppm";
    }
    imgFilePath = fp;
    imgWidth = w;
    imgHeight = h;
    createCanvas();
}


// Public functions:
int Draw::placePixel(int x, int y, int r, int g, int b) {
    // TODO: Places pixel at specified x,y coordinates in image. Returns 1 if successful
    // Check coordinates are inbounds
    if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0) {
        throw invalid_argument("RGB must be exclusively within 0-255");
    }
    if (x >= imgWidth || y >= imgHeight || x < 0 || y < 0) {
        throw invalid_argument("Width or height is out of bounds");
    }
    // Open two images, one in, one out
    ifstream img(imgFilePath);
    ofstream temp("images/temp.ppm");

    string line;
    int lineNum = 0;
    int targetLine = (y * imgHeight) + x;

    for (int j = 0; j < headerSize; j++) {
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


int Draw::placeBox(int x, int y, int wLeangth, int hLeangth, int r, int g, int b) {
    // Draw a filled in box on canvas
    if (wLeangth <= 0 || hLeangth <= 0) {
        throw invalid_argument("Width and height must be greater than 0");
    }
    if (x + wLeangth > imgWidth || y + hLeangth > imgHeight || x < 0 || y < 0) {
        throw invalid_argument("Coordinates or size is out of bounds");
    }



    return 1;
}


map<char, int> Draw::getPixel(int x, int y){
    // TODO: implement this
    map<char, int> pixel;

    if (x >= imgWidth || y >= imgHeight || x < 0 || y < 0) {
        throw invalid_argument("Coordinates are out of bounds");
    }

    ifstream img(imgFilePath);

    // Get to correct line
    int targetLine = (y * imgHeight) + x + headerSize;
    string line;
    for (int lineNum = 0; lineNum <= targetLine; lineNum++) {
        getline(img, line);
    }

    // Extract pixel values, destroys line variable
    string spaceDelimiter = " ";
    string newLineDelimiter = "\n";
    vector<string> p;
    int pos = 0;

    pos = line.find(spaceDelimiter);
    p.push_back(line.substr(0, pos));
    line.erase(0, pos + spaceDelimiter.length());

    pos = line.find(spaceDelimiter);
    p.push_back(line.substr(0, pos));
    line.erase(0, pos + spaceDelimiter.length());

    pos = line.find(newLineDelimiter);
    p.push_back(line.substr(0, pos));
    line.erase(0, pos + newLineDelimiter.length());

    // Place in dictionary and return to caller
    pixel['r'] = stoi(p[0]);
    pixel['g'] = stoi(p[1]);
    pixel['b'] = stoi(p[2]);

    img.close();
    return pixel;
}


void Draw::drawRainbow() {
    // !!! Temp function, will likely be removed later on
    // Draw onto the image
    // Open two images, one in, one out
    ifstream img(imgFilePath);
    ofstream temp("images/temp.ppm");

    string line;

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

void Draw::replaceFile(const string temp) {
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

bool Draw::hasFileExtension(const string &fp) {
    string suffix = ".ppm";

    if (fp.length() >= suffix.length()) {
        return (0 == fp.compare(fp.length() - suffix.length(), suffix.length(), suffix));
    } else {
        return false;
    }
}
