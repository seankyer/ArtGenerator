#include <iostream>
#include <string>
#include <map>
#include "../draw.h"

using namespace std;

void testDrawConstructor() {
    cout << "*** TESTING DRAW CONSTRUCTOR ***" << endl;

    // Test constructor, expect success
    Draw d1("tests/testImages/t1.ppm", 10, 10);
    if (d1.imgWidth == 10 && d1.imgHeight == 10) {
        cout << "PASS: Width and height match values" << endl;
    } else {
        cout << "FAIL: Width or height don't match values" << endl;
    }

    if (d1.imgFilePath == "tests/testImages/t1.ppm") {
        cout << "PASS: Filepath matches value" << endl;
    } else {
        cout << "~~~ FAIL: Filepath does not match value ~~~" << endl;
    }

    // Test constuctor with no file extension
    Draw d4("tests/testImages/t2", 5, 5);
    if (d4.imgFilePath == "tests/testImages/t2.ppm") {
        cout << "PASS: Filepath was appending with .ppm" << endl;
    } else {
        cout << "~~~ FAIL: Filepath should have been appended with .ppm ~~~" << endl;
    }

    // Test constructor with invalid values
    try {
        Draw d2("tests/testImages/t1.ppm", 0, 50);
        cout << "~~~ FAIL: Should have thrown exception ~~~" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for invalid width" << endl;
    }
    
    try {
        Draw d3("tests/testImages/t1.ppm", 50, 0);
        cout << "~~~ FAIL: Should have thrown exception ~~~" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for invalid height" << endl;
    }
}

void testPlacePixel() {
    cout << "*** TESTING PLACEPIXEL ***" << endl;
    Draw d1("tests/testImages/place1.ppm", 10, 10);

    // Test pixel is placed and all other pixels are unneffected (default is 255)
    d1.placePixel(5, 5, 0, 0 ,0);
    map<char, int> pixel;
    for (int x = 0; x < d1.imgWidth; x++) {
        for (int y = 0; y < d1.imgHeight; y++) {
            pixel = d1.getPixel(x, y);
            if (x == 5 && y == 5) {
                if (pixel['r'] == 0 && pixel['g'] == 0 && pixel['b'] == 0) {
                    cout << "PASS: Pixel placed in correct position" << endl;
                }
            } else {
                if (pixel['r'] == 255 && pixel['g'] == 255 && pixel['b'] == 255) {
                    // Pass
                } else {
                    cout << "~~~ FAIL: All other pixels should be 255,255,255 ~~~" << endl;
                }
            }
        }
    }

    // Try invalid input arguments
    try {
        d1.placePixel(5, 5, -1, 5, 5);
        cout << "~~~ FAIL: Negative RGB value should be rejected ~~~" << endl;
    } catch (exception &e) {
        cout << "PASS: Negative RGB value should be rejected" << endl;
    }

    try {
        d1.placePixel(5, 5, 256, 5, 5);
        cout << "~~~ FAIL: RGB Values over 255 should be rejected ~~~" << endl;
    } catch (exception &e) {
        cout << "PASS: RGB Values over 255 should be rejected" << endl;
    }

    try {
        d1.placePixel(5, 5, 255, 255, 255);
        cout << "PASS: RGB Values at 255 should be accepted" << endl;
    } catch (exception &e) {
        cout << "~~~ FAIL: RGB Values at 255 should be accepted ~~~" << endl;
    }

    try {
        d1.placePixel(0, 0, 255, 255, 255);
        cout << "PASS: Coordinates at 0 should be accepted" << endl;
    } catch (exception &e) {
        cout << "~~~ FAIL: Coordinates at 0 should be accepted ~~~" << endl;
    }

    try {
        d1.placePixel(10, 10, 255, 255, 255);
        cout << "~~~ FAIL: Coordinates at max w/h should be rejected ~~~" << endl;
    } catch (exception &e) {
        cout << "PASS: Coordinates at max w/h should be rejected" << endl;
    }

    try {
        d1.placePixel(9, 9, 255, 255, 255);
        cout << "PASS: Coordinates at inclusive of max w/h should be accepted" << endl;
    } catch (exception &e) {
        cout << "~~~ FAIL: Coordinates at inclusive of max w/h should be accepted ~~~" << endl;
    }
}

