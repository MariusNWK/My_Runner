/*
** EPITECH PROJECT, 2021
** runner
** File description:
** myrunner
*/
#include "my.h"

list_t *list_of_runner_objects(void)
{
    list_t *list = NULL;
    struct game_object run = create_object("./images/runner.png",
    coords(830, 740), dimensions(0, 0, 90, 101), coords(1.8, 1.8));
    struct game_object jump = create_object("./images/runner.png",
    coords(830, 740), dimensions(0, 160, 90, 110), coords(1.8, 1.8));
    struct game_object explosion = create_object("./images/explosion.png",
    coords(0, 0), dimensions(0, 0, 256, 256), coords(1, 1));

    list = add_at(list, run, 0);
    list = add_at(list, jump, 1);
    list = add_at(list, explosion, 2);
    return (list);
}