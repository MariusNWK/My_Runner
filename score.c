/*
** EPITECH PROJECT, 2021
** score
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

sfText *create_text(sfVector2f pos, char *str, sfColor color, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setColor(text, color);
    return (text);
}

int increase_score(sfText *dist, int jump, int nbr, sfClock *scoreclock)
{
    sfTime time = sfClock_getElapsedTime(scoreclock);
    float seconds = time.microseconds / 1000000.0;

    if (jump != 2 && jump != 3) {
        if (seconds > 0.01) {
            nbr = nbr + 1;
            sfClock_restart(scoreclock);
        }
    }
    return (nbr);
}