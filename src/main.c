#include "game.h"

int main() {
    object scr;
    object b1, b2, b;
    int cont = 0;
    bool end = false;

    init_screen(&scr);
    init_game(&scr, &b1, &b2, &b);
    getch();
    
    nodelay(stdscr, true);
    while (!end) {
        usleep(10000);
        update_game(&scr, &b1, &b2, &b, &cont);
        handle_input(getch(), &b1, &b2, &end);
        render_game(&scr, &b1, &b2, &b);
    }

    return 0;
}
