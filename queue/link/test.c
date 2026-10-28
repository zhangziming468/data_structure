#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
  queue* q = queue_create();

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);

  while(!queue_empty(q))
    printf("dequeue:%d\n", dequeue(q));

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  queue_clear(q);

  if(queue_empty(q))
    printf("The queue has been cleaned.\n");

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  
  queue_free(q);

  return 0;
}
