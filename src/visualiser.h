#ifndef SRC_VISUALISER_H_
#define SRC_VISUALISER_H_

#include "langton.h"

#define cell_at(x, y) field[y][x]

void init_colors();

// поле
int** field;

// инициализация всех зависимостей
void start_visualisation(int max_x, int max_y, struct ant *ant, size_t *generation);

// уничтожение всех зависимостей
void end_visualisation(int max_y);

// получение char для корректного оторбражения муравья
char get_direction(struct ant *ant);

// инициализация поля
void init_field(int max_x, int max_y);

// уничтожение поля
void remove_field(int max_y);

// отрисовка и продвижение муравья вперед
void visualise_and_advance(const char* rules, const int len, struct ant *ant,
                           int max_x, int max_y, size_t *generation, bool gameLevel);

// отрисовка надписи Step
void draw_gen(int max_y);

// отрисовка числа шагов
void update_gen(size_t *generation, int max_y);

// отрисовка поля
void fill_screen(struct ant *ant, int max_x, int max_y);

// отрисовка муравья
void set_ant(struct ant *ant);

void real_rule(const char* rules, const int len, struct ant *ant);

void apply_rule(const char* rules, const int len, struct ant *ant);

void apply_rule_general(const char* rules, const int len, struct ant *ant);

#endif  // SRC_VISUALISER_H_
