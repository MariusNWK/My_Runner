/*
** EPITECH PROJECT, 2021
** obstacles
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdio.h>

list_t *create_obstacle(list_t *obstacles, int y, sfColor Color)
{
    struct game_object obj = create_object("./images/bloc.png", coords(1930, y),
    dimensions(0, 0, 142, 142), coords(1, 1));

    sfSprite_setColor(obj.sprite, Color);
    obstacles = add_at(obstacles, obj, 0);
    return (obstacles);
}

list_t *list_of_obstacles(char **line)
{
    list_t *obstacles = NULL;
    int len1 = my_strlen(line[0]);

    for (int i = 0; i < len1; i++) {
        if (line[0][i] == 'x') {
            obstacles = create_obstacle(obstacles, 349, sfMagenta);
        }
        if (line[1][i] == 'x') {
            obstacles = create_obstacle(obstacles, 491, sfBlue);
        }
        if (line[2][i] == 'x') {
            obstacles = create_obstacle(obstacles, 633, sfCyan);
        }
        if (line[3][i] == 'x') {
            obstacles = create_obstacle(obstacles, 775, sfWhite);
        }
    }
    return (obstacles);
}

int check_cross(int cross, list_t *obstacles)
{
    struct game_object obj;

    obj = get_at(obstacles, cross - 1);
    obj.pos.x = 1925;
    sfSprite_setPosition(obj.sprite, obj.pos);
    set_at(obstacles, obj, cross - 1);
    cross = cross - 1;
    return (cross);
}

void condition_obstacles(int pos, char **line, bag_t *bag, list_t *obstacles)
{
    if (line[pos][bag->seconds] == 'x') {
        line[pos][bag->seconds] = 'o';
        bag->cross = check_cross(bag->cross, obstacles);
    }
}

int set_obstacles(int cross, list_t *obstacles,
sfClock *gameclock, char **line)
{
    bag_t bag;
    int len = my_strlen(line[0]);
    sfTime time = sfClock_getElapsedTime(gameclock);
    bag.seconds = time.microseconds / 235000;
    bag.cross = cross;

    if (bag.seconds > len - 1)
        bag.seconds = len - 1;
    condition_obstacles(0, line, &bag, obstacles);
    condition_obstacles(1, line, &bag, obstacles);
    condition_obstacles(2, line, &bag, obstacles);
    condition_obstacles(3, line, &bag, obstacles);
    return (bag.cross);
}