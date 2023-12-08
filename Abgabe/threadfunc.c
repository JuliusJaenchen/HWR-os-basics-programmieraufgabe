#include "threadfunc.h"


void* ThrdFunc(void* arg) {
    clock_t startTime = clock();
    char* errorMessage = NULL;
    char* pattern = (char*)arg;
    int patternLength = strlen(pattern);

    printf("started thread with id: %lu looking for starting word: '%s'\n", (unsigned long)pthread_self(), pattern);

    FILE* fileDescriptor = fopen(FILENAME, "r");
    if (fileDescriptor == NULL) {
        errorMessage = calloc(30 + strlen(FILENAME), sizeof(char));
        sprintf(errorMessage, "failed to open file '%s'\n", FILENAME);
    } else {
        bool wasPatternFound = false;
        char lineBuffer[LINE_BUFFER_SIZE];
        while (!wasPatternFound && fgets(lineBuffer, LINE_BUFFER_SIZE, fileDescriptor) != NULL) {
            bool shouldContinue = false;
            for (int i = 0; i < patternLength && !shouldContinue; i++) {
                if (pattern[i] != lineBuffer[i]) {
                    shouldContinue = true;
                }
            }
            if (!shouldContinue) {
                wasPatternFound = true;
            }
        }
            
        double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
        if (wasPatternFound) {
            printf("'%s' was found in %s. Took %.5fs\n", pattern, FILENAME, elapsedTime);
        } else {
            printf("no line in %s starts with '%s'. Took %.5fs\n",  FILENAME, pattern, elapsedTime);
        }
    }
    
    fclose(fileDescriptor);
    return errorMessage;
}
