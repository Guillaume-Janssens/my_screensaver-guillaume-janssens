/*
** EPITECH PROJECT, 2020
** framebuffer.h
** File description:
** 
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

typedef unsigned char uchar;

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    uchar *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);
#endif
