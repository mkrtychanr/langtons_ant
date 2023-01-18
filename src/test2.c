#include "stdio.h"
#include "ncurses.h"

int main() {
    initscr();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    chtype c = ' ' | COLOR_PAIR(1);
    for (int i = 0; i < 70; i++) {
        for (int j = 0; j < 20; j++) {
            move(j, i);
            addch(c);
        }
    }
    refresh();
    getch();
    endwin();
    return 0;
}