#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

// #include "langton.h"
#include "visualiser.h"

bool init_rules(char* rules, int* len, int argc, char *argv[]);

int main(int argc, char *argv[]) {
    int max_x = 100;
    int max_y = 56;
    struct ant ant;
    int len = 2;
    char rules[128];
    size_t generation = 0;
    bool rule = init_rules(rules, &len, argc, argv);
    start_visualisation(max_x, max_y, &ant, &generation);
    char input = getch();
    while (input != 'q' && input != 'Q') {
        visualise_and_advance(rules, (int)len, &ant, max_x, max_y, &generation, rule);
        input = getch();
    }
    end_visualisation(max_y);
    return 0;
}

bool init_rules(char* rules, int* len, int argc, char *argv[]) {
    bool valid_string = true;
    if (argc > 1) {
        size_t temp_len = strlen(argv[1]);
        for (size_t i = 0; i < temp_len && valid_string; i++) {
            if (argv[1][i] != 'L' && argv[1][i] != 'R') {
                valid_string = false;
            }
        }
        if (valid_string) {
            *len = temp_len;
            strncpy(rules, argv[1], 26);
        }
    } else {
        valid_string = false;
    }
    if (!valid_string) {
        strcpy(rules, "LR");
        *len = 2;
    }
    return valid_string;
}
