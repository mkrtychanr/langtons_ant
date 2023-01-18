#ifndef SRC_VISUALISER_H_
#define SRC_VISUALISER_H_

#include "langton.h"
#include <stdbool.h>

static int max_x = 100;
static int max_y = 100;

typedef enum colour cell;

void start_visualisation();
void visualise_and_advance();
bool not_quit();
cell cell_at_fct(int y, int x); //optional
void end_visualisation();
const char* direction_to_s(enum direction d);

#endif  // SRC_VISUALISER_H_
