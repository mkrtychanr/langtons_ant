#ifndef SRC_LANGHON_H_
#define SRC_LANGTON_H_

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant {
    int x;
    int y;
    enum direction direction;
};

enum colour { WHITE, BLACK };

void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant, int max_x, int max_y);
void cut_position(struct ant *ant, int max_x, int max_y);

void apply_rule(enum colour *colour, struct ant *ant);
void apply_rule_general(enum colour *colour, struct ant *ant, const char* rules);

#endif  // SRC_LANGHON_H_
