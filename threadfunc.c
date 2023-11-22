#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "threadfunc.h"


char getPatternChar(char* patternPtr, int offset) {
    return *(patternPtr + offset);
}

void* ThrdFunc(void* arg) {
    char* patternPtr = (char*)arg;
    clock_t startTime = clock();

    FILE* fileDescriptor = fopen(FILENAME, "r");
    if (fileDescriptor == NULL) {
        printf("Failed to open file '%s'\n", FILENAME);
        exit(1);
    }

    int patternCursorOffset = 0;
    bool wasPatternFound = false;
    char ch;
    while (!wasPatternFound && (ch = fgetc(fileDescriptor)) != EOF) {
        // printf("ch: %c\n", ch);
        bool doesCurrentCharacterMatch = (getPatternChar(patternPtr, patternCursorOffset) == ch);
        // printf("does character match pattern? (offset: %d) %d\n", patternCursorOffset, doesCurrentCharacterMatch);
        if (doesCurrentCharacterMatch) {
            patternCursorOffset++;
        } else {
            patternCursorOffset = 0;
        }

        // check if pattern has no next unmatched character
        if (getPatternChar(patternPtr, patternCursorOffset) == '\0') {
            wasPatternFound = true;
        }
    }
        
    double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

    if (wasPatternFound) {
        printf("Pattern '%s' was found in %s. Took %.5fs\n", patternPtr, FILENAME, elapsedTime);
    } else {
        printf("Pattern '%s' was not found in %s. Took %.5fs\n", patternPtr, FILENAME, elapsedTime);
    }

    fclose(fileDescriptor);
    return NULL;
}
