/*
** EPITECH PROJECT, 2022
** list_create.c
** File description:
** create list
*/
#include "../../include/list.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
