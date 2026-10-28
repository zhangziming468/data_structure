typedef int data_t;
#define N 4

typedef struct{
  data_t data[N];
  int front, rear;
  int count;
}queue;

queue* queue_create();
int enqueue(queue* q, data_t value);
data_t dequeue(queue* q);
int queue_clear(queue* q);
int queue_empty(queue* q);
int queue_full(queue* q);
queue* queue_free(queue* q);
