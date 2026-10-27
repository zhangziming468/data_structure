typedef int data_t;

typedef struct node{
  data_t data;
  struct node *next;
}node, *linklist;

linklist linklist_create();
int linklist_tail_insert(linklist H, data_t value);
void linklist_show(linklist H);
linklist linklist_get_position(linklist H, int pos);
int linklist_insert(linklist H, int pos, data_t value);
int linklist_delete(linklist H, int pos);
linklist linklist_free(linklist H);
linklist linklist_turn(linklist H);
linklist linklist_adjmax(linklist H, data_t* value);
int linklist_merge(linklist H1, linklist H2);
