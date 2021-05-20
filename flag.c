/*
** EPITECH PROJECT, 2021
** flag
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

int isflag(sfClock *gameclock, int len, int flag)
{
    sfTime time = sfClock_getElapsedTime(gameclock);
    int seconds = time.microseconds / 235000;

    if (seconds >= len) {
        return (1);
    }
    return (flag);
}

void move_flag(list_t *tools, float deltaseconds, int flag)
{
    struct game_object light = get_at(tools, 2);

    if (flag == 1) {
        light.pos.x = light.pos.x - 600 * deltaseconds;
        sfSprite_setPosition(light.sprite, light.pos);
        set_at(tools, light, 2);
    }
}