/**
 * @file draw.h
 * @author Sean Kyer (github.com/seankyer)
 */

#ifndef DRAW_H
#define DRAW_H

class Draw {

const int metaData = 18;

public:
    // TODO: Make width and height passing unnecesary, extract values from metadata in methods
    void drawImage(std::string filePath, int offset, int width, int height);
    void drawImage(std::string filePath, int width, int height);
    void createCanvas(std::string filePath, int width, int height);
};

#endif // DRAW_H