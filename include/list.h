/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** list
*/
#include <stdlib.h>
#include <stdio.h>

#ifndef LIST_H
    #define LIST_H

    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <string.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <time.h>
    #include <unistd.h>

typedef struct list_node_s {

    sfRenderWindow *window;
    bool yorn;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2i currentPos;
    struct list_node_s *next;
    struct list_node_s *prev;
    int index;
    sfMusic *song;
    int l;

}  list_node_t;

typedef struct list_s {

    list_node_t *head;
    list_node_t *tail;
    unsigned int size;

}list_t;

list_t *list_create(void);
unsigned int list_add(list_t *list, int index);
int list_get(list_t *list, unsigned int index);
void *list_get_node(list_t *list, unsigned int index);
void list_remove(list_t *list, unsigned int index);
void reload_list(list_t *list, int indexmax);
#endif /* LIST_H */
