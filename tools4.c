/*
** EPITECH PROJECT, 2021
** tools4
** File description:
** myrunner
*/
#include <time.h>
#include <stdlib.h>

char randomchar(void)
{
    int alea = 0;

    alea = rand() % 50 + 1;
    if (alea == 1) {
        return ('x');
    }
    else {
        return ('.');
    }
}

char **infinite(void)
{
    char **line = malloc(sizeof(char *) * 4);

    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        line[i] = malloc(sizeof(char **) * 2000);
        for (int j = 0; j < 2000; j++) {
            line[i][j] = randomchar();
        }
    }
    return (line);
}