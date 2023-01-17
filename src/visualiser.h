#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>

static int max_x;
static int max_y;

typedef enum colour cell;

void start_visualisation();
void visualise_and_advance();
bool not_quit();
cell cell_at_fct(int y, int x); //optional
void end_visualisation();
const char* direction_to_s(enum direction d);

#endif
