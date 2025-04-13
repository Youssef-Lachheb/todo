#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "tasks.txt"

void add_task(const char *task) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Added task: %s\n", task);
}

void list_tasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No tasks found.\n");
        return;
    }
    char line[256];
    int count = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d. %s", count++, line);
    }
    fclose(file);
}

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

