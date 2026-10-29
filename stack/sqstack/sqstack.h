typedef int data_t;

typedef struct{
  data_t* data;
  int maxlen;
  int top;
}sqstack;

typedef struct{
  sqstack* s1;
  sqstack* s2;
}queue;

sqstack* sqstack_create(int max);
int sqstack_empty(sqstack* s);
data_t sqstack_top(sqstack* s);
int sqstack_push(sqstack* s, data_t value);
data_t sqstack_pop(sqstack* s);
int sqstack_clear(sqstack* s);
sqstack* sqstack_free(sqstack* s);
int sqstack_full(sqstack* s);
queue* queue_create(int max);
void enqueue(queue* q, data_t value);
data_t dequeue(queue* q);
int queue_empty(queue* q);
data_t queue_front(queue* q);
queue* queue_free(queue* q);
