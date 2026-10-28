typedef int data_t;

typedef struct node{
  data_t data;
  struct node* next;
}node, *stack;

stack stack_create();
int stack_push(stack s, data_t value);
void stack_show(stack s);
data_t stack_pop(stack s);
int stack_empty(stack s);
data_t stack_top(stack s);
stack stack_free(stack s);
