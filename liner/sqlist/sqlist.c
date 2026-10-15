#include <stdio.h>
#include "sqlist.h"
#include <stdlib.h>
#include <string.h>

sqlink sqlist_create(){
	sqlink L;
	L = (sqlink)malloc(sizeof(sqlist));	
	if(L == NULL){
		printf("malloc failed\n");
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

	memset(L, 0, sizeof(sqlist));	
	L->last = -1;

	return 0;
}

//1:yes		0:no
int sqlist_empty(sqlink L){
	if(L->last == -1){
		return 1;
	}

	else{
		return 0;
	}
}


int sqlist_insert(sqlink L, int value, int pos){
	if(L->last == N-1){
		printf("The list is full\n");
		return -1;
	}

	if(pos < 0 || pos > (L->last)+1){
		printf("The input position is invalid\n");
		return -1;
	}

	int i;
	for(i = L->last;i >= pos;i--){
		L->data[i] = L->data[i+1];
	}
	L->data[pos] = value;
	L->last++;

	return 0;
}


int sqlist_delete(sqlink L, int pos){

	return 0;
}


int sqlist_locate(sqlink L, int value){

	return 0;
}


int sqlist_free(sqlink L){

	return 0;
}


int sqlist_show(sqlink L){

	return 0;
}


int sqlist_merge(sqlink A, sqlink B){

	return 0;
}


int sqlist_purge(sqlink L){

	return 0;
}

