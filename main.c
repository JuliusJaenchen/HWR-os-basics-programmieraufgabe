#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "threadfunc.h"


// TODO: test on windows
int main(int argc, char const *argv[])
{
    char* patterns[PATTERN_COUNT] = {"berlin", "dresden", "fokus", "wiesbaden"};
    pthread_t threads[PATTERN_COUNT];

    

    for (int i = 0; i < PATTERN_COUNT; i++) {
        printf("started thread %d (searching for '%s')\n", i, patterns[i]);
        char* patternPtr = (char*) malloc(sizeof(patterns[i]));
        // TODO: free() dataPtr
        if (patternPtr == NULL) {
            printf("dataPtr allocation failed");
            exit(1);
        }
        strcpy(patternPtr, patterns[i]);
        pthread_create(&threads[i], NULL, searchForPatternInFile, patternPtr);
        // searchForPatternInFile(patternPtr);
    }

    for (int i = 0; i < PATTERN_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // TODO: loop to wait for threads
    exit(0);
}
