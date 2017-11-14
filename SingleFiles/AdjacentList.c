#include <stdio.h>
#include <stdlib.h>

struct edge {
	char headname;
	int weight;
	struct edge *next;
};

struct vertex {
	char name;
	struct edge *first;
};

struct VertexArray {
	struct vertex *a;
	size_t length;
	size_t size;
};

void initVertexArray(struct VertexArray *va, size_t size=128) {
	va->a=(vertex *)malloc(size * sizeof(vertex));
	va->size=size;
	va->length=0;
}

void push_back(struct VertexArray *va, vertex v) {
	if (va->size<=va->length) {
		va->a=(vertex *)realloc(va->a, 2 * va->size * sizeof(vertex));
		va->size*=2;
		va->a[va->length]=v;
		++(va->length);
	} else {
		va->a[va->length]=v;
		++(va->length);
	}
}

void createEdge(struct VertexArray *va, char fromvertex, char tovertex, int weight=0) {
	struct edge *e;

	e=(edge *)malloc(sizeof(edge));
	e->headname=tovertex;
	e->weight=weight;
	e->next=NULL;

	int i=0;
	struct edge *p;

	for (i=0;i<va->length;i++) {
		if (va->a[i].name==fromvertex) {	
			if (va->a[i].first==NULL) {
				va->a[i].first=e;
				break;
			}

			p=va->a[i].first;
			while (p->next!=NULL) {
				p=p->next;
			}
			p->next=e;

			break;
		}
	}
}

void showGraph(struct VertexArray *va) {
	int i=0;
	printf("Length: %d\n", va->length);
	printf("Size:   %d\n", va->size);
	printf("Vertices: \n");
	for (i=0;i<va->length;i++) {
		printf("%c ", va->a[i].name);
	}
	printf("\nEdges: \n");
	struct edge *p;
	for (i=0;i<va->length;i++) {
		p=va->a[i].first;
		while (p!=NULL) {
			printf("(%c,%c) ", va->a[i].name, p->headname);
			p=p->next;
		}
	}
	printf("\n");
}

/*void DepthFirstTraverse(struct VertexArray *va, int *visited, int index) {
	struct edge *p;
	p=va->a[index].first;
	if (p==NULL) {
		return;
	}

	int i=0;
	int headindex=0;

	printf("%c ", va->a[index].name);
	visited[index]=1;

	while (p!=NULL) {
		headindex=0;
		for (i=0;i<va->length;i++) {
			if (va->a[i].name==p->headname) {
				headindex=i;
				break;
			}
		}
		if (visited[headindex]==0) {
			DepthFirstTraverse(va, visited, headindex);
		}
		p=p->next;
	}
}

void DepthFirstTraverse_Top(struct VertexArray *va) {
	int *visited;
	visited=(int *)calloc(va->length * sizeof(int));

	int i=0;
	for (i=0;i<va->length;i++) {
		if (visited[i]==0) {
			DepthFirstTraverse(va, visited, i);
		} else {
			continue;
		}
	}
	free(visited);
}*/

void deleteList(struct VertexArray *va) {
	int i=0;
	struct edge *p;
	struct edge *q;
	for (i=0;i<va->length;i++) {
		if (va->a[i].first==NULL) {
			continue;
		} else {
			p=va->a[i].first;
			while (p->next!=NULL) {
				q=p->next;
				free(p);
				p=q;
			}
			free(p);
		}
	}
}

int main(void) {
	struct VertexArray va;
	initVertexArray(&va, 2);

	struct vertex temp;
	char c;

	int num=0;
	scanf("%d", &num);
	fflush(stdin);

	int i=0;

	for (i=0;i<num;i++) {
		scanf("%c", &c);
		temp.name=c;
		temp.first=NULL;
		push_back(&va, temp);
	}
	fflush(stdin);

	int n=0;
	char from, to;

	scanf("%d", &n);
	fflush(stdin);
	for (i=0;i<n;i++) {
		scanf("%c", &from);
		scanf("%c", &to);
		createEdge(&va, from, to, 1);
	}

	showGraph(&va);

	deleteList(&va);

	system("pause");

	return 0;
}


