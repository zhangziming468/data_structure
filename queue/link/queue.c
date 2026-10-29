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

stack* stack_create(){
  stack* s;
  if((s = (stack*)malloc(sizeof(stack))) == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  s->q1 = queue_create();
  s->q2 = queue_create();

  return s;
}

void stack_push(stack* s, data_t value){
  if(s == NULL){
    printf("s is NULL.\n");
    return;
  }

  if(!queue_empty(s->q1))
    enqueue(s->q1, value);
  else if(!queue_empty(s->q2))
    enqueue(s->q2, value);
  else
    enqueue(s->q1, value);
}

data_t stack_pop(stack* s){
  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  if(queue_empty(s->q2) && s->q2 != NULL){
    while(s->q1->front->next != s->q1->rear)
      enqueue(s->q2,dequeue(s->q1));
    return dequeue(s->q1);
  }

  if(queue_empty(s->q1) && s->q1 != NULL){
    while(s->q2->front->next != s->q2->rear)
      enqueue(s->q1,dequeue(s->q2));
    return dequeue(s->q2);
  }
}

int stack_empty(stack* s){
  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  return (queue_empty(s->q1) && queue_empty(s->q2)) ? 1 : 0;
}

data_t stack_top(stack* s){
  data_t t;

  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  if(queue_empty(s->q2) && s->q2 != NULL){
    while(s->q1->front->next != s->q1->rear)
      enqueue(s->q2,dequeue(s->q1));
    t = s->q1->rear->data;
    enqueue(s->q2,dequeue(s->q1));
  }

  if(queue_empty(s->q1) && s->q1 != NULL){
    while(s->q2->front->next != s->q2->rear)
      enqueue(s->q1,dequeue(s->q2));
    t = s->q2->rear->data;
    enqueue(s->q1,dequeue(s->q2));
  }

  return t;
}

stack* stack_free(stack* s){
  if(s == NULL)
    return NULL;

  s->q1 = queue_free(s->q1);
  s->q2 = queue_free(s->q2);

  free(s);
  s = NULL;

  return NULL;
}
