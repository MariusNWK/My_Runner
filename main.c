/*
** EPITECH PROJECT, 2020
** main
** File description:
** myrunner
*/
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void lines_settings(lines_t *line, int lines, int n)
{
    switch (lines) {
        case 1 : line->line1 += n;
            break;
        case 2 : line->line2 += n;
            break;
        case 3 : line->line3 += n;
            break;
        case 4 : line->line4 += n;
            break;
    }
}

int error_handling(int ac, char **av, char *str)
{
    lines_t line = {0, 0, 0, 0};
    int lines = 1;

    if (ac != 2 || getfilesize(av[1]) == 0)
        return (84);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != 'x' && str[i] != '\n')
            return (84);
        lines_settings(&line, lines, 1);
        if (str[i] == '\n') {
            lines_settings(&line, lines, -1);
            lines = lines + 1;
        }
    }
    if (lines != 4 || line.line1 != line.line2 || line.line1 != line.line3 ||
        line.line1 != line.line4) {
        return (84);
    }
    return (0);
}

char **set_lines(char *str)
{
    char **line;
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++);
    i = i - 1;
    line = malloc(sizeof(char *) * 4);
    for (int k = 0, n = 0; k < 4; k++) {
        line[k] = malloc(sizeof(char **) * i / 4 + 1);
        for (j = 0; j < i / 4; j++, n++) {
            line[k][j] = str[n];
        }
        line[k][j] = '\0';
        n = n + 1;
    }
    free(str);
    return (line);
}

int main(int ac, char **av)
{
    char **line;
    char *str = map_str(av[1]);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write(1, map_str("description.txt"), getfilesize("description.txt"));
        return (0);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'i')
        line = infinite();
    else { if (error_handling(ac, av, str) == 84) {
            free(str);
            write(2, "Invalid file or arguments\n", 26);
            return (84);
        }
        line = set_lines(str);
    }
    game(line);
    for (int i = 0; i < 4; i++)
        free(line[i]);
    free(line);
    return (0);
}
