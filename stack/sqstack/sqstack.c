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
