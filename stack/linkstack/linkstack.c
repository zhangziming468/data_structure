#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

stack stack_create(){
  stack s;
  if((s = (stack)malloc(sizeof(node))) == NULL){
    printf("malloc failed.\n");
    return NULL;
  }

  s->data = 0;
  s->next = NULL;
  
  return s;
}

int stack_push(stack s, data_t value){
  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  stack p;
  if((p = (stack)malloc(sizeof(node))) == NULL){
    printf("malloc failed.\n");
    return -1;
  }

  p->data = value;
  p->next = s->next;
  s->next = p;
  
  return 0;
}

void stack_show(stack s){
  if(s == NULL){
    printf("s is NULL.\n");
    return;
  }

  if(s->next == NULL){
    printf("The stack is empty.\n");
    return;
  }

  stack p = s->next;
  while(p != NULL){
    printf("%d ", p->data);
    p = p->next;
  }
  puts("");

  return;
}

data_t stack_pop(stack s){
  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  if(s->next == NULL){
    printf("The stack is empty.\n");
    return -1;
  }

  stack p = s->next;
  s->next = p->next;
  data_t t = p->data;

  free(p);
  p = NULL;

  return t;
}

int stack_empty(stack s){
  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  return (s->next == NULL) ? 1 : 0;
}

data_t stack_top(stack s){
  if(s == NULL){
    printf("s is NULL.\n");
    return -1;
  }

  if(s->next == NULL){
    printf("The stack is empty.\n");
    return -1;
  }
  
  return s->next->data;
}

stack stack_free(stack s){
  if(s == NULL)
    return NULL;

  stack p;
  printf("free:");
  while(s != NULL){
    p = s->next;
    printf("%d ", s->data);
    free(s);
    s = p;
  }
  puts("");

  return NULL;
}
