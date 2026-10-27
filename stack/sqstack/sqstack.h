typedef int data_t;

typedef struct{
  data_t* data;
  int maxlen;
  int top;
}sqstack;

sqstack* sqstack_create(int max);
int sqstack_empty(sqstack* s);
data_t sqstack_top(sqstack* s);
int sqstack_push(sqstack* s, data_t value);
data_t sqstack_pop(sqstack* s);
int sqstack_clear(sqstack* s);
sqstack* sqstack_free(sqstack* s);
