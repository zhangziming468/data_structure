#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#include <string.h>

void test_push();
void test_empty();
void test_top();
void test_pop();
void test_clear();
void test_queue();

int main()
{
  // test_push();
  // test_empty();
  // test_top();
  // test_pop();
  // test_clear();
  test_queue();

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

void test_queue() {
  printf("--- 开始测试双栈队列 ---\n");
  queue* q = queue_create(3); // 容量设为3，方便测试

  printf("入队: 1, 2, 3\n");
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);

  printf("当前队首: %d\n", queue_front(q)); // 应该输出 1

  printf("出队: %d\n", dequeue(q)); // 应该输出 1
  printf("出队: %d\n", dequeue(q)); // 应该输出 2

  printf("再次入队: 4, 5\n");
  enqueue(q, 4);
  enqueue(q, 5);

  printf("当前队首: %d\n", queue_front(q)); // 应该输出 3

  printf("全部出队: ");
  while(!queue_empty(q)) {
    printf("%d ", dequeue(q)); // 应该输出 3 4 5
  }
  printf("\n");

  q = queue_free(q);
  printf("--- 测试结束 ---\n");
}
