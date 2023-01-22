#ifndef SRC_LANGTON_H_
#define SRC_LANGTON_H_

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

void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(int max_x, int max_y, struct ant *ant);
void cut_position(int max_x, int max_y, struct ant *ant);

#endif  // SRC_LANGTON_H_
