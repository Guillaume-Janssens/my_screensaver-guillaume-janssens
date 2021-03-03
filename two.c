/*
** EPITECH PROJECT, 2020
** screensaver
** File description:
** second scene
*/

#include "shapes.h"
#include <time.h>

branch_t *branch_init(unsigned int len, unsigned int thik,
                      sfVector2i *pos, sfColor *color)
{
    branch_t *elem = malloc(sizeof(branch_t));

    if (elem == NULL)
        return (NULL);
    elem->len = len;
    elem->thik = thik;
    elem->pos = (sfVector2i){pos->x, pos->y};
    elem->color = (sfColor){color->r, color->g, color->b, color->a};
    elem->next = NULL;
    return (elem);
}

void branch_append(branch_t *begin, branch_t *elem)
{
    if (begin == NULL)
        return;
    while (begin->next != NULL) {
        begin = begin->next;
    }
    begin->next = elem;
}

void branch_create_list(int n, branch_t *sample)
{
    int i = 0;
    int j = 10;
    
    while (i < n) {
        branch_append(sample, branch_init(sample->len, sample->thik,
                                          &(sfVector2i){sample->pos.x,
                                                  sample->pos.y},
                                          &(sample->color)));
        i += 1;
    }
}

int draw_branch(branch_t *sample, framebuffer_t *fb,int y, int a, sfColor *color)
{
    int i = sample->len / 4;
    
    if (y <= 140) {
        sample->pos.y -= 1;
        my_put_pixel(fb, sample->pos.x + a, sample->pos.y, *color);
        my_put_pixel(fb, sample->pos.x + a - sample->len, sample->pos.y, *color);
        my_put_pixel(fb, sample->pos.x - a, sample->pos.y, *color);
        my_put_pixel(fb, sample->pos.x - a + sample->len, sample->pos.y, *color);
    }
    else {
        if (y <= 200) {
            my_put_pixel(fb,
                         sample->pos.x - a + (sample->len + (sample->len / 2))
                         , sample->pos.y, *color);
            my_put_pixel(fb,
                         sample->pos.x + a - (sample->len + (sample->len / 2))
                         , sample->pos.y, *color);
        }
        if (y <= 160) {
            my_put_pixel(fb,
                         sample->pos.x + a  - sample->len,
                         sample->pos.y, *color);
            my_put_pixel(fb,
                         sample->pos.x + a  - sample->len / 2,
                         sample->pos.y, *color);
            my_put_pixel(fb,
                         sample->pos.x - a + sample->len,
                         sample->pos.y, *color);
            my_put_pixel(fb,
                         sample->pos.x - a + sample->len / 2,
                         sample->pos.y, *color);     
        }
    }
    sample->pos.y -= 1;
    return (a);
}

void second_scene(void)
{
    srand (time(NULL));
    sfEvent event;
    sfRenderWindow *window;
    framebuffer_t *fb;
    sfSprite *sp;
    sfTexture *text;
    int z = 0;
    int y = 0;
    int a = 0;
    int i = rand() % 1920;
    branch_t *sample = branch_init(80, 3, &(sfVector2i){i, 600},
                                   &(sfColor){255, 255, 255, 255});
    int r = rand() % 255;
    int g = rand() % 255;
    int b = rand() % 255;
    sfColor *color = &(sfColor){r, g, b, 255};
    
    window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
                                   "Second Scene", sfResize | sfClose, NULL);
    fb = framebuffer_create(1920, 1080);
    sp = sfSprite_create();
    text = sfTexture_create(fb->width, fb->height);
    sfSprite_setTexture(sp, text, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 144);
    branch_create_list(0, sample);
    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
                return ;
            }
        }
        //UPDATE                                                                                     
        sfRenderWindow_clear(window, sfBlack);
        sfTexture_updateFromPixels(text, fb->pixels,
                                   fb->width, fb->height, 0, 0);
        sfRenderWindow_drawSprite(window, sp, NULL);
        sfRenderWindow_display(window);
        //draw
        a = draw_tree(sample, fb, y, a);
        if (y >= 120)
            a = draw_branch(sample, fb, y, a, color);
        y += 1;
        if (y == 250) {
            y = 0;
            a = 0;
            *color = my_reset(sample);
        }
        z += 1;
        if (z >= 6000) {
            memset(fb->pixels, 0, fb->width * fb->height * 4);
            z = 0;
        } 
    }
}
