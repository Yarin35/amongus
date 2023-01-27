/*
** EPITECH PROJECT, 2023
** list_reload.c
** File description:
** list_reload.c
*/
#include "../../include/list.h"

void reload_list(list_t *list, int indexmax)
{
    list_node_t *node = list->head;
    int i = indexmax;
    for (i = indexmax; node != NULL && i != 0; node = node->next, i --)
        node->index = i;
    return;
}
