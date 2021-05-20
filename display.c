/*
** EPITECH PROJECT, 2021
** display
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdlib.h>

void display_sprites(sfRenderWindow *window, list_t *list1,
list_t *list2, int jump)
{
    sfRenderWindow_drawSprite(window, get_at(list1, 2).sprite, NULL);
    sfRenderWindow_drawSprite(window, get_at(list1, 5).sprite, NULL);
    sfRenderWindow_drawSprite(window, get_at(list1, 6).sprite, NULL);
    sfRenderWindow_drawSprite(window, get_at(list1, 0).sprite, NULL);
    sfRenderWindow_drawSprite(window, get_at(list1, 1).sprite, NULL);
    sfRenderWindow_drawSprite(window, get_at(list1, 3).sprite, NULL);
    sfRenderWindow_drawSprite(window, get_at(list1, 4).sprite, NULL);
    if (jump == 0) {
        sfRenderWindow_drawSprite(window, get_at(list2, 0).sprite, NULL);
    }
    else if (jump == 1) {
        sfRenderWindow_drawSprite(window, get_at(list2, 1).sprite, NULL);
    }
}

void display_obstacles(sfRenderWindow *window, list_t *obstacles,
list_t *runner_objects, int jump)
{
    int len = len_list(obstacles);

    for (int i = 0; i < len; i++) {
        sfRenderWindow_drawSprite(window,
        get_at(obstacles, i).sprite, NULL);
    }
    if (jump == 2) {
        sfRenderWindow_drawSprite(window,
        get_at(runner_objects, 2).sprite, NULL);
    }
}

void display_score(sfRenderWindow *window, sfText *score,
sfText *dist, int nbr)
{
    char *str = int_to_str_converter(nbr);
    sfText_setString(dist, str);
    sfRenderWindow_drawText(window, score, NULL);
    sfRenderWindow_drawText(window, dist, NULL);
    free(str);
}

void display_game(sfRenderWindow *window, list_t *tools, int jump, int flag)
{
    if (jump == 2) {
        sfRenderWindow_drawSprite(window, get_at(tools, 0).sprite, NULL);
    }
    if (flag == 1) {
        sfRenderWindow_drawSprite(window, get_at(tools, 2).sprite, NULL);
    }
}

int display_victory(sfRenderWindow *window, list_t *tools,
list_t *objects, int jump)
{
    struct game_object light = get_at(tools, 2);
    struct game_object run = get_at(objects, 0);

    if (run.pos.x >= light.pos.x && jump != 2) {
        sfRenderWindow_drawSprite(window, get_at(tools, 1).sprite, NULL);
        return (3);
    }
    return (jump);
}