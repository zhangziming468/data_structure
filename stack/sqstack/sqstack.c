#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#include <string.h>

sqstack* sqstack_create(int max){
  sqstack* s;
  if((s = (sqstack*)malloc(sizeof(sqstack))) == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  if((s->data = (data_t*)malloc(max * sizeof(data_t))) == NULL){
    printf("malloc failed.\n");
    free(s);
    return NULL;
  }

  memset(s->data, 0, max * sizeof(data_t));
  s->top = -1;
  s->maxlen = max;

  return s;
}

int sqstack_empty(sqstack* s){
  if(s == NULL || s->data == NULL){
    printf("The stack you create malloc failed, please check!\n");
    return -1;
  }

  return (s->top == -1) ? 1 : 0;
}

data_t sqstack_top(sqstack* s){
  if(s == NULL || s->data == NULL){
    printf("The stack you create malloc failed, please check!\n");
    return 0;
  }
  
  if(s->top == -1){
    printf("The stack is empty.\n");
    return 0;
  }

  return s->data[s->top];
}

int sqstack_push(sqstack* s, data_t value){
  if(s == NULL || s->data == NULL){
    printf("The stack you create malloc failed, please check!\n");
    return -1;
  }

  if(s->top == s->maxlen-1){
    printf("The stack is full.\n");
    return -1;
  }

  s->top++;
  s->data[s->top] = value;
  
  return 0;
}

data_t sqstack_pop(sqstack* s){
  if(s == NULL || s->data == NULL){
    printf("The stack you create malloc failed, please check!\n");
    return 0;
  }
  
  if(s->top == -1){
    printf("The stack is empty.\n");
    return 0;
  }

  data_t t = s->data[s->top];
  s->data[s->top] = 0;
  s->top--;

  return t;
}

int sqstack_clear(sqstack* s){
  if(s == NULL || s->data == NULL){
    printf("The stack you create malloc failed, please check!\n");
    return -1;
  }
  
  if(s->top == -1){
    printf("The stack is empty.\n");
    return -1;
  }

  s->top = -1;

  return 0;
}

sqstack* sqstack_free(sqstack* s){
  if(s == NULL)
    return NULL;

  if(s->data != NULL)
    free(s->data);

  free(s);

  return NULL;
}

int sqstack_full(sqstack* s){
  if(s == NULL){
    printf("The stack is NULL.\n");
    return -1;
  }

  return (s->top == s->maxlen-1) ? 1 : 0;
}

queue* queue_create(int max){
  queue* q;
  if((q = (queue*)malloc(sizeof(queue))) == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  q->s1 = sqstack_create(max);
  q->s2 = sqstack_create(max);

  return q;
}

void enqueue(queue* q, data_t value){
  if(q == NULL){
    printf("q is NULL.\n");
    return;
  }

  if(sqstack_full(q->s1) && !sqstack_empty(q->s2)){
    printf("The queue is full.\n");
    return;
  }

  if(sqstack_full(q->s1) && sqstack_empty(q->s2)){
    while(!sqstack_empty(q->s1))
      sqstack_push(q->s2, sqstack_pop(q->s1));
  }

  sqstack_push(q->s1, value);
}

data_t dequeue(queue* q){
  if(q == NULL){
    printf("q is NULL.\n");
    return -1;
  }

  if(sqstack_empty(q->s1) && sqstack_empty(q->s2)){
    printf("The queue is empty.\n");
    return -1;
  }

  if(sqstack_empty(q->s2)){
    while(!sqstack_empty(q->s1))
      sqstack_push(q->s2,sqstack_pop(q->s1));
  }

  return sqstack_pop(q->s2);
}

int queue_empty(queue* q){
  if(q == NULL){
    printf("p is NULL.\n");
    return -1;
  }

  return (sqstack_empty(q->s1) && sqstack_empty(q->s2)) ? 1 : 0;
}

data_t queue_front(queue* q){
  if(q == NULL){
    printf("q is NULL");
    return -1;
  }

  if(queue_empty(q)){
    printf("q is empty.\n");
    return -1;
  }

  if(sqstack_empty(q->s2)){
    while(!sqstack_empty(q->s1))
      sqstack_push(q->s2, sqstack_pop(q->s1));
  }

  return sqstack_top(q->s2);
}

queue* queue_free(queue* q){
  if(q == NULL)
    return NULL;

  q->s1 = sqstack_free(q->s1);
  q->s2 = sqstack_free(q->s2);

  free(q);
  
  return NULL;
}
