#include "threadfunc.h"


// TODO: test on windows
int main(int argc, char const *argv[])
{
    char* patterns[PATTERN_COUNT] = {"berlin", "dresden", "fokus", "wiesbaden"};
    pthread_t threads[PATTERN_COUNT];

    for (int i = 0; i < PATTERN_COUNT; i++) {
        printf("started thread %d (searching for '%s')\n", i, patterns[i]);
        pthread_create(&threads[i], NULL, ThrdFunc, patterns[i]);
    }

    for (int i = 0; i < PATTERN_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    exit(0);
}
