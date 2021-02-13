#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "globals.h"
#include "globals.cpp"
#include "display.cpp"

void init() {
    glClearColor(1, 1, 1, 1);

    // center (0, 0)
    glOrtho(X_MIN, X_MAX, Y_MIN, Y_MAX, -1, 1);
}

void resize(int width, int height) {
    glutReshapeWindow(WIDTH, HEIGHT);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(480, 270);
    glutInitWindowSize(WIDTH, HEIGHT);

    glutCreateWindow("Graph Plotter");
    glutDisplayFunc(display);
//    glutReshapeFunc(resize);
    init();
    glutMainLoop();

    return 0;
}
