#include <stdio.h>
#include <stdlib.h>
typedef int VECTORTYPE;

typedef struct {
	VECTORTYPE *a;
	unsigned int size;
	unsigned int capacity;
} vector;

void vector_init(vector *v, unsigned int capacity = 1) {
	v->a=(VECTORTYPE *)malloc(capacity*sizeof(VECTORTYPE));
	v->size=0u;
	v->capacity=1u;
}

void vector_push_back(vector *v, VECTORTYPE data) {
	if (v->capacity <= v->size) {
		(v->a)=(VECTORTYPE *)realloc(v->a, 2*(v->capacity)*sizeof(VECTORTYPE));
		v->capacity*=2;
		(v->a)[v->size]=data;
		++(v->size);
	}
	else {
		(v->a)[v->size]=data;
		++(v->size);
	}
}

VECTORTYPE vector_pop_back(vector *v) {
	if (v->size==0u) {
		return (VECTORTYPE)0;
	}
	VECTORTYPE result=(v->a)[v->size-1];
	--v->size;
	return result;
}

void vector_insert(vector *v, VECTORTYPE data, unsigned int position) {
	unsigned int i=0u;
	if (position > v->size) {
		printf("Insert Error!\n");
		return;
	}
	else if (position == v->size) {
		vector_push_back(v, data);
	}
	else {
		if (v->size >= v->capacity) {
			VECTORTYPE *b = (VECTORTYPE *)malloc(2*(v->capacity)*sizeof(VECTORTYPE));
			for (i=0;i<position;i++) {
				b[i] = (v->a)[i];
			}
			b[position]=data;
			for (i=position;i<(v->size);i++) {
				b[i+1]=(v->a)[i];
			}
			(v->a)=b;
			(v->capacity)*=2;
			++(v->size);
		} else {
			for (i=v->size-1;i>=position;i--) {
				(v->a)[i+1]=(v->a)[i];
			}
			(v->a)[position]=data;
			++(v->size);
		}
	}
}

void vector_delete(vector *v, unsigned int position) {
	if (position >= v->size) {
		return;
	}
	if (v->size==0u) {
		return;
	}
	unsigned int i=0;
	for (i=position+1;i<v->size;i++) {
		(v->a)[i-1]=(v->a)[i];
	}
	--(v->size);
}

void vector_destroy(vector *v) {
	free(v->a);
	v->a=NULL;
	v->size=0u;
	v->capacity=0u;
}