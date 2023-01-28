#include <ncurses.h>
#include <stdlib.h>
#include "visualiser.h"

void init_colors() {
    init_color(8, 0, 500, 500);
}


void start_visualisation(int max_x, int max_y, struct ant *ant, size_t *generation) {
    initscr();
    noecho();
    start_color();
    curs_set(false);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
    init_pair(4, COLOR_WHITE, COLOR_CYAN);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_RED);
    init_field(max_x, max_y);
    for (int i = 0; i < max_x; i++) {
        for (int j = 0; j < max_y; j++) {
            field[j][i] = 0;
        }
    }
    ant->x = max_x / 2;
    ant->y = max_y / 2;
    ant->direction = UP;
    fill_screen(max_x, max_y);
    set_ant(ant);
    draw_gen(max_y);
    update_gen(generation, max_y);
    refresh();
}

void set_ant(struct ant *ant) {
    move(ant->y, ant->x);
    addch(get_direction(ant) | COLOR_PAIR(field[ant->y][ant->x] + 1));
}

void end_visualisation(int max_y) {
    remove_field(max_y);
    endwin();
}

char get_direction(struct ant *ant) {
    char result = ' ';
    switch (ant->direction) {
        case UP:
            result = '^';
            break;
        case RIGHT:
            result = '>';
            break;
        case DOWN:
            result = 'v';
            break;
        case LEFT:
            result = '<';
            break;
        default:
            break;
    }
    return result;
}

void init_field(int max_x, int max_y) {
    field = malloc(max_y * sizeof(int*));
    for (int i = 0; i < max_y; i++) {
        field[i] = malloc(max_x * sizeof(int));
    }
}

void remove_field(int max_y) {
    for (int i = 0; i < max_y; i++) {
        free(field[i]);
    }
    free(field);
}

void visualise_and_advance(const char* rules, const int len, struct ant *ant,
                           int max_x, int max_y, size_t *generation) {
    if (rules[field[ant->y][ant->x]] == 'L') {
        turn_left(ant);
    } else {
        turn_right(ant);
    }
    field[ant->y][ant->x]++;
    if (field[ant->y][ant->x] == len) {
        field[ant->y][ant->x] = 0;
    }
    fill_screen(max_x, max_y);
    move_forward(max_x, max_y, ant);
    set_ant(ant);
    draw_gen(max_y);
    update_gen(generation, max_y);
    refresh();
    move(max_y + 1, max_x + 1);
}

void draw_gen(int max_y) {
    mvprintw(max_y + 2, 0, "Step: ");
}

void update_gen(size_t *generation, int max_y) {
    char gen[30];
    sprintf(gen, "%ld", *generation);
    mvprintw(max_y + 2, 6, gen);
    (*generation)++;
}

void fill_screen(int max_x, int max_y) {
    for (int i = 0; i < max_x; i++) {
        for (int j = 0; j < max_y; j++) {
            move(j, i);
            addch(' ' | COLOR_PAIR(field[j][i] + 1));
        }
    }
}
