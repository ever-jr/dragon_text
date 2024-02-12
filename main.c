#include <ncurses.h>
#include <panel.h>
#include <stdbool.h>

#include "include/entity.h"
#include "include/util.h"


// PLAYER
Entity player;
WINDOW *player_stats;

static void press_something() {
    mvprintw(getcury(stdscr) + 1, 0, "press something to continue...\n");
    getch();
}

static void show_win_size(WINDOW *win) {
    int size_rows, size_cols;
    getmaxyx(win, size_rows, size_cols);

    // wprintw(
    //     win,
    //     "TESTE rows: %d cols: %d",
    //     size_rows,
    //     size_cols
    // );

    win_add_border(win);

    wrefresh(win);
    wgetch(win);
}

int main() {
    // ncurses SETTINGS
    initscr();
    cbreak();
    // [stdscr] Standard Screen: Whole terminal
    keypad(stdscr, TRUE);
    intrflush(stdscr, FALSE);
    noecho();

    // PLAYER related
    player = entity_new("PLAYER", 20);
    player_stats = newwin(
        10, // rows
        20, // cols
        10, // start row/line
        0   // start col
    );
    show_win_size(player_stats);
    PANEL *stats_panel = new_panel(player_stats);
    panel_above(stats_panel);

    // start
    // printw("Dragon Text\n-----------------\nStarting...\n");
    // getch();

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

