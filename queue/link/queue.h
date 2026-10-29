typedef int data_t;

typedef struct node{
  data_t data;
  struct node* next;
}node, *linklist;

typedef struct{
  linklist front, rear;
}queue;

typedef struct{
  queue* q1;
  queue* q2;
}stack;

queue* queue_create();
int enqueue(queue* q, data_t value);
data_t dequeue(queue* q);
int queue_empty(queue* q);
int queue_clear(queue* q);
queue* queue_free(queue* q);
stack* stack_create();
void stack_push(stack* s, data_t value);
data_t stack_pop(stack* s);
int stack_empty(stack* s);
data_t stack_top(stack* s);
stack* stack_free(stack* s);
