/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *int_to_str_converter_two(int size_boucles, int neg,
    unsigned long fois_dix, int b)
{
    char *boucles;
    int i = 0;

    boucles = malloc(sizeof(char) * (size_boucles + 1) + neg);
    if (neg == 1)
        boucles[0] = '-';
    fois_dix = fois_dix / 10;
    while (fois_dix > 0) {
        boucles[i + neg] = (b / fois_dix) + 48;
        b = b % fois_dix;
        i++;
        fois_dix = fois_dix / 10;
    }
    boucles[i + neg] = '\0';
    return (boucles);
}

char *int_to_str_converter(int b)
{
    unsigned long fois_dix = 1;
    int b_bis = 0;
    int size_boucles = 0;
    int neg = 0;
    char *zero = malloc(sizeof(char) * 2);

    if (b == 0) {
        zero[0] = '0';
        zero[1] = '\0';
        return (zero);
    } free(zero);
    if (b < 0) { b = b * (-1);
        neg = neg + 1;
    }
    b_bis = b;
    while (b_bis > 0) {
        b_bis = b_bis / 10;
        fois_dix = fois_dix * 10;
        size_boucles++;
    }
    return (int_to_str_converter_two(size_boucles, neg, fois_dix, b));
}
