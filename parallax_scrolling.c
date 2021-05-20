/*
** EPITECH PROJECT, 2021
** parallax_scrolling
** File description:
** myrunner
*/
#include "my.h"

list_t *list_of_parallax_scrolling_objects(void)
{
    list_t *list = NULL;

    list = add_at(list, create_object("./images/city.png", coords(0, 0),
    dimensions(0, 0, 1920, 960), coords(1, 1)), 0);
    list = add_at(list, create_object("./images/rcity.png", coords(1920, 0),
    dimensions(0, 0, 1920, 960), coords(1, 1)), 1);
    list = add_at(list, create_object("./images/moon.jpg", coords (0, 0),
    dimensions(0, 0, 1920, 1080), coords(1, 1)), 2);
    list = add_at(list, create_object("./images/barriers.png", coords(0, 0),
    dimensions(0, 0, 1920, 1080), coords(1, 1)), 3);
    list = add_at(list, create_object("./images/barriers.png", coords(1920, 0),
    dimensions(0, 0, 1920, 1080), coords(1, 1)), 4);
    list = add_at(list, create_object("./images/clouds.png", coords(0, -100),
    dimensions(0, 0, 1920, 724), coords(1, 1)), 5);
    list = add_at(list, create_object("./images/clouds.png",
    coords(1920, -100), dimensions(0, 0, 1920, 724), coords(1, 1)), 6);
    return (list);
}

void parallax_scrolling(float deltaseconds, list_t *objects)
{
    set_at(objects, move_object(objects, deltaseconds, 0, 80), 0);
    set_at(objects, move_object(objects, deltaseconds, 1, 80), 1);
    set_at(objects, move_object(objects, deltaseconds, 3, 600), 3);
    set_at(objects, move_object(objects, deltaseconds, 4, 600), 4);
    set_at(objects, move_object(objects, deltaseconds, 5, 20), 5);
    set_at(objects, move_object(objects, deltaseconds, 6, 20), 6);
}