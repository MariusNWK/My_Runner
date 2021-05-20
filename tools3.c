/*
** EPITECH PROJECT, 2021
** tools3
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int cross_counter(char **line)
{
    int cross = 0;

    for (int i = 0; line[0][i] != '\0'; i++) {
        if (line[0][i] == 'x') {
            cross = cross + 1;
        }
        if (line[1][i] == 'x') {
            cross = cross + 1;
        }
        if (line[2][i] == 'x') {
            cross = cross + 1;
        }
        if (line[3][i] == 'x') {
            cross = cross + 1;
        }
    }
    return (cross);
}

void move_rect(list_t *objects, int addleft, int limit)
{
    struct game_object explosion = get_at(objects, 2);

    explosion.rect.left = explosion.rect.left + addleft;
    if (explosion.rect.left >= limit) {
        explosion.rect.left = 0;
        explosion.rect.top = explosion.rect.top + 256;
    }
    sfSprite_setTextureRect(explosion.sprite, explosion.rect);
    set_at(objects, explosion, 2);
}

list_t *tools_list(void)
{
    list_t *list = NULL;
    struct game_object gameover = create_object("./images/gameover.png",
    coords(0, 0), dimensions(0, 0, 1920, 1080), coords(1, 1));
    struct game_object victory = create_object("./images/victory.png",
    coords(0, 0), dimensions(0, 0, 1920, 1080), coords(1, 1));
    struct game_object light = create_object("./images/lampadaire.png",
    coords(1930, 380), dimensions(0, 0, 829, 1800), coords(0.3, 0.3));

    sfSprite_setColor(light.sprite, sfGreen);
    list = add_at(list, gameover, 0);
    list = add_at(list, victory, 1);
    list = add_at(list, light, 2);
    return (list);
}

void move_obstacles(list_t *obstacles, float deltaseconds)
{
    int len = len_list(obstacles);
    int pos = 0;
    struct game_object obj;

    for (int i = 0; i < len; i++) {
        obj = get_at(obstacles, i);
        if (obj.pos.x != 1930) {
            obj.pos.x = obj.pos.x - 600 * deltaseconds;
            sfSprite_setPosition(obj.sprite, obj.pos);
            set_at(obstacles, obj, i);
        }
    }
}