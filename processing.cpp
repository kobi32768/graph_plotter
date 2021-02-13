#pragma once

void enableSmooth() {
    glEnable(GL_LINE_SMOOTH);
}

void disableSmoothing() {
    glDisable(GL_LINE_SMOOTH);
}

void enableBlend() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
}

void disableBlend() {
    glDisable(GL_BLEND);
}

void enableAntialias() {
    enableSmooth();
    enableBlend();
}

void disableAntialias() {
    disableSmoothing();
}
