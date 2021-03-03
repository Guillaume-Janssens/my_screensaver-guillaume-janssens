/*
** EPITECH PROJECT, 2020
** screensaver
** File description:
** init of funct
*/

#include <stdlib.h>
#include "shapes.h"

circle_t *circle_init(unsigned int rayon, sfVector2i *pos, sfColor *color,
                      sfVector2i *speed)
{
    circle_t *elem = malloc(sizeof(circle_t));

    if (elem == NULL)
        return (NULL);
    elem->rayon = rayon;
    elem->pos = (sfVector2i){pos->x, pos->y};
    elem->color = (sfColor){color->r, color->g, color->b, color->a};
    elem->speed = (sfVector2i){speed->x, speed->y};
    elem->next = NULL;
    return (elem);
}

void circle_append(circle_t *begin, circle_t *elem)
{
    if (begin == NULL)
        return;
    while (begin->next != NULL) {
        begin = begin->next;
    }
    begin->next = elem;
}
