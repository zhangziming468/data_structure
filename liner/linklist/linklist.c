#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist linklist_create(){
  linklist H;
  if((H = (linklist)malloc(sizeof(node))) == NULL){
    printf("malloc failed.\n");
    return H;
  }

  H->data = 0;
  H->next = NULL;

  return H;
}

int linklist_tail_insert(linklist H, data_t value){
  if(H == NULL){
    printf("Your previous malloc has failed, please check!\n");
    return -1;
  }

  linklist p;
  if((p = (linklist)malloc(sizeof(node))) == NULL){
    printf("malloc failed.\n");
    return -1;
  }
  p->data = value;
  p->next = NULL;

  linklist q = H;
  for(;q->next != NULL;q = q->next);
  q->next = p;

  return 0;
}

void linklist_show(linklist H){
  if(H == NULL){
    printf("Your previous malloc has failed, please check!\n");
    return;
  }

  if(H->next == NULL){
    printf("The linklist is empty.\n");
    return;
  }

  linklist p;
  for(p = H;p->next != NULL;p = p->next){
    printf("%d ", p->next->data);
  }
  puts("");

  return;
}

linklist linklist_get_position(linklist H, int pos){
  if(H == NULL){
    printf("Your previous malloc has failed, please check!\n");
    return NULL;
  }
   
  if(H->next == NULL){
    printf("The linklist is empty.\n");
    return NULL;
  }

  if(pos < -1){
    printf("The input position is invalid.\n");
    return NULL;
  }

  if(pos == -1){
    return H;
  }

  linklist p = H;
  for(int i = 0;i <= pos;i++){
    p = p->next;
    if(p == NULL){
      printf("The input position is invalid.\n");
      return NULL;
    }
  }

  return p;
}

int linklist_insert(linklist H, int pos, data_t value){
  linklist p = linklist_get_position(H, pos-1);
  if(p == NULL)
    return -1;
  
  linklist q;
  if((q = (linklist)malloc(sizeof(node))) == NULL){
    printf("malloc failed.\n");
    return -1;
  }
  q->data = value;
  q->next = NULL;

  q->next = p->next;
  p->next = q;
  
  return 0;
}

int linklist_delete(linklist H, int pos){
  if(H == NULL){
    printf("Your previous malloc has failed, please check!\n");
    return -1;
  }
   
  if(H->next == NULL){
    printf("The linklist is empty.\n");
    return -1;
  }
  
  linklist p = linklist_get_position(H, pos-1);
  if(p == NULL || p->next == NULL){
    printf("The input position is invalid.\n");
    return -1;
  }
  linklist q = p->next;
  p->next = q->next;
  
  free(q);
  q = NULL;
  
  return 0;
}

linklist linklist_free(linklist H){
  if(H == NULL){
    return NULL;
  }

  linklist temp;
  printf("free:");

  while(H != NULL){
    temp = H->next;
    printf("%d ", H->data);
    free(H);
    H = temp;
  }
  puts("");
 
  return NULL;
  //You need to put H on the left of the equation.
}

linklist linklist_turn(linklist H){
  if(H == NULL){
    printf("H = NULL.\n");
    return NULL;
  }

  if(H->next == NULL || H->next->next == NULL)
    return H;
    linklist p = H->next->next;
    H->next->next = NULL;
  
  linklist q;
  while(p != NULL){
    q = p;
    p = p->next;
    q->next = H->next;
    H->next = q;
  }
  
  return H;
}

linklist linklist_adjmax(linklist H, data_t* value){
  if(H == NULL){
    printf("H = NULL.\n");
    return NULL;
  }
  
  if(H->next == NULL || H->next->next == NULL || H->next->next->next == NULL)
    return NULL;
    
  linklist p, q, r;
  p = H->next;
  q = H->next->next;
  *value = p->data+q->data;
  r = p;
  
  while(q->next != NULL){
    p = p->next;
    q = q->next;
  
    if(*value < p->data + q->data){
      *value = p->data + q->data;
      r = p;
    }
  }
  
  return r;
}

int linklist_merge(linklist H1, linklist H2){
  if(H1 == NULL || H2 == NULL)
    return -1;

  linklist p = H1->next;
  linklist q = H2->next;
  linklist r = H1;
  H1->next = NULL;
  H2->next = NULL;
  
  while(p && q){
    if(p->data < q->data){
      r->next = p;
      p = p->next;
      r = r->next;
    }
    else{
      r->next = q;
      q = q->next;
      r = r->next;
    }
  }
  
  if(p == NULL)
    r->next = q;
  else
    r->next = p;

  //r->next = p ? p : q;//三目运算符
  
  return 0;
}
