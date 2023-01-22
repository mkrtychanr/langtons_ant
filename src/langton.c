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

void move_forward(int max_x, int max_y, struct ant *ant) {
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
    cut_position(max_x, max_y, ant);
}

void cut_position(int max_x, int max_y, struct ant *ant) {
    if (ant->x > max_x - 1) {
        ant->x = 0;
    } else if (ant->x < 0) {
        ant->x = max_x - 1;
    } else if (ant->y > max_y - 1) {
        ant->y = 0;
    } else if (ant->y < 0) {
        ant->y = max_y - 1;
    }
}
