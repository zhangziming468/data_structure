#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

queue* queue_create(){
  queue* q;
  if((q = (queue*)malloc(sizeof(queue))) == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  q->count = 0;
  q->front = q->rear = 0;
  memset(q->data, 0, sizeof(q->data));

  return q;
}

int enqueue(queue* q, data_t value){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(q->count == N){
    printf("The queue is full.\n");
    return -1;
  }

  q->data[q->rear] = value;
  q->rear = (q->rear + 1) % N;
  q->count++;

  return 0;
}


data_t dequeue(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(q->count == 0){
    printf("The queue is empty.\n");
    return -1;
  }

  data_t t = q->data[q->front];
  q->front = (q->front + 1) % N;
  q->count--;

  return t;
}

int queue_clear(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  q->front = q->rear = 0;
  q->count = 0;

  return 0;
}

int queue_empty(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  return (q->count == 0) ? 1 : 0;
}

int queue_full(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  return (q->count == N) ? 1 : 0;
}

queue* queue_free(queue* q){
  if(q == NULL)
    return NULL;

  free(q);
  q = NULL;

  return NULL;
}
