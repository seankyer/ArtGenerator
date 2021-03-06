/**
 * @file draw.h
 * @author Sean Kyer (github.com/seankyer)
 */

#ifndef DRAW_H
#define DRAW_H

#include <map>

class Draw {

    const int headerSize = 3;

    public:
        std::string imgFilePath;
        int imgWidth;
        int imgHeight;
        
        Draw(std::string filepath, int width, int height);
        
        void drawRainbow();
        int placePixel(int x, int y, int r, int g, int b);
        int placeBox(int x, int y, int wLeangth, int hLeangth, int r, int g, int b);
        std::map<char,int> getPixel(int x, int y); // TODO: will need to create a pixelstruct so it can return multiple values

    private:
        void createCanvas();
        void drawBlankImage(); // Used when creating the canvas
        void replaceFile(std::string temp);
        bool hasFileExtension(const std::string &fp);
};


#endif // DRAW_H