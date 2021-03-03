/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** screensaver1
*/

#include "shapes.h"

void my_put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y,
                  sfColor color)
{
    sfColor *ptn = (sfColor *)fb->pixels;

    if (x > fb->width || y > fb->height)
        return;
    
    ptn[x + y * fb->width] = color;
        
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));
    fb->width = width;
    fb->height = height;
    fb->pixels = malloc(sizeof(uchar) * (height * width * 4));
    memset(fb->pixels, 0, fb->width * fb->height * 4);
    return (fb);
}

void first_scene(void)
{
    sfEvent event;
    sfRenderWindow *window;
    framebuffer_t *fb;
    sfSprite *sp;
    sfTexture *text;
    circle_t *sample = circle_init(120, &(sfVector2i){240, 240},
                                   &(sfColor){255, 255, 255, 255},
                                   &(sfVector2i){100, 100});
    sfClock *clock = sfClock_create();
    
    window = sfRenderWindow_create((sfVideoMode)
                                   {800, 600, 32}, "Guillaume's Window",
                                   sfResize | sfClose, NULL);
    fb = framebuffer_create(800, 600);
    sp = sfSprite_create();
    text = sfTexture_create(fb->width, fb->height);
    sfSprite_setTexture(sp, text, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 60);
    circles_create_list(4, sample);
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
        memset(fb->pixels, 0, fb->width * fb->height * 4);
        //draw
        draw_circle(sample, fb, sfTime_asSeconds
                    (sfClock_getElapsedTime(clock)));
        sfClock_restart(clock);
    }
}
int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    else {
        if (argv[1][0] == '1')
            first_scene();
        else if (argv[1][0] == '2')
            second_scene();
        return (0);
    }
}
