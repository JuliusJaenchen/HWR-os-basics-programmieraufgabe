#include "threadfunc.h"


// TODO: test on windows
int main(int argc, char const *argv[])
{
    char* patterns[PATTERN_COUNT] = {"berlin", "dresden", "fokus", "wiesbaden"};
    pthread_t threads[PATTERN_COUNT];
    int exitStatus = 0;

    for (int i = 0; i < PATTERN_COUNT; i++) {
        pthread_create(&threads[i], NULL, ThrdFunc, patterns[i]);
    }

    for (int i = 0; i < PATTERN_COUNT && exitStatus == 0; i++) {
        char* errorMessage = NULL;
        void* errorMessagePtr = &errorMessage;
        
        pthread_join(threads[i], errorMessagePtr);

        if (errorMessage != NULL) {
            exitStatus = 1;
            printf("ERROR: %s", errorMessage);
            free(errorMessage);
        }
    }

    return exitStatus;
}
