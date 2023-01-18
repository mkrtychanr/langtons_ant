#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

// int main(int argc, char* argv[]) {
//     int instructions = 2;
//     if (argc > 1) {
//         size_t len = strlen(argv[1]);
//         if (len < 27) {
//             bool status = true;
//             for (size_t i = 0; i < len && status; i++) {
//                 if (argv[1][i] != 'L' && argv[1][i] != 'R') {
//                     status = false;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     initscr();
//     start_color();
//     // init_color(8, 227, 169, 190);
//     // init_color(9, 171, 70, 73);
//     init_pair(1, COLOR_GREEN, COLOR_MAGENTA);
//     chtype c = ' ' | COLOR_PAIR(1);
//     addch(c);
//     addch(c);
//     addch(c);
//     addch(c);
//     addch(c);
//     char kek = ' ';
//     chtype c1 = kek | COLOR_PAIR(1);
//     addch(c1);
//     addch(c1);
//     addch(c1);
//     addch(c1);
//     addch(c1);
//     refresh();
//     getch();
//     endwin();
//     return 0;
// }

// int main(int argc, char* argv[]) {
//     initscr();
//     start_color();
//     init_color(8, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
//     init_color(9, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
//     init_pair(1, COLOR_BLACK, 8);
//     init_pair(2, COLOR_BLACK, 9);
//     chtype c = ' ' | COLOR_PAIR(1);
//     for (int i = 0; i < 1000; i++) {
//         addch(c);
//     }
//     c = ' ' | COLOR_PAIR(2);
//     for (int i = 0; i < 1000; i++) {
//         addch(c);
//     }
//     refresh();
//     getch();
//     endwin();
//     return 0;
// }

// 60 179 113 - OK
// 
// #include "test.h"
extern int a;
int main() {
    printf("%d\n", a);
    return 0;
}