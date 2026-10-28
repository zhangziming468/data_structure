typedef int data_t;

typedef struct node{
  data_t data;
  struct node* next;
}node, *linklist;

typedef struct{
  linklist front, rear;
}queue;

queue* queue_create();
int enqueue(queue* q, data_t value);
data_t dequeue(queue* q);
int queue_empty(queue* q);
int queue_clear(queue* q);
queue* queue_free(queue* q);
