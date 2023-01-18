#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

char* rules;
int len = 0;

enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

struct ant {
    int x;
    int y;
    int direction;
};

struct field_unit {
    int rule_status;
    int colour;
};

int max_x = 70;
int max_y = 20;
struct field_unit** field;
struct ant ant;

// visualiser
void start_visualisation();
void end_visualisation();
char get_direction();
void init_field();
void remove_field();
void visualise_and_advance();

// langton
void turn_left();
void turn_right();
void move_forward();
void cut_position();
void get_len();

int main(int argc, char *argv[]) {
    rules = argv[argc - 1];
    char input = ' ';
    start_visualisation();
    do {
        visualise_and_advance();
        input = getch();
    } while (input != 'q' && input != 'Q');
    end_visualisation();
    return 0;
}

void start_visualisation() {
    initscr();
    start_color();
    curs_set(false);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_field();
    chtype c = ' ' | COLOR_PAIR(1);
    for (int i = 0; i < max_x; i++) {
        for (int j = 0; j < max_y; j++) {
            move(j, i);
            addch(c);
            field[j][i].colour = 0;
            field[j][i].rule_status = 0;
        }
    }
    ant.x = max_x / 2;
    ant.y = max_y / 2;
    ant.direction = UP;
    chtype ant_unit = get_direction() | COLOR_PAIR(1);
    move(ant.y, ant.x);
    addch(ant_unit);
    refresh();
    get_len();
}

void end_visualisation() {
    remove_field();
    endwin();
}

char get_direction() {
    char result = ' ';
    switch (ant.direction) {
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

void init_field() {
    field = malloc(max_y * sizeof(struct field_unit*));
    for (int i = 0; i < max_y; i++) {
        field[i] = malloc(max_x * sizeof(struct field_unit));
    }
}

void remove_field() {
    for (int i = 0; i < max_y; i++) {
        free(field[i]);
    }
    free(field);
}

void visualise_and_advance() {
    move(max_y + 1, max_x + 1);
    addch(' ' | COLOR_PAIR(0));
    field[ant.y][ant.x].rule_status++;
    if (field[ant.y][ant.x].rule_status == len) {
        field[ant.y][ant.x].rule_status = 0;
    }
    if (rules[field[ant.y][ant.x].rule_status] == 'L') {
        move(90, 0);
        addch('l' | COLOR_PAIR(0));
        turn_left();
    } else {
        move(90, 0);
        addch('r' | COLOR_PAIR(0));
        turn_right();
    }
    move(ant.y, ant.x);
    addch(' ' | COLOR_PAIR(field[ant.y][ant.x].rule_status + 1));
    move_forward();
    move(ant.y, ant.x);
    addch(get_direction() | COLOR_PAIR(field[ant.y][ant.x].rule_status + 1));
    refresh();
    move(max_y + 1, max_x + 1);
}

void turn_left() {
    switch (ant.direction) {
        case UP:
            ant.direction = LEFT;
            break;
        case LEFT:
            ant.direction = DOWN;
            break;
        case DOWN:
            ant.direction = RIGHT;
            break;
        case RIGHT:
            ant.direction = UP;
            break;
        default:
            break;
    }
}

void turn_right() {
    switch (ant.direction) {
        case UP:
            ant.direction = RIGHT;
            break;
        case RIGHT:
            ant.direction = DOWN;
            break;
        case DOWN:
            ant.direction = LEFT;
            break;
        case LEFT:
            ant.direction = UP;
            break;
        default:
            break;
    }
}

void move_forward() {
    switch (ant.direction) {
        case UP:
            ant.y--;
            break;
        case RIGHT:
            ant.x++;
            break;
        case DOWN:
            ant.y++;
            break;
        case LEFT:
            ant.x--;
            break;
        default:
            break;
    }
    cut_position();
}

void cut_position() {
    if (ant.x > max_x) {
        ant.x = 0;
    } else if (ant.x < 0) {
        ant.x = max_x;
    } else if (ant.y > max_y) {
        ant.y = 0;
    } else if (ant.y < 0) {
        ant.y = max_y;
    }
}

void get_len() {
    len = strlen(rules);
}