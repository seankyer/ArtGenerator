/**
 * @file draw.h
 * @author Sean Kyer (github.com/seankyer)
 */

#ifndef DRAW_H
#define DRAW_H

#include <map>

class Draw {

    const int headerSize = 3;
    std::string imgFilePath;
    int imgWidth;
    int imgHeight;

    public:
        Draw(std::string filepath, int width, int height);
        
        void drawRainbow();
        int placePixel(int x, int y, int r, int g, int b);
        std::map<char,int> getPixel(int x, int y); // TODO: will need to create a pixelstruct so it can return multiple values

    private:
        void createCanvas();
        void drawBlankImage(); // Used when creating the canvas
        void replaceFile(std::string temp);
};


#endif // DRAW_H