#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void test_queue();
void test_stack();

int main(){
  // test_queue();
  test_stack();

  return 0;
}

void test_queue(){
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
}

void test_stack() {
  printf("========== 开始测试：用两个队列实现栈 ==========\n");

  // 1. 创建栈
  stack* s = stack_create();
  if (s == NULL) {
    printf("stack create failed.\n");
    return;
  }

  // 2. 判空测试
  printf("初始状态: stack_empty = %d (预期 1)\n", stack_empty(s));

  // 3. 压栈测试
  printf("\n--- 压栈: 1, 2, 3 ---\n");
  stack_push(s, 1);
  stack_push(s, 2);
  stack_push(s, 3);
  
  // ⚠️ 这里跑起来你会发现，由于你的 push 里有 !queue_empty 判断，
  // 当栈底是空的时候，第一个 1 可能压根没压进去！
  // 稍后你需要把 stack_push 里的 !queue_empty 去掉，改成统一往 q1 压。
  
  printf("压栈后: stack_empty = %d (预期 0)\n", stack_empty(s));
  printf("当前栈顶: %d (预期 3)\n", stack_top(s));

  // 4. 出栈测试
  printf("\n--- 开始出栈 ---\n");
  printf("出栈: %d (预期 3)\n", stack_pop(s));
  printf("当前栈顶: %d (预期 2)\n", stack_top(s));
  
  printf("再次压栈: 4\n");
  stack_push(s, 4);
  printf("当前栈顶: %d (预期 4)\n", stack_top(s));

  // 5. 连续出栈直到空
  printf("\n--- 清空栈 ---\n");
  while (!stack_empty(s)) {
    printf("出栈: %d\n", stack_pop(s));
  }
  printf("全部出栈完毕。\n");
  printf("清空后: stack_empty = %d (预期 1)\n", stack_empty(s));

  // 6. 释放栈
  printf("\n--- 释放栈 ---\n");
  s = stack_free(s);
  if (s == NULL) {
    printf("stack 已安全释放。\n");
  }

  printf("========== 测试结束 ==========\n");
}
