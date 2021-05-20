/*
** EPITECH PROJECT, 2020
** game
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

global_t create_global(char **line)
{
    global_t global;

    global.clock = create_clocks();
    global.sounds = create_sounds();
    global.scores = create_scores();
    global.group = create_group(line);
    global.status = create_status(global.group, line);
    return (global);
}

void play1(sfRenderWindow *window, sfEvent event, global_t *gb, char **line)
{
    parallax_scrolling(deltatime(gb->clock.deltaclock),
    gb->group.parallax_scrolling_objects);
    jump_sound(gb->sounds.sound, gb->group.runner_objects,
    gb->status.jump);
    gb->status.jump = move_runner(gb->group.runner_objects,
    gb->clock.speedmoveclock, gb->status.jump,
    gb->clock.jumpclock);
    jump_runner(deltatime(gb->clock.deltaclock),
    gb->group.runner_objects, gb->status.jump, gb->clock.jumpclock);
    gb->status.cross = set_obstacles(gb->status.cross,
    gb->group.obstacles, gb->clock.gameclock, line);
    move_obstacles(gb->group.obstacles,
    deltatime(gb->clock.deltaclock));
    gb->status.jump = collision_bloc(gb->group.obstacles,
    gb->group.runner_objects, gb->status.len, gb->status.jump);
    explosion(gb->group.runner_objects, gb->clock.explosionclock,
    gb->status.jump, deltatime(gb->clock.deltaclock));
    gb->status.nbr = increase_score(gb->scores.dist,
    gb->status.jump, gb->status.nbr, gb->clock.scoreclock);
    gb->status.flag = isflag(gb->clock.gameclock,
    my_strlen(line[0]), gb->status.flag);
}

void play2(sfRenderWindow *window, sfEvent event,
global_t *global, char **line)
{
    move_flag(global->group.tools, deltatime(global->clock.deltaclock),
    global->status.flag);
    display_sprites(window, global->group.parallax_scrolling_objects,
    global->group.runner_objects, global->status.jump);
    display_obstacles(window, global->group.obstacles,
    global->group.runner_objects, global->status.jump);
    display_game(window, global->group.tools, global->status.jump,
    global->status.flag);
    global->status.jump = display_victory(window, global->group.tools,
    global->group.runner_objects, global->status.jump);
    display_score(window, global->scores.score, global->scores.dist,
    global->status.nbr);
    sfClock_restart(global->clock.deltaclock);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void play(sfRenderWindow *window, sfEvent event, global_t *global, char **line)
{
    while (sfRenderWindow_pollEvent(window, &event))
        global->status.jump = analyse_events(window, event,
        global->status.jump);
    play1(window, event, global, line);
    play2(window, event, global, line);
}

void game (char **line)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "SFML windows",
    sfFullscreen, NULL);
    sfEvent event;
    global_t global = create_global(line);

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfMusic_play(global.sounds.music);
    while (sfRenderWindow_isOpen(window)) {
        play(window, event, &global, line);
    }
    clocks_destroyer(&global.clock);
    sounds_destroyer(&global.sounds);
    scores_destroyer(&global.scores);
    group_destroyer(&global.group);
    sfRenderWindow_destroy(window);
}