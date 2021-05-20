/*
** EPITECH PROJECT, 2021
** destroyer
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

void clocks_destroyer(clocks_t *clock)
{
    sfClock_destroy(clock->deltaclock);
    sfClock_destroy(clock->speedmoveclock);
    sfClock_destroy(clock->jumpclock);
    sfClock_destroy(clock->gameclock);
    sfClock_destroy(clock->explosionclock);
    sfClock_destroy(clock->scoreclock);
}

void sounds_destroyer(sounds_t *sounds)
{
    sfMusic_destroy(sounds->music);
    sfSound_destroy(sounds->sound);
    sfSoundBuffer_destroy(sounds->buffer);
}

void scores_destroyer(scores_t *scores)
{
    sfText_destroy(scores->score);
    sfText_destroy(scores->dist);
    sfFont_destroy(scores->font);
}

void group_destroyer(group_t *group)
{
    destroyer(group->parallax_scrolling_objects);
    destroyer(group->runner_objects);
    destroyer(group->obstacles);
    destroyer(group->tools);
}