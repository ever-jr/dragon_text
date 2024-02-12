#include <ncurses.h>

void win_add_border(WINDOW *win) {
    int size_rows, size_cols;
    getmaxyx(win, size_rows, size_cols);

    for (int row = 0; row < size_rows; ++row) {
        for (int col = 0; col < size_cols; ++col) {
            bool s_row = row == 0;
            bool e_row = row == size_rows - 1;
            bool s_col = col == 0;
            bool e_col = col == size_cols - 1;

            bool is_vertice =
                (s_row || e_row) &&
                (s_col || e_col);

            bool is_horizontal_edge =
                (s_row || e_row ) &&
                (!s_col || !e_col);

            bool is_vertical_edge =
                (s_col || e_col ) &&
                (!s_row || !e_row);

            char c;
            if (is_vertice) {
                c = '+';
            } else if (is_horizontal_edge) {
                c = '-';
            } else if (is_vertical_edge) {
                c = '|';
            } else continue;

            wmove(win, row, col);
            waddch(win, c);
        }
    }

    wrefresh(win);
    wgetch(win);
}
