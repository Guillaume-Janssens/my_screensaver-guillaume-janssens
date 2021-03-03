/*
** EPITECH PROJECT, 2020
** screensaver
** File description:
** file struc for shapes
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "framebuffer.h"
#include <math.h>
#include <time.h>

#ifndef SHAPES_H_
#define SHAPES_H_

typedef struct circle_s {
    int rayon;
    sfVector2i pos;
    sfColor color;
    sfVector2i speed;
    struct circle_s *next;
} circle_t;

typedef struct branch_s {
    int len;
    int thik;
    sfVector2i pos;
    sfColor color;
    struct branch_s *next;
} branch_t;

sfColor my_reset(branch_t *sample);
int draw_tree(branch_t *sample, framebuffer_t *fb, int y, int a);
branch_t *branch_init(unsigned int len, unsigned int thik, sfVector2i *pos, sfColor *color);
void branch_append(branch_t *begin, branch_t *elem);
void branch_create_list(int n, branch_t *sample);
int draw_tree(branch_t *sample, framebuffer_t *fb, int y, int a);
void second_scene(void);
void my_draw_square(framebuffer_t *fb, int x, int y, int w, int h, sfColor color);
void move_it(framebuffer_t *fb, int x, int y, int w, int h, sfColor color);
void bresenhamcircle(sfVector2i *pos, int r, framebuffer_t *fb, sfColor *color);
void my_put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor color);
void circles_create_list(int n, circle_t *sample);
void draw_circle(circle_t *sample, framebuffer_t *fb, float time);
circle_t *circle_init(unsigned int rayon, sfVector2i *pos, sfColor *color, sfVector2i *speed);
void circle_append(circle_t *begin, circle_t *elem);

#endif //SHAPES_H_
