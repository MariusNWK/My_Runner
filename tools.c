/*
** EPITECH PROJECT, 2021
** tools
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

sfVector2f coords (float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfIntRect dimensions (int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfSprite *apply_settings(struct game_object *obj)
{
    obj->sprite = sfSprite_create();

    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setScale(obj->sprite, obj->scale);
    return (obj->sprite);
}

struct game_object create_object (const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
    struct game_object obj;

    obj.texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    obj.pos = pos;
    obj.rect = rect;
    obj.scale = scale;
    obj.sprite = apply_settings(&obj);
    return (obj);
}

struct game_object move_object(list_t *objects, float delta_seconds,
int pos, int speed)
{
    struct game_object obj = get_at(objects, pos);

    obj.pos.x = obj.pos.x - speed * delta_seconds;
    if (obj.pos.x <= -1920) {
        obj.pos.x = 1920;
    }
    sfSprite_setPosition(obj.sprite, obj.pos);
    return (obj);
}