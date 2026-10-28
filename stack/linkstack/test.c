#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

void test_push();
void test_pop();
void test_empty();

int main()
{
  test_push();
  // test_pop();
  // test_empty();

  return 0;
}

void test_push(){
  stack s;
  s = stack_create();

  // stack_push(s, 7);
  // stack_push(s, 5);
  // stack_push(s, 3);
  // stack_push(s, 1);

  stack_show(s);

  stack_free(s);
}

void test_pop(){
  stack s;
  s = stack_create();

  stack_push(s, 7);
  stack_push(s, 5);
  stack_push(s, 3);
  stack_push(s, 1);

  stack_show(s);

  stack_pop(s);
  stack_show(s);
  stack_pop(s);
  stack_show(s);
}

void test_empty(){
  stack s;
  s = stack_create();

  stack_push(s, 7);
  stack_push(s, 5);
  stack_push(s, 3);
  stack_push(s, 1);

  stack_show(s);

  stack_pop(s);
  stack_show(s);
  stack_pop(s);
  stack_show(s);
  stack_pop(s);
  stack_show(s);
  stack_pop(s);
  stack_show(s);

  printf("%d\n", stack_empty(s));
}
