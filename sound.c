/*
** EPITECH PROJECT, 2021
** sound
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

void jump_sound(sfSound *sound, list_t *objects, int isjump)
{
    struct game_object run = get_at(objects, 0);
    struct game_object jump = get_at(objects, 1);

    if (isjump == 1) {
        if (run.pos.y == jump.pos.y) {
            sfSound_play(sound);
        }
    }
}

sfSound *create_sound(sfSoundBuffer *buffer)
{
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    return (sound);
}