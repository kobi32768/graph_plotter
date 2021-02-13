#pragma once

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <random>
#include <chrono>
#include <windows.h>

#include "globals.h"
#include "drawing.cpp"
#include "processing.cpp"
#include "drawText.cpp"

using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    enableAntialias();
    glColor3f(1, 0.75, 0);
    circle(0, 0, 200);

    glLineWidth(2);
    float size = 80;

    glColor3f(1, 0, 0);
    glBegin(GL_LINE_STRIP);
    double x1 = X_MIN;
    while (x1 < X_MAX) {
        double y = sin(x1 / size) * size;
        glVertex2d(x1, y);

        x1++;
    }
    glEnd();

    glColor3f(0, 0.5, 1);
    glBegin(GL_LINE_STRIP);
    double x2 = X_MIN;
    while (x2 < X_MAX) {
        double y = cos(x2 / size) * size;
        glVertex2d(x2, y);

        x2 += 10;
    }
    glEnd();

    int pitch = 20;
    int space = 2;
    int times = 450 / pitch;

    glColor3f(0, 0, 0);
    disableAntialias();
    enableBlend();
    scale(pitch);

    glColor3f(0, 0, 0);
    writeString("x", X_MAX-5, -15, 2, "tr");
    writeString("y", 15, Y_MAX-5, 2, "tl");
    writeString("O", -5, -5, 2, "tr");

    glColor4f(0.1, 0.1, 0.1, 0.75);
    int digit = 3;
    for (int x = -times; x <= times; x += space) {
        if (x == 0) continue;
        string label = to_string( (x * pitch) / size ).substr(0, digit);;
        writeString(label, x * pitch, -5, 1, "t");
    }

    for (int y = -times; y <= times; y += space) {
        if (y == 0) continue;
        string label = to_string( (y * pitch) / size ).substr(0, digit);
        writeString(label, -5, y * pitch, 1, "r");
    }

    glFlush();
}
