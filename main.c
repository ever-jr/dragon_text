#include <ncurses.h>
#include "entity.h"

static void press_something() {
    mvprintw(getcury(stdscr) + 1, 0, "press something to continue...\n");
    getch();
}

int main() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("Dragon Text\n-----------------\n");

    Entity player = entity_new("Player", 20);

    char input;
    do {
        /// TODO: try not to rewrite everything again and again...
        clear();
        entity_stats(player);

        // options
        mvprintw(getcury(stdscr) + 2, 0, "[s]earch\n[r]est\n[q]uit\n");

        // get input
        input = getch();

        switch (input) {
            case 's':
                printw("found something... but don't know what\n");
                press_something();
                break;
            case 'r':
                printw("health recovered!\n");
                press_something();
        }

    } while (input != 'q');

    refresh();
    endwin();

    return 0;
}

