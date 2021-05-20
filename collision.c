/*
** EPITECH PROJECT, 2021
** collision
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

int collision(list_t *obstacles, list_t *runner_objects, int p, int i)
{
    int len = len_list(obstacles);
    struct game_object bloc = get_at(obstacles, i);
    struct game_object jump = get_at(runner_objects, 1);
    struct game_object run = get_at(runner_objects, 0);

    if (jump.pos.y <= bloc.pos.y - 110 && jump.pos.y >= bloc.pos.y - 200 &&
        run.pos.x + 90 >= bloc.pos.x - 90 && run.pos.x <= bloc.pos.x + 142) {
        run.pos.y = bloc.pos.y - 175;
        p = 1;
    }
    else if (run.pos.y <= bloc.pos.y - 175 && run.pos.x > bloc.pos.x + 142 &&
        run.pos.x < bloc.pos.x + 200 && p == 0) {
        run.pos.y = run.pos.y + 142;
    }
    if (!(run.pos.x + 90 >= bloc.pos.x - 90 && run.pos.x <= bloc.pos.x + 142))
        run.blocs++;
    if (run.blocs == len)
        run.pos.y = 740;
    sfSprite_setPosition(run.sprite, run.pos);
    set_at(runner_objects, run, 0);
    return (p);
}

void set_explosion(struct game_object obj1,
struct game_object obj2, list_t *runner_objects)
{
    obj1.pos.x = obj2.pos.x - 50;
    obj1.pos.y = obj2.pos.y - 50;
    sfSprite_setPosition(obj1.sprite, obj1.pos);
    set_at(runner_objects, obj1, 2);
}

int isexplosion(list_t *obstacles, list_t *runner_objects, int isjump, int i)
{
    struct game_object bloc = get_at(obstacles, i);
    struct game_object jump = get_at(runner_objects, 1);
    struct game_object run = get_at(runner_objects, 0);
    struct game_object explosion = get_at(runner_objects, 2);

    if (isjump == 0) {
        if (run.pos.x >= bloc.pos.x - 140 && run.pos.x <= bloc.pos.x + 30 &&
            run.pos.y >= bloc.pos.y - 150 && run.pos.y <= bloc.pos.y + 100) {
            set_explosion(explosion, run, runner_objects);
            return (2);
        }
    }
    else if (isjump == 1) {
        if (jump.pos.x >= bloc.pos.x - 140 && jump.pos.x <= bloc.pos.x + 30 &&
            jump.pos.y >= bloc.pos.y - 100 && jump.pos.y <= bloc.pos.y + 100) {
            set_explosion(explosion, jump, runner_objects);
            return (2);
        }
    }
    return (0);
}

int collision_bloc(list_t *obstacles, list_t *runner_objects,
int len, int isjump)
{
    struct game_object run = get_at(runner_objects, 0);

    run.blocs = 0;
    set_at(runner_objects, run, 0);
    for (int i = 0, p = 0; i < len; i++) {
        p = collision(obstacles, runner_objects, p, i);
        if (isexplosion(obstacles, runner_objects, isjump, i) == 2) {
            return (2);
        }
    }
    return (isjump);
}

void explosion(list_t *objects, sfClock *explosionclock,
int jump, float deltaseconds)
{
    struct game_object explosion = get_at(objects, 2);
    sfTime time = sfClock_getElapsedTime(explosionclock);
    float seconds = time.microseconds / 1000000.0;

    if (jump == 2) {
        explosion.pos.x = explosion.pos.x - 600 * deltaseconds;
        sfSprite_setPosition(explosion.sprite, explosion.pos);
        set_at(objects, explosion, 2);
        if (seconds > 0.01) {
            move_rect(objects, 256, 256 * 8);
            sfClock_restart(explosionclock);
        }
    }
}