#include <stdio.h>
#include "sqlist.h"

void test_insert();
void test_delete();
void test_merge();
void test_purge();

int main()
{
	//test_insert();
	//test_delete();
	//test_merge();
	//test_purge();

	return 0;
}

void test_insert(){
	sqlink L;
	L = sqlist_create();
	
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_insert(L, 30, 0);
	sqlist_insert(L, 40, 0);
	sqlist_insert(L, 50, 0);
	sqlist_insert(L, 60, 0);

	sqlist_show(L);
	sqlist_free(L);
} 

void test_delete(){
	sqlink L;
	L = sqlist_create();
	
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_insert(L, 30, 0);
	sqlist_insert(L, 40, 0);
	sqlist_insert(L, 50, 0);
	sqlist_insert(L, 60, 0);

	sqlist_show(L);
	sqlist_delete(L, 0);
	sqlist_show(L);
	sqlist_free(L);
}

void test_merge(){
	sqlink A, B;
	A = sqlist_create();
	B = sqlist_create();
	
	sqlist_insert(A, 10, 0);
	sqlist_insert(A, 20, 0);
	sqlist_insert(A, 30, 0);
	sqlist_insert(A, 40, 0);

	sqlist_insert(B, 50, 0);
	sqlist_insert(B, 20, 0);
	sqlist_insert(B, 50, 0);
	sqlist_insert(B, 40, 0);

	sqlist_show(A);
	sqlist_show(B);

	sqlist_merge(A, B);
	sqlist_show(A);
	sqlist_free(A);
	sqlist_free(B);
}

void test_purge(){
	sqlink L;
	L = sqlist_create();
	
	sqlist_insert(L, 10, 0);
	sqlist_insert(L, 20, 0);
	sqlist_insert(L, 30, 0);
	sqlist_insert(L, 40, 0);
	sqlist_insert(L, 50, 0);
	sqlist_insert(L, 20, 0);

	sqlist_show(L);
	sqlist_purge(L);
	sqlist_show(L);
	sqlist_free(L);
}
