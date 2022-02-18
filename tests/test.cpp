#include <iostream>
#include <string>
#include <map>
#include "../draw.h"

using namespace std;

int testDrawConstructor() {
    return 1;
}

int testPlacePixel() {
    return 1;
}

int testPlaceBox() {
    return 1;
}

int testGetPixel() {
    return 1;
}

int main(void) {
    cout << "Tests Suite Runs:" << endl;
    testDrawConstructor();
    testPlacePixel();
    testPlaceBox();
    testGetPixel();
}