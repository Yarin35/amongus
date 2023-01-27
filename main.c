/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdlib.h>
#include "include/list.h"
#include <string.h>
#include <libgen.h>

int main(int argc,char **argv)
{
    if (argc != 2) {
        printf("incorrect usage of %s\n", basename(argv[0]));
        printf("try %s -nb\nUSAGE:\n\t-nb\t: is the number of crewmates we want\n", basename(argv[0]));
        return 84;
    }
    
    // Create the window
    list_t *mogus = list_create();
    list_node_t *amogus = mogus->head;
    sfVideoMode mode = {105, 110, 32};
    int nb = atoi(argv[1]);
    int l = 0;
    for (int i = nb; i > 0; i --)
        list_add(mogus, i);
    for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
        amogus->window = sfRenderWindow_create(mode, "amogus running", sfClose, NULL);
        amogus->texture = sfTexture_createFromFile("amongus.png", NULL);
        amogus->sprite = sfSprite_create();
    }
    sfEvent event;
    sfVector2i pawn = {0, 0};
//    sfVector2f pos;
//    sfVector2i currentPos;
    float speed = 1;

    for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
        amogus->currentPos.x = 0;
        amogus->currentPos.y = 0;
    }

    for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
        sfSprite_setTexture(amogus->sprite, amogus->texture, sfTrue);
        sfRenderWindow_setPosition(amogus->window, amogus->currentPos);
    }
    
    // Set up the animation
    sfIntRect rect = {10, 160, 105, 117};
    sfClock* clock = sfClock_create();
    sfClock *moovs = sfClock_create();
    srand(time(NULL));

    for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
        amogus->pos.x = rand() % 1921;
        amogus->pos.y = rand() % 1081;
    }

    for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
        sfRenderWindow_setPosition(amogus->window, pawn);
        sfRenderWindow_setVisible(amogus->window, sfTrue);
    }
    
    // Run the main loop
    while (true) { //sfRenderWindow_isOpen(mogus->head->window)) {
        sfTime elapsed2 = sfClock_getElapsedTime(moovs);
        float elapsed_seconds2 = sfTime_asSeconds(elapsed2);
        if (elapsed_seconds2 > 0.001) {
            for (amogus = mogus->head; amogus != NULL; amogus= amogus->next) {
                if (elapsed_seconds2 > 0.001) {
                    if (amogus->currentPos.x < amogus->pos.x)
                        amogus->currentPos.x += speed;
                    else
                        amogus->currentPos.x -= speed;
                    if (amogus->currentPos.y < amogus->pos.y)
                        amogus->currentPos.y += speed;
                    else
                        amogus->currentPos.y -= speed;
                }
                if ((amogus->currentPos.x <= amogus->pos.x && amogus->currentPos.x + 105 >= amogus->pos.x) && (amogus->currentPos.y <= amogus->pos.y && amogus->currentPos.y + 110 >= amogus->pos.y)) {
                    amogus->pos.x = rand() % 1921;
                    amogus->pos.y = rand() % 1081;
                    int dead = rand() % 5;
                    if (dead == 1) {
                        rect.top = 440;
                        sfSprite_setTextureRect(amogus->sprite, rect);
                    } else
                        rect.top = 160;
                }
                sfClock_restart(moovs);
            }
            
            for (amogus = mogus->head; amogus != NULL; amogus = amogus->next)
                sfRenderWindow_setPosition(amogus->window, amogus->currentPos);
        }
        // Process events
        for (amogus = mogus->head; amogus != NULL; amogus = amogus->next)
            while (sfRenderWindow_pollEvent(amogus->window, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(amogus->window);
                if (event.type == sfEvtKeyPressed)
                    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
                        sfRenderWindow_close(amogus->window);
                        l ++;
                    }
            }
        if (l == nb)
            break;
        // Update the sprite
        sfTime elapsed = sfClock_getElapsedTime(clock);
        float elapsed_seconds = sfTime_asSeconds(elapsed);
        if (elapsed_seconds > 0.1) {
            rect.left += 105;
            if (rect.left >= 420)
                rect.left = 10;
            sfClock_restart(clock);
        }
        for (amogus = mogus->head; amogus != NULL; amogus = amogus->next)
            sfSprite_setTextureRect(amogus->sprite, rect);
        // Draw the sprite
        for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
            sfRenderWindow_clear(amogus->window, sfBlack);
            sfRenderWindow_drawSprite(amogus->window, amogus->sprite, NULL);
            sfRenderWindow_display(amogus->window);
        }
    }
    // Clean up
    sfClock_destroy(moovs);
    sfClock_destroy(clock);
    for (amogus = mogus->head; amogus != NULL; amogus = amogus->next) {
        sfSprite_destroy(amogus->sprite);
        sfTexture_destroy(amogus->texture);
        list_remove(mogus, 1);
    }
    free(mogus);
    return 0;
}
