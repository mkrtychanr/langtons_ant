#include <string.h>
#include <ncurses.h>

#include "langton.h"
#include "visualiser.h"

int main(int argc, char *argv[]) {
    int max_x = 60;
    int max_y = 28;
    struct ant ant;
    int len = 2;
    char rules[26];
    bool valid_string = true;
    if (argc > 1) {
        size_t temp_len = strlen(argv[1]);
        bool valid_string = true;
        for (size_t i = 0; i < temp_len && valid_string; i++) {
            if (argv[1][i] != 'L' && argv[1][i] != 'R') {
                valid_string = false;
            }
        }
        if (valid_string) {
            len = temp_len;
            strncpy(rules, argv[1], 26);
        }
    } else {
        valid_string = false;
    }
    if (!valid_string) {
        strcpy(rules, "LR");
    }
    size_t generation = 0;
    start_visualisation(max_x, max_y, &ant, &generation);
    char input = getch();
    while (input != 'q' && input != 'Q') {
        visualise_and_advance(rules, (int)len, &ant, max_x, max_y, &generation);
        input = getch();
    }
    end_visualisation(max_y);
    return 0;
}
