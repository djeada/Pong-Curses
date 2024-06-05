#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
 
typedef struct {
    short int x, y, c;
    bool movhor, movver;
} object;

void init_screen(object *scr);
void init_game(object *scr, object *b1, object *b2, object *b);
void update_game(object *scr, object *b1, object *b2, object *b, int *cont);
void handle_input(int ch, object *b1, object *b2, bool *end);
void render_game(object *scr, object *b1, object *b2, object *b);

#endif // GAME_H
