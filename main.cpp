#include "Menu.h"

/*int main(int argc, char** argv) {
    primeMenu(argc, argv);
    return 0;
}*/

int main() {
    const char* algos[11]{"bubble-sort", "heap-sort",     "insertion-sort", "selection-sort",
                          "merge-sort",  "quick-sort",    "radix-sort",     "shell-sort",
                          "flash-sort",  "counting-sort", "shaker-sort"};
    char** argv = new char*[5];
    for (int i = 0; i < 5; i++) {
        argv[i] = new char[100];
    }
    strcpy(argv[0], "main.exe");
    strcpy(argv[1], "-a");
    strcpy(argv[2], "bubble-sort");
    strcpy(argv[3], "10000");
    strcpy(argv[4], "-both");
    for (int i = 0; i < 11; i++) {
        strcpy(argv[2], algos[i]);
        primeMenu(5, argv);
    }
}