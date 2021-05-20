/*
** EPITECH PROJECT, 2021
** creator
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"

clocks_t create_clocks(void)
{
    clocks_t clock;

    clock.deltaclock = sfClock_create();
    clock.speedmoveclock = sfClock_create();
    clock.jumpclock = sfClock_create();
    clock.gameclock = sfClock_create();
    clock.explosionclock = sfClock_create();
    clock.scoreclock = sfClock_create();
    return (clock);
}

sounds_t create_sounds(void)
{
    sounds_t sounds;

    sounds.music = sfMusic_createFromFile("./sounds/music.ogg");
    sounds.buffer = sfSoundBuffer_createFromFile("./sounds/jumpsound.ogg");
    sounds.sound = create_sound(sounds.buffer);
    return (sounds);
}

scores_t create_scores(void)
{
    scores_t scores;

    scores.font = sfFont_createFromFile("./images/college.ttf");
    scores.score = create_text(coords(850, 1000), "SCORE :",
    sfWhite, scores.font);
    scores.dist = create_text(coords(955, 1000), "0", sfYellow, scores.font);
    return (scores);
}

status_t create_status(group_t group, char **line)
{
    status_t status;

    status.cross = cross_counter(line);
    status.len = len_list(group.obstacles);
    status.jump = 0;
    status.nbr = 0;
    status.flag = 0;
    return (status);
}

group_t create_group(char **line)
{
    group_t group;

    group.parallax_scrolling_objects = list_of_parallax_scrolling_objects();
    group.runner_objects = list_of_runner_objects();
    group.obstacles = list_of_obstacles(line);
    group.tools = tools_list();
    return (group);
}