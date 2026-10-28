#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

int main(){
  queue* q;
  q = queue_create();

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  printf("%d\n", queue_full(q));

  while(!queue_empty(q))
    printf("dequeue:%d\n", dequeue(q));

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);

  queue_clear(q);
  printf("%d\n", queue_empty(q));

  queue_free(q);

  return 0;
}

