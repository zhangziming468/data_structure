//define the maximun and the datatype
#define N 128
typedef int datatype;

//define sqlist
typedef struct{
	datatype data[N];
	int last;			//the index of the last data
}sqlist, *sqlink;

//define function
sqlink sqlist_create();

int sqlist_clear(sqlink L);

int sqlist_empty(sqlink L);

int sqlist_insert(sqlink L, int value, int pos);

int sqlist_delete(sqlink L, int pos);

int sqlist_locate(sqlink L, int value);

int sqlist_free(sqlink L);

int sqlist_show(sqlink L);

int sqlist_merge(sqlink A, sqlink B);

int sqlist_purge(sqlink L);
