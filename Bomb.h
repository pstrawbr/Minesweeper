#ifndef PS_JV_GRAPHICS_FINAL_BOMB_H
#define PS_JV_GRAPHICS_FINAL_BOMB_H

#include "Tile.h"

#include <string>

class Bomb : public Tile {
public:
    Bomb() {
        adj_bombs = -1;
        int temp = column;
        if (row % 2 == 0) {
            ++temp;
        }
        if (temp % 2 == 1) {
            original_fill = {colors[LIGHT_BROWN].r, colors[LIGHT_BROWN].g,colors[LIGHT_BROWN].b};
            current_fill = {colors[LIGHT_BROWN].r, colors[LIGHT_BROWN].g,colors[LIGHT_BROWN].b};

        } else {
            original_fill = {colors[DARK_BROWN].r, colors[DARK_BROWN].g,colors[DARK_BROWN].b};
            current_fill = {colors[DARK_BROWN].r, colors[DARK_BROWN].g,colors[DARK_BROWN].b};
        }
    }

    string tile_display() override {
        return "B";
    }

   void draw() const override {
        glColor3f(current_fill.r, current_fill.g, current_fill.b);
        glBegin(GL_QUADS);
        glVertex2i(x1, y1);
        glVertex2i(x2, y1);
        glVertex2i(x2, y2);
        glVertex2i(x1, y2);
        glEnd();


        // TODO: Draw Bomb here
        unsigned char filler[] = "10";
        int num = 10;
        glColor3f(colors[SEVEN].r, colors[SEVEN].g, colors[SEVEN].b);
        glRasterPos2i(x1 + (0.5 * (x2 - x1)) - (0.5 * glutBitmapLength(GLUT_BITMAP_HELVETICA_18, filler)),
                     y1 + (0.5 * (y2 - y1)) + (0.75 * glutBitmapLength(GLUT_BITMAP_HELVETICA_18, filler)));
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, reinterpret_cast<int>('0' + num));
        glEnd();
   }
};

#endif //PS_JV_GRAPHICS_FINAL_BOMB_H
