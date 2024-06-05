#include "game.h"
#include <unistd.h>

void init_screen(object *scr) {
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    getmaxyx(stdscr, scr->y, scr->x);
}

void init_game(object *scr, object *b1, object *b2, object *b) {
    b1->x = scr->x - 2;
    b1->y = scr->y / 2;
    b1->c = 0;
    b1->movhor = false;
    b1->movver = false;

    b2->x = 1;
    b2->y = scr->y / 2;
    b2->c = 0;
    b2->movhor = false;
    b2->movver = false;

    b->x = scr->x / 2;
    b->y = scr->y / 2;
    b->c = 0;
    b->movhor = false;
    b->movver = false;
}

void update_game(object *scr, object *b1, object *b2, object *b, int *cont) {
    if (++(*cont) % 16 == 0) {
        if (b->y == scr->y - 1 || b->y == 1) {
            b->movver = !b->movver;
        }
        if (b->x >= scr->x - 2 || b->x <= 2) {
            b->movhor = !b->movhor;
            if (b->y == b1->y - 1 || b->y == b2->y - 1) {
                b->movver = false;
            } else if (b->y == b1->y + 1 || b->y == b2->y + 1) {
                b->movver = true;
            } else if (b->y != b1->y && b->y != b2->y) {
                (b->x >= scr->x - 2) ? b1->c++ : b2->c++;
                b->x = scr->x / 2;
                b->y = scr->y / 2;
            }
        }
        b->x = b->movhor ? b->x + 1 : b->x - 1;
        b->y = b->movver ? b->y + 1 : b->y - 1;

        if (b1->y <= 1)
            b1->y = scr->y - 2;
        if (b1->y >= scr->y - 1)
            b1->y = 2;
        if (b2->y <= 1)
            b2->y = scr->y - 2;
        if (b2->y >= scr->y - 1)
            b2->y = 2;
    }
}

void handle_input(int ch, object *b1, object *b2, bool *end) {
    switch (ch) {
        case KEY_DOWN:
            b1->y++;
            break;
        case KEY_UP:
            b1->y--;
            break;
        case 'q':
            b2->y--;
            break;
        case 'a':
            b2->y++;
            break;
        case 'p':
            getchar();
            break;
        case 0x1B:
            endwin();
            *end = true;
            break;
    }
}

void render_game(object *scr, object *b1, object *b2, object *b) {
    erase();
    mvprintw(2, scr->x / 2 - 2, "%i | %i", b1->c, b2->c);
    mvvline(0, scr->x / 2, ACS_VLINE, scr->y);
    attron(COLOR_PAIR(1));
    mvprintw(b->y, b->x, "o");
    for (int i = -1; i < 2; i++) {
        mvprintw(b1->y + i, b1->x, "|");
        mvprintw(b2->y + i, b2->x, "|");
    }
    attroff(COLOR_PAIR(1));
}
