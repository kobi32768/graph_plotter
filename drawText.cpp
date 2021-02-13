#pragma once

#include <string>
#include <GL/glut.h>

#include "font.h"
#include "globals.h"
#include "globals.cpp"
#include "utility.cpp"
#include "processing.cpp"

using namespace std;

void writeString(string text, int orig_x, int orig_y,
                 int size = 10, string origin = "lb") {

    // ----- positioning -----
    int box_w = ( text.size() - 1 ) * size; // space between chars
    int box_h = 7 * size;
    for (int i = 0; i < text.size(); ++i) {
        int index = text[i] - ' ';
        box_w += font_width[index] * size;
    }

    int offset_x = 0;
    int offset_y = 0;

    origin = tolower(origin);
    if (origin.size() <= 1) { // center
        offset_x = -box_w / 2;
        offset_y = -box_h / 2;
    }
    if (contain(origin, "l")) { // left
        offset_x = 0;
    }
    if (contain(origin, "r")) { // right
        offset_x = -box_w;
    }
    if (contain(origin, "b")) { // bottom
        offset_y = 0;
    }
    if (contain(origin, "t")) { // top
        offset_y = -box_h;
    }

    // ----- drawing -----
    glPointSize(size);
    glBegin(GL_POINTS);

    int move_x = 0;
    for (int i = 0; i < text.size(); ++i) {
        int index = int(text[i]) - ' ';
        if (index < 0 || 94 < index) {
            index = '_' - ' '; // replace under bar
        }

        // to dot along Y
        for (int y = 0; y < 8; ++y) {
            string binary = bitset<8>(font[index][y]).to_string();
            // to dot along X
            for (int x = 0; x < 5; ++x) {
                float coordinate_x = orig_x
                                     + (x + move_x ) * size
                                     + (size / 2.0) // because dot coordinate is the center
                                     + offset_x;

                float coordinate_y = orig_y
                                     + y * size
                                     - size // below the baseline
                                     + (size / 2)
                                     + offset_y;

                if (binary[x] == '1') {
                    glVertex2f(coordinate_x, coordinate_y);
                }
            }
        }

        //  +1 is space between chars.
        move_x += float(font_width[index]) + 1;
    }
    glEnd();
}
