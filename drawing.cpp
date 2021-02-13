#pragma once

#include <string>
#include <filesystem>
#include <cmath>
#include <bitset>
#include <GL/glut.h>
#include <GL/glu.h>
#include <FTGL/ftgl.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "globals.h"
#include "globals.cpp"
#include "font.h"
#include "processing.cpp"
#include "utility.cpp"


#pragma comment (lib, "ftgl.lib")

using namespace std;

void circle(int x, int y, int radius) {
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    double progress = 0;
    while (progress < M_PI*2) {
        glVertex2d(x + sin(progress)*radius,
                   y + cos(progress)*radius);
        progress +=  M_PI/180;
    }
    glEnd();
}

void scale(int pitch) {
    glLineWidth(1);
    glBegin(GL_LINES);

    // ----- lattice -----
    glColor4f(0.75, 0.75, 0.75, 0.5);

    for (int y = -HEIGHT/pitch; y <= HEIGHT/pitch; ++y) { // horizontal
        glVertex2d(X_MIN, y * pitch);
        glVertex2d(X_MAX, y * pitch);
    }

    for (int x = -WIDTH/pitch; x <= WIDTH/pitch; ++x) { // vertical
        glVertex2d(x*pitch, Y_MIN);
        glVertex2d(x*pitch, Y_MAX);
    }

    // ----- axis -----
    glColor4f(0, 0, 0, 0.5);

    glVertex2d(X_MIN, 0); // X
    glVertex2d(X_MAX, 0);

    glVertex2d(0, Y_MIN); // Y
    glVertex2d(0, Y_MAX);

    // ----- axis arrowhead -----
    glLineWidth(2);

    glVertex2d(X_MAX, 0);
    glVertex2d(X_MAX - sqrt(3) * 10, 10);

    glVertex2d(X_MAX, 0);
    glVertex2d(X_MAX - sqrt(3) * 10, -10);

    glVertex2d(0, Y_MAX);
    glVertex2d(10, Y_MAX - sqrt(3) * 10);

    glVertex2d(0, Y_MAX);
    glVertex2d(-10, Y_MAX - sqrt(3) * 10);


    glEnd();
}
