#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

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
