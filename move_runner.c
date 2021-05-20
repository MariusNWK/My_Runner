/*
** EPITECH PROJECT, 2021
** move_runner
** File description:
** myrunner
*/
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

int up_or_down(float seconds, list_t *objects)
{
    struct game_object obj = get_at(objects, 1);

    if (seconds > 0.5) {
        set_at(objects, set_rect(objects, 1, 80), 1);
        if (obj.pos.y >= get_at(objects, 0).pos.y) {
            return (0);
        }
    }
    else {
        set_at(objects, set_rect(objects, 1, 0), 1);
    }
    return (1);
}

int restarter(sfClock *jumpclock, list_t *objects, int jump)
{
    struct game_object obj = get_at(objects, 1);

    sfClock_restart(jumpclock);
    obj.pos.y = get_at(objects, 0).pos.y;
    obj.rect.left = 0;
    set_at(objects, obj, 1);
    return (jump);
}

int move_runner(list_t *objects, sfClock *clock, int jump, sfClock *jumpclock)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        set_at(objects, animation_object(objects, 0, 84), 0);
        sfClock_restart(clock);
    }
    time = sfClock_getElapsedTime(jumpclock);
    seconds = time.microseconds / 1000000.0;
    if (jump == 1) {
        return (up_or_down(seconds, objects));
    }
    else {
        return (restarter(jumpclock, objects, jump));
    }
}

void jump_runner(float deltaseconds, list_t *objects, int jump,
sfClock *jumpclock)
{
    struct game_object obj = get_at(objects, 1);
    struct game_object run = get_at(objects, 0);
    sfTime time = sfClock_getElapsedTime(jumpclock);
    float seconds = time.microseconds / 1000000.0;

    if (jump == 1 && obj.rect.left == 0) {
        obj.pos.y = obj.pos.y - (0.5 - seconds) * 3000.0 * deltaseconds;
    }
    else if (jump == 1 && obj.rect.left == 80) {
        obj.pos.y = obj.pos.y + (seconds - 0.5) * 3000.0 * deltaseconds;
    }
    sfSprite_setPosition(obj.sprite, obj.pos);
    set_at(objects, obj, 1);
}