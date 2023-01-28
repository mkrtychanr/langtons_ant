#ifndef SRC_LANGTON_H_
#define SRC_LANGTON_H_

// enum направлений
enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// структура муравья
struct ant {
    int x;
    int y;
    int direction;
};

// функция поворота влево
void turn_left(struct ant *ant);

// функция поворота вправо
void turn_right(struct ant *ant);

// функция движения вперед
void move_forward(int max_x, int max_y, struct ant *ant);

// функция восстановления координат при выходе за границы поля
void cut_position(int max_x, int max_y, struct ant *ant);

#endif  // SRC_LANGTON_H_
