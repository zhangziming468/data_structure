#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#include <string.h>

void test_push();
void test_empty();
void test_top();
void test_pop();
void test_clear();

int main()
{
  // test_push();
  // test_empty();
  // test_top();
  // test_pop();
  test_clear();

  return 0;
}

void test_push(){
  sqstack* s;
  s = sqstack_create(5);
  sqstack_push(s, 1);
  sqstack_push(s, 2);
  sqstack_push(s, 3);
  sqstack_push(s, 4);
  sqstack_push(s, 5);

  for(int i = 0;i <= s->top;i++)
    printf("%d ", s->data[i]);
  puts("");

  sqstack_free(s);
}

void test_empty(){
  sqstack* s;
  s = sqstack_create(5);

  sqstack_empty(s);
  sqstack_free(s);
}

void test_top(){
  sqstack* s;
  s = sqstack_create(5);
  sqstack_push(s, 1);
  sqstack_push(s, 2);
  sqstack_push(s, 3);
  sqstack_push(s, 4);
  sqstack_push(s, 5);

  for(int i = 0;i <= s->top;i++)
    printf("%d ", s->data[i]);
  puts("");

  data_t t = sqstack_top(s);
  printf("%d\n", t);

  sqstack_free(s);
}

void test_pop(){
  sqstack* s;
  s = sqstack_create(5);
  sqstack_push(s, 1);
  sqstack_push(s, 2);
  sqstack_push(s, 3);
  sqstack_push(s, 4);
  sqstack_push(s, 5);

  for(int i = 0;i <= s->top;i++)
    printf("%d ", s->data[i]);
  puts("");

  data_t t = sqstack_pop(s);
  printf("%d\n", t);

  for(int i = 0;i <= s->top;i++)
    printf("%d ", s->data[i]);
  puts("");

  sqstack_free(s);
}

void test_clear(){
  sqstack* s;
  s = sqstack_create(5);
  sqstack_push(s, 1);
  sqstack_push(s, 2);
  sqstack_push(s, 3);
  sqstack_push(s, 4);
  sqstack_push(s, 5);

  for(int i = 0;i <= s->top;i++)
    printf("%d ", s->data[i]);
  puts("");

  sqstack_clear(s);

  if(s->top >= 0){
    for(int i = 0;i <= s->top;i++)
      printf("%d ", s->data[i]);
    puts("");
  }
  else{
    printf("The stack is empty.\n");
  }

  sqstack_free(s);
}
