#include <ncurses.h>
#include <stdlib.h>
#include "visualiser.h"

void init_colors() {
    init_color(8, 0, 500, 500);
    init_color(9, 585, 292, 0);
    init_color(10, 433, 0, 207);
    init_color(11, 914, 550, 964);
    init_color(12, 207, 406, 175);
    init_color(13, 70, 136, 0);
    init_color(14, 136, 50, 128);
    init_color(15, 137, 128, 160);
    init_color(16, 906, 472, 242);
    init_color(17, 894, 316, 214);
    init_color(18, 765, 117, 226);
    init_color(19, 996, 570, 93);
    init_color(20, 121, 679, 910);
    init_color(21, 250, 875, 812);
    init_color(22, 843, 867, 726);
    init_color(23, 996, 968, 859);
    init_color(24, 933, 800, 718);
    init_color(25, 539, 472, 363);
    init_color(26, 589, 601, 664);
}


void start_visualisation(int max_x, int max_y, struct ant *ant, size_t *generation) {
    initscr();
    noecho();
    start_color();
    curs_set(false);
    init_colors();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, 8);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_CYAN);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_WHITE, COLOR_RED);
    init_pair(8, COLOR_BLACK, COLOR_YELLOW);
    init_pair(9, COLOR_WHITE, 9);
    init_pair(10, COLOR_WHITE, 10);
    init_pair(11, COLOR_BLACK, 11);
    init_pair(12, COLOR_WHITE, 12);
    init_pair(13, COLOR_WHITE, 13);
    init_pair(14, COLOR_WHITE, 14);
    init_pair(15, COLOR_WHITE, 15);
    init_pair(16, COLOR_BLACK, 16);
    init_pair(17, COLOR_BLACK, 17);
    init_pair(18, COLOR_BLACK, 18);
    init_pair(19, COLOR_BLACK, 19);
    init_pair(20, COLOR_BLACK, 20);
    init_pair(21, COLOR_BLACK, 21);
    init_pair(22, COLOR_BLACK, 22);
    init_pair(23, COLOR_BLACK, 23);
    init_pair(24, COLOR_BLACK, 24);
    init_pair(25, COLOR_BLACK, 25);
    init_pair(26, COLOR_BLACK, 26);
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
