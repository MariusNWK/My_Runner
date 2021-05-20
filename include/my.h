/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** myrunner
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

void game(char **);

struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    int blocs;
};

//////////////////////////////////////////////////////

typedef struct Cell
{
    struct game_object data;
    struct Cell *next;
} list_t, cell_t;

list_t *empty_list(void);
int is_empty_list(list_t *);
long len_list(list_t *);
list_t *add_at(list_t *, struct game_object, int);
struct game_object get_at(list_t *, int);
void set_at(list_t *, struct game_object, int);
list_t *free_at(list_t *, int);
list_t *free_list(list_t *);
void print_list(list_t *);

//////////////////////////////////////////////////////

typedef struct clocks
{
    sfClock *deltaclock;
    sfClock *speedmoveclock;
    sfClock *jumpclock;
    sfClock *gameclock;
    sfClock *explosionclock;
    sfClock *scoreclock;
} clocks_t;

//////////////////////////////////////////////////////

typedef struct sounds
{
    sfMusic *music;
    sfSoundBuffer *buffer;
    sfSound *sound;
} sounds_t;

//////////////////////////////////////////////////////

typedef struct scores
{
    sfFont *font;
    sfText *score;
    sfText *dist;
} scores_t;

//////////////////////////////////////////////////////

typedef struct status
{
    int cross;
    int len;
    int jump;
    int nbr;
    int flag;
} status_t;

//////////////////////////////////////////////////////

typedef struct group
{
    list_t *parallax_scrolling_objects;
    list_t *runner_objects;
    list_t *obstacles;
    list_t *tools;
} group_t;

//////////////////////////////////////////////////////

typedef struct global
{
    clocks_t clock;
    sounds_t sounds;
    scores_t scores;
    group_t group;
    status_t status;
} global_t;

//////////////////////////////////////////////////////

typedef struct lines
{
    int line1;
    int line2;
    int line3;
    int line4;
} lines_t;

//////////////////////////////////////////////////////

typedef struct bag
{
    int seconds;
    int cross;
} bag_t;

//////////////////////////////////////////////////////

char *int_to_str_converter(int);
int analyse_events(sfRenderWindow *, sfEvent, int);
list_t *list_of_parallax_scrolling_objects(void);
list_t *list_of_runner_objects(void);
void parallax_scrolling(float, list_t *);
void destroyer(list_t *);
float deltatime(sfClock *);
struct game_object animation_object(list_t *, int, int);
struct game_object set_rect(list_t *, int, int);
sfVector2f coords(float, float);
sfIntRect dimensions(int, int, int, int);
sfSprite *apply_settings(struct game_object *);
struct game_object create_object (const char *, sfVector2f, sfIntRect, sfVector2f);
struct game_object move_object (list_t *, float, int, int);
int move_runner(list_t *, sfClock *, int, sfClock *);
void display_sprites(sfRenderWindow *, list_t *, list_t *, int);
void display_obstacles(sfRenderWindow *, list_t *, list_t *, int);
void display_score(sfRenderWindow *, sfText *, sfText *, int);
void display_game(sfRenderWindow *, list_t *, int, int);
int display_victory(sfRenderWindow *, list_t *, list_t *, int);
void jump_runner(float, list_t *, int, sfClock *);
list_t *list_of_obstacles(char **);
int set_obstacles(int, list_t *, sfClock *, char **);
void move_obstacles(list_t *, float);
int my_strlen(char *);
int cross_counter(char **);
void move_rect(list_t *, int, int);
int collisionn(list_t *, list_t *, int, int);
void set_explosion(struct game_object, struct game_object, list_t *);
int isexplosion(list_t *, list_t *, int, int);
int collision_bloc(list_t *, list_t *, int, int);
void explosion(list_t *, sfClock *, int, float);
sfText *create_text(sfVector2f, char *, sfColor, sfFont *);
int increase_score(sfText *, int, int, sfClock *);
list_t *tools_list(void);
char randomchar(void);
char **infinite(void);
int isflag(sfClock *, int, int);
void move_flag(list_t *, float, int);
void jump_sound(sfSound *, list_t *, int);
sfSound *create_sound(sfSoundBuffer *);
clocks_t create_clocks(void);
sounds_t create_sounds(void);
scores_t create_scores(void);
status_t create_status(group_t, char **);
group_t create_group(char **);
void clocks_destroyer(clocks_t *);
void sounds_destroyer(sounds_t *);
void scores_destroyer(scores_t *);
void group_destroyer(group_t *);
size_t getfilesize(char const *);
char *map_str(char const *);
void move_obstacles(list_t *, float);