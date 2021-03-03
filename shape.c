/*
** EPITECH PROJECT, 2020
** shape
** File description:
** displays a shape
*/

#include "shapes.h"

void circles_create_list(int n, circle_t *sample)
{
    int i = 0;

    while (i < n) {
        circle_append(sample, circle_init(sample->rayon / (i + 2), &(sfVector2i)
                                          {sample->pos.x + (i + 1) *
                                                  (sample->rayon * 2),
                        sample->pos.y + (i + 1) * (sample->rayon * 2)},
                                          &(sample->color), &(sample->speed)));
        i += 1;
    }
}

void bresenhamcircle(sfVector2i *pos, int r, framebuffer_t *fb, sfColor *color)
{
    int x, y, p;
    while (r > 0) {
        x = 0;
        y = r;

        my_put_pixel(fb, pos->x + x, pos->y - y, *color);

        p = 3 - (2 * r);

        for(x = 0; x <= y; x++)
        {
            if (p < 0)
            {
                p = (p + (4 * x) + 6);
            }
            else
            {
                y -= 1;
                p += ((4 * (x - y) + 10));
            }
        
            my_put_pixel(fb, pos->x + x, pos->y - y, *color);
            my_put_pixel(fb, pos->x - x, pos->y - y, *color);
            my_put_pixel(fb, pos->x + x, pos->y + y, *color);
            my_put_pixel(fb, pos->x - x, pos->y + y, *color);
            my_put_pixel(fb, pos->x + y, pos->y - x, *color);
            my_put_pixel(fb, pos->x - y, pos->y - x, *color);
            my_put_pixel(fb, pos->x + y, pos->y + x, *color);
            my_put_pixel(fb, pos->x - y, pos->y + x, *color);
        }
        r -= 1;
    }
}

void my_collision(circle_t *begin)
{
    circle_t *tmp = begin;
    circle_t *cmp;
    float dx = 0;
    float dy = 0;
    float b = 0;
    int len = 0;
    int susx;
    int susy;

    while (begin != NULL) {
        cmp = tmp;
        while (cmp != NULL) {
            dx = cmp->pos.x - begin->pos.x;
            dy = cmp->pos.y - begin->pos.y;
            if (cmp != begin && sqrt(pow(abs(dx), 2) + pow(abs(dy), 2))
                <= cmp->rayon + begin->rayon) {
                susx = cmp->speed.x;
                susy = cmp->speed.y;
                cmp->speed.x = begin->speed.x;
                cmp->speed.y = begin->speed.y;
                begin->speed.x = susx;
                begin->speed.y = susy;            
            }
            cmp = cmp->next;
        }
        begin = begin->next;
    }
}

void draw_circle(circle_t *sample, framebuffer_t *fb, float time)
{
    while (sample != NULL) {
        sample->pos.x += time * sample->speed.x;
        sample->pos.y += time * sample->speed.y;
        if ((sample->pos.x + sample->rayon >
             fb->width && sample->speed.x > 0) ||
            (sample->pos.x - sample->rayon < 1 && sample->speed.x < 0)) {
            sample->speed.x *= -1;
            sample->pos.x = (sample->pos.x < fb->width/2 ?
                             sample->rayon : fb->width - sample->rayon - 1);
        }
        if ((sample->pos.y + sample->rayon >
             fb->height && sample->speed.y > 0) ||
            (sample->pos.y - sample->rayon < 1 && sample->speed.y < 0)) {
            sample->speed.y *= -1;
            sample->pos.y = (sample->pos.y < fb->height/2 ?
                             sample->rayon : fb->height - sample->rayon - 1);
        }
        bresenhamcircle(&(sample->pos), sample->rayon, fb, &(sample->color));
        sample = sample->next;
    }
}
