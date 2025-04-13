#include <stdio.h>
#include <string.h>
#include "todo.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:\n");
        printf("  ./todo add \"task description\"\n");
        printf("  ./todo list\n");
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc >= 3) {
        add_task(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_tasks();
    } else {
        printf("Unknown command.\n");
    }

    return 0;
}

// TODO: add done command 
