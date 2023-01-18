#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"

cell **cells;

void start_visualisation(struct ant* ant) {
    initscr();
    start_color();
    curs_set(FALSE);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    cells = init_matrix();
    chtype c = ' ' | COLOR_PAIR(1);
    for (int i = 0; i < max_x; i++) {
        for (int j = 0; j < max_y; j++) {
            move(j, i);
            addch(c);
            cells[i][j] = WHITE;
        }
    }
}

cell** init_matrix() {
    cell** matrix = calloc(max_y, sizeof(cell*));
    for (int i = 0; i < max_y; i++) {
        matrix[i] = calloc(max_x, sizeof(cell));
    }
    return matrix;
}

void remove_matrix(cell **matrix) {
    for (int i = 0; i < max_y; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void visualise_and_advance(struct ant* ant, const char* rules, size_t len) {
    int value = cells[ant->x][ant->y];
    if (value + 1 < len) {
        move(ant->y, ant->x);
        
        chtype c = ' '
        addch;
    }
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

void end_visualisation() {
   remove_matrix(cells);
   endwin();
}
