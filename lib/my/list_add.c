/*
** EPITECH PROJECT, 2022
** list_add.c
** File description:
** list add
*/
#include "../../include/list.h"

static unsigned int list_add_node(list_t *list, list_node_t *node)
{
    list->size ++;
    node->prev = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return 0;
    }
    list->head->prev = node;
    node->next = list->head;
    list->head = node;
    return list->size - 1;
}

unsigned int list_add(list_t *list, int index)
{
    list_node_t *node;
    if (list == NULL) {
        write(1, "list_add: list or value is NULL\n", 33);
        return 0;
    }
    node = malloc(sizeof(list_node_t));
    node->index = index;
    node->next = NULL;
    node->prev = NULL;
    return list_add_node(list, node);
}
