#include <stdio.h>
#include "sqlist.h"
#include <stdlib.h>
#include <string.h>

sqlink sqlist_create(){
	sqlink L;
	L = (sqlink)malloc(sizeof(sqlist));	
	if(L == NULL){
		printf("malloc failed.\n");
		return L;
	}

	memset(L, 0, sizeof(sqlist));
	L->last = -1;

	return L;
}

//-1:fail	0:success
int sqlist_clear(sqlink L){
	if(L == NULL){
		return -1;
	}
	
	if(L->last == -1){
		printf("the list is empty.\n");
		return -1;
	}

	memset(L, 0, sizeof(sqlist));	
	L->last = -1;

	return 0;
}

//1:yes		0:no
int sqlist_empty(sqlink L){
	if(L == NULL){
		return -1;
	}

	if(L->last == -1){
		return 1;
	}

	else{
		return 0;
	}
}


int sqlist_insert(sqlink L, int value, int pos){
	if(L == NULL){
		return -1;
	}

	if(L->last == N-1){
		printf("The list is full.\n");
		return -1;
	}

	if(pos < 0 || pos > (L->last)+1){
		printf("The input position is invalid.\n");
		return -1;
	}

	int i;
	for(i = L->last;i >= pos;i--){
		L->data[i+1] = L->data[i];
	}
	L->data[pos] = value;
	L->last++;

	return 0;
}


int sqlist_delete(sqlink L, int pos){
	if(L == NULL){
		return -1;
	}

	if(L->last == -1){
		printf("the list is empty.\n");
		return -1;
	}

	for(int i = pos + 1;i <= L->last;i++){
		L->data[i-1] = L->data[i];
	}
	L->last--;

	return 0;
}


int sqlist_locate(sqlink L, int value){
	if(L == NULL){
		return -1;
	}

	if(L->last == -1){
		printf("the list is empty.\n");
		return -1;
	}

	for(int i = 0;i <= L->last;i ++){
		if(L->data[i] == value){
			return i;
		}
	}

	return -1;
}


int sqlist_free(sqlink L){
	if(L == NULL){
		return -1;
	}

	free(L);
	L = NULL;

	return 0;
}


int sqlist_show(sqlink L){
	if(L == NULL){
		return -1;
	}

	if(L->last == -1){
		printf("the list is empty.\n");
		return -1;
	}

	for(int i = 0;i <= L->last;i++){
		printf("%d ", L->data[i]);
	}
	puts("");

	return 0;
}


int sqlist_merge(sqlink A, sqlink B){
	if(A == NULL || B == NULL){
		return -1;
	}

	if(B->last == -1){
		return -1;
	}

	int i = 0;
	int ret;

	while(i <= B->last){
		ret = sqlist_locate(A, B->data[i]);
		if(ret == -1){
			sqlist_insert(A, B->data[i], A->last+1);
		}
		i++;
	}

	return 0;
}


int sqlist_purge(sqlink L){
	if(L == NULL){
		return -1;
	}

	if(L->last == -1){
		printf("the list is empty.\n");
	}

	if(L->last == 0){
		return 0;
	}

	int i, j;
	for(i = 1;i <= L->last;){
		for(j = i - 1;j >= 0;j--){
			if(L->data[i] == L->data[j]){
				sqlist_delete(L, i);
				break;
			}
		}
		
		if(j < 0)
			i++;
	}

	return 0;
}

