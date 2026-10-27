#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void test_tail_insert();
void test_insert();
void test_delete();
void test_free();
void test_turn();
void test_adjmax();
void test_merge();

int main(){
  // test_tail_insert();
  // test_insert();
  // test_delete();
  // test_free();
  // test_turn();
  // test_adjmax();
  test_merge();

  return 0;
}

void test_tail_insert(){
  linklist H;
  
  H = linklist_create();
  if(H == NULL){
    return;
  }

  data_t value;
  printf("input:");
  while(1){
    scanf("%d", &value);
    if(value == -1){
      break;
    }
    linklist_tail_insert(H, value);
    printf("input:");
  }

  linklist_show(H);
}

void test_insert(){
  linklist H;
  
  H = linklist_create();
  if(H == NULL){
    return;
  }

  data_t value;
  printf("input:");
  while(1){
    scanf("%d", &value);
    if(value == -1){
      break;
    }
    linklist_tail_insert(H, value);
    printf("input:");
  }

  linklist_show(H);

  linklist_insert(H, 4, 100);

  linklist_show(H);
}

void test_delete(){
  linklist H;
  
  H = linklist_create();
  if(H == NULL){
    return;
  }

  data_t value;
  printf("input:");
  while(1){
    scanf("%d", &value);
    if(value == -1){
      break;
    }
    linklist_tail_insert(H, value);
    printf("input:");
  }

  linklist_show(H);

  linklist_delete(H, 4);

  linklist_show(H);
}

void test_free(){
  linklist H;
  
  H = linklist_create();
  if(H == NULL){
    return;
  }

  // 1. 快速造一个链表，不用每次手动输入了 (1, 2, 3)
  data_t value;
  printf("input:");
  while(1){
    scanf("%d", &value);
    if(value == -1){
      break;
    }
    linklist_tail_insert(H, value);
    printf("input:");
  }

  printf("--- 释放前 ---\n");
  printf("H 的地址是: %p\n", (void*)H);
  linklist_show(H);

  // 2. 执行释放
  printf("\n--- 开始释放 ---\n");
  H = linklist_free(H); 

  // 3. 验证结果
  printf("\n--- 释放后 ---\n");
  printf("H 的地址是: %p\n", (void*)H); // 这里应该打印出 (nil) 或者 0x0
  
  if (H == NULL) {
      printf("测试通过：头指针已成功置空！\n");
  } else {
      printf("测试失败：头指针未置空！\n");
  }

  // 4. 防御性测试：再释放一次空指针，看看你的代码能不能兜住（不应该崩溃）
  printf("\n--- 测试重复释放空指针 ---\n");
  H = linklist_free(H); 
  printf("安全退出。\n");
}

void test_turn(){
  linklist H;
  
  H = linklist_create();
  if(H == NULL){
    return;
  }

  data_t value;
  printf("input:");
  while(1){
    scanf("%d", &value);
    if(value == -1){
      break;
    }
    linklist_tail_insert(H, value);
    printf("input:");
  }

  linklist_show(H);

  H = linklist_turn(H);

  linklist_show(H);
  linklist_free(H);
}

void test_adjmax(){
  linklist H;
  
  H = linklist_create();
  if(H == NULL){
    return;
  }

  data_t value;
  printf("input:");
  while(1){
    scanf("%d", &value);
    if(value == -1){
      break;
    }
    linklist_tail_insert(H, value);
    printf("input:");
  }

  linklist_show(H);

  linklist p;
  data_t sum;
  p = linklist_adjmax(H, &sum);
  if(p == NULL)
    return;
  printf("p = %d, sum = %d\n", p->data, sum);

  linklist_free(H);
}

void test_merge(){
  linklist H1, H2;
  H1 = linklist_create();
  H2 = linklist_create();

  linklist_tail_insert(H1, 2);
  linklist_tail_insert(H1, 4);
  linklist_tail_insert(H1, 6);
  linklist_tail_insert(H1, 8);
  linklist_tail_insert(H2, 1);
  linklist_tail_insert(H2, 3);
  linklist_tail_insert(H2, 7);
  linklist_tail_insert(H2, 10);

  linklist_show(H1);
  linklist_show(H2);

  linklist_merge(H1, H2);
  linklist_show(H1);

  linklist_free(H1);
  linklist_free(H2);
  return;
}
