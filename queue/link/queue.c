#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_create(){
  queue* q;
  if((q = (queue*)malloc(sizeof(queue))) == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  q->front = q->rear = (linklist)malloc(sizeof(node));
  if(q->front == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  q->front->data = 0;
  q->front->next = NULL;

  return q;
}

int enqueue(queue* q, data_t value){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(q->front == NULL){
    printf("front is NULL.\n");
    return -1;
  }

  linklist p;
  if((p = (linklist)malloc(sizeof(node))) == NULL){
    printf("malloc failed.\n");
    return -1;
  }
  p->data = value;
  p->next = NULL;

  q->rear->next = p;
  q->rear = p;

  return 0;
}

data_t dequeue(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(q->front == NULL){
    printf("front is NULL.\n");
    return -1;
  }

  if(q->front->next == NULL){
    printf("The queue is empty.\n");
    return -1;
  }

  linklist p = q->front;
  q->front = p->next;

  free(p);
  p = NULL;

  return q->front->data;
}

int queue_empty(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(q->front == NULL){
    printf("front is NULL.\n");
    return -1;
  }

  return (q->front == q->rear) ? 1 : 0;
}

int queue_clear(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(q->front == NULL){
    printf("front is NULL.\n");
    return -1;
  }

  if(q->front == q->rear)
    return 0;

  linklist p;
  while(q->front->next != NULL){
    p = q->front;
    q->front = p->next;
    printf("free:%d\n", p->data);
    free(p);
    p = NULL;
  }

  return 0;
}

queue* queue_free(queue* q){
  if(q == NULL)
    return NULL;

  linklist p;
  while(q->front != NULL){
    p = q->front;
    q->front = p->next;
    printf("free:%d\n", p->data);
    free(p);
  }
  
  free(q);
  q = NULL;

  return NULL;
}
