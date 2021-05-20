/*
** EPITECH PROJECT, 2021
** analyse_events
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

int analyse_events(sfRenderWindow *window, sfEvent event, int jump)
{
    sfKeyEvent key;

    if (event.key.code == sfKeyQ) {
        sfRenderWindow_close(window);
    }
    if (event.key.code == sfKeySpace && jump == 0) {
        return (1);
    }
    return (jump);
}