#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define FILENAME "db.txt"
#define PATTERN_COUNT 4


void* ThrdFunc(void* args);
