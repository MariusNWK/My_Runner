/*
** EPITECH PROJECT, 2021
** tools2
** File description:
** myrunner
*/
#include "my.h"

void destroyer(list_t *list)
{
    int len = len_list(list);
    struct game_object object;

    for (int i = 0; i < len; i++) {
        object = get_at(list, i);
        sfSprite_destroy(object.sprite);
        sfTexture_destroy(object.texture);
    }
    free_list(list);
}

float deltatime(sfClock *deltaclock)
{
    sfTime dt;
    float delta_seconds = 0;

    dt = sfClock_getElapsedTime(deltaclock);
    delta_seconds = dt.microseconds / 1000000.0;
    return (delta_seconds);
}

struct game_object animation_object(list_t *objects, int pos, int add_left)
{
    struct game_object obj = get_at(objects, pos);

    obj.rect.left = obj.rect.left + add_left;
    if (obj.rect.left > 500) {
        obj.rect.left = 0;
    }
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    return (obj);
}

struct game_object set_rect(list_t *objects, int pos, int left)
{
    struct game_object obj = get_at(objects, pos);

    obj.rect.left = left;
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    return (obj);
}