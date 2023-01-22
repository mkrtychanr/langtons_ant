#ifndef SRC_VISUALISER_H_
#define SRC_VISUALISER_H_

#include "langton.h"

int** field;

void start_visualisation(int max_x, int max_y, struct ant *ant, size_t *generation);
void end_visualisation(int max_y);
char get_direction(struct ant *ant);
void init_field(int max_x, int max_y);
void remove_field(int max_y);
void visualise_and_advance(const char* rules, const int len, struct ant *ant,
                           int max_x, int max_y, size_t *generation);
void draw_gen(int max_y);
void update_gen(size_t *generation, int max_y);
void fill_screen(int max_x, int max_y);
void set_ant(struct ant *ant);

#endif  // SRC_VISUALISER_H_
