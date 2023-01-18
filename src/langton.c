#include "langton.h"

void turn_left(struct ant *ant) {
    switch (ant->direction) {
        case UP:
            ant->direction = LEFT;
            break;
        case LEFT:
            ant->direction = DOWN;
            break;
        case DOWN:
            ant->direction = RIGHT;
            break;
        case RIGHT:
            ant->direction = UP;
            break;
        default:
            break;
    }
}

void turn_right(struct ant *ant) {
    switch (ant->direction) {
        case UP:
            ant->direction = RIGHT;
            break;
        case RIGHT:
            ant->direction = DOWN;
            break;
        case DOWN:
            ant->direction = LEFT;
            break;
        case LEFT:
            ant->direction = UP;
            break;
        default:
            break;
    }
}

void move_forward(struct ant *ant, int max_x, int max_y) {
    switch (ant->direction) {
        case UP:
            ant->y--;
            break;
        case RIGHT:
            ant->x++;
            break;
        case DOWN:
            ant->y++;
            break;
        case LEFT:
            ant->x--;
            break;
        default:
            break;
    }
    cut_position(ant, max_x, max_y);
}

void cut_position(struct ant *ant, int max_x, int max_y) {
    if (ant->x < 0) {
        ant->x = max_x;
    } else if (ant->x > max_x) {
        ant->x = 0;
    } else if (ant->y < 0) {
        ant->y = max_y;
    } else if (ant->y > max_y) {
        ant->y = 0;
    }
}