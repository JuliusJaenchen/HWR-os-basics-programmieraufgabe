#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define FILENAME "db.txt"
#define PATTERN_COUNT 4

// Although the line is defined as being max. 80 characters long,
// it could take up a lot more bytes due to UTF-8 encoding.
// Hence, the line buffer size (in bytes) is set to 1000 for
// the sake of robustness.
#define LINE_BUFFER_SIZE 1000

void* ThrdFunc(void* args);