void testPlaceBox() {
    cout << "*** TESTING PLACEBOX ***" << endl;
    // TODO: Implement tests
    Draw pic("tests/testImages/p4.ppm", 25, 25);
    map<char, int> pixel;

    // Test box placement and color correctness
    try {
        int result = pic.placeBox(10, 10, 10, 10, 7, 7, 7);
        if (result == 1) {
            cout << "PASS: Box should return succesfully" << endl;
        } else {
            cout << "FAIL: No exception, but function returned with non 1" << endl;
        }
    } catch (exception &e) {
        cout << "FAIL: Should not throw exception" << endl;
    }

    int result = 0;

    for (int x = 0; x < pic.imgWidth; x++) {
        for (int y = 0; y < pic.imgHeight; y++) {
            if (x >= 10 && x < 20 && y >= 10 && y < 20) {
                pixel = pic.getPixel(x, y);
                if (pixel['r'] != 7 || pixel['g'] != 7 || pixel['b'] != 7) {
                    result = 1;
                    cout << "~~~ FAIL: Pixel at x: " << x << " y: " << y << " Should equal r: 7, g: 7, b: 7" <<
                        " Instead equals: r: " << pixel['r'] << " g: " << pixel['g'] << " b: " << pixel['b'] << " ~~~" << endl;
                }
            } else {
                pixel = pic.getPixel(x, y);
                if (pixel['r'] != 255 || pixel['g'] != 255 || pixel['b'] != 255) {
                    result = 1;
                    cout << "~~~ FAIL: Pixel at x: " << x << " y: " << y << " Should equal r: 255, g: 255, b: 255" <<
                        " Instead equals: r: " << pixel['r'] << " g: " << pixel['g'] << " b: " << pixel['b'] << " ~~~" << endl;
                }
            }
        }
    }

    if (result == 0) {
        cout << "PASS: No errors in box placement" << endl;
    }

    // Test invalid arguments:
    try {
        pic.placeBox(26, 1, 10, 10, 6, 6, 6);
        cout << "FAIL: Should have thrown exception for x being out of bounds" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for x being out of bounds" << endl;
    }

    try {
        pic.placeBox(10, 1, 20, 10, 256, 6, 6);
        cout << "FAIL: Should have thrown exception for RGB being out of range" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for RGB being out of range" << endl;
    }

    try {
        pic.placeBox(10, -1, 20, 10, 256, 6, 6);
        cout << "FAIL: Should have thrown exception for Y being negative" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for Y being negative" << endl;
    }

    try {
        pic.placeBox(10, 1, 0, 0, 256, 6, 6);
        cout << "FAIL: Should have thrown exception for leangth being less than 1" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for leangth being less than 1" << endl;
    }

    // Tests around corner cases of box edges
    try {
        pic.placeBox(10, 1, 20, 10, 6, 6, 6);
        cout << "FAIL: Should have thrown exception for x leangth being out of bounds" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for x leangth being out of bounds" << endl;
    }

    try {
        pic.placeBox(25, 25, 1, 1, 6, 6, 6);
        cout << "FAIL: Should have thrown exception for x/y + leangth being out of bounds" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception thrown for x/y + leangth being out of bounds" << endl;
    }

    try {
        pic.placeBox(24, 24, 1, 1, 6, 6, 6);
        cout << "PASS: No exception thrown for x/y + leangth being in bounds" << endl;
    } catch (exception &e) {
        cout << "FAIL: No exception thrown for x/y + leangth being in bounds" << endl;
    }

    try {
        pic.placeBox(0, 0, 25, 25, 6, 6, 6);
        cout << "PASS: No exception thrown for x/y + leangth being in bounds" << endl;
    } catch (exception &e) {
        cout << "FAIL: No exception thrown for x/y + leangth being in bounds" << endl;
    }

    try {
        pic.placeBox(0, 0, 26, 26, 6, 6, 6);
        cout << "FAIL: Exception should be thrown for x/y + leangth being out of bounds" << endl;
    } catch (exception &e) {
        cout << "PASS: Exception should be thrown for x/y + leangth being out of bounds" << endl;
    }
}

void testGetPixel() {
    cout << "*** TESTING GETPIXEL ***" << endl;
    map<char, int> pixel;
    Draw draw("tests/testImages/p3.ppm", 10, 10);

    try {
        pixel = draw.getPixel(0, 0);
        cout << "PASS: getPixel should return" << endl;
        if (pixel['r'] == 255 && pixel['g'] == 255 && pixel['b'] == 255) {
            cout << "PASS: Values returned correctly" << endl;
        } else {
            cout << "~~~ FAIL: Values did not come back as expected" << endl;
        }
    } catch (exception &e) {
        cout << "~~~ FAIL: getPixel shouldn't return exception" << endl;
    }

    try {
        pixel = draw.getPixel(-1, 0);
        cout << "~~~ FAIL: getPixel should throw exception for negative coordinate" << endl;
    } catch (exception &e) {
        cout << "PASS: getPixel should throw exception for negative coordinate" << endl;
    }

    try {
        pixel = draw.getPixel(10, 0);
        cout << "~~~ FAIL: getPixel should throw exception for out of bounds coorindate" << endl;
    } catch (exception &e) {
        cout << "PASS: getPixel should throw exception for out of bounds coorindate" << endl;
    }
    
}

int main(void) {
    cout << "Running Tests:" << endl;
    testDrawConstructor();
    testPlacePixel();
    testPlaceBox();
    testGetPixel();
}
