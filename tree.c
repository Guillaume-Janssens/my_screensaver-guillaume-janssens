/*
** EPITECH PROJECT, 2020
** screensaver
** File description:
** draw tree.c
*/

#include "shapes.h"

int draw_tree(branch_t *sample, framebuffer_t *fb, int y, int a)
{
    int i = sample->len / 2;
    sfColor *color = &(sample->color);
    if (y <= sample->len) {
        my_put_pixel(fb, sample->pos.x, sample->pos.y, *color);
    }
    else {
        a += 1;
        if (y <= 140) {
            my_put_pixel(fb, sample->pos.x + a, sample->pos.y, *color);
            my_put_pixel(fb, sample->pos.x - a, sample->pos.y, *color);
        }
    }
    sample->pos.y -= 1;
    return (a);
}

sfColor my_reset(branch_t *sample)
{
    srand (time(NULL));
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;
    sample->pos.x = rand() % 1920;
    sample->pos.y = 600;
    sfColor *color = &(sfColor){r, g, b, 255};
    return (*color);
}
