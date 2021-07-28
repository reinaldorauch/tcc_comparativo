#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

typedef struct timespec tv_t;

uint32_t random_int(uint32_t max) {
  return rand() % max;
}

void random_string(char *ref) {
  char buf[11];

  for (uint32_t i = 0; i < 10; i++) {
    buf[i] = (char) (random_int(127-32)+32);
  }

  buf[10] = '\0';

  strcpy(buf, ref);
}

uint8_t linear_search(char *key, char *arr[], uint32_t len) {
  for (uint32_t i = 0; i < len; i++) {
    if (strcmp(arr[i], key) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  srand(time(NULL));

  const uint32_t MAX_ITEMS = 10000;

  char *arr[MAX_ITEMS];
  uint32_t search_index = 0;
  char key[11];
  tv_t start, end;

  for (uint32_t i = 0; i < MAX_ITEMS; i++) {
    // initializing
    for (uint32_t j = 0; j < MAX_ITEMS; j++) {
      arr[j] = malloc(11);
      random_string(arr[j]);
    }

    search_index = random_int(MAX_ITEMS);
    strcpy(arr[search_index], key);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    printf("%d;", search_index);
    linear_search(key, arr, MAX_ITEMS);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("%d\n", (end.tv_sec - start.tv_sec) * 10000000000 + (end.tv_nsec - start.tv_nsec));
  }

  return 0;
}
