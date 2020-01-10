#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int visit[4];


typedef struct Adj_element {
	int vertex;
	Adj_element * link;
}element;
typedef struct Adj_list {
	int n; // 정점개수 
	element * plink[MAX];

}Alist;
typedef struct Stack {
	int cur;
	int ele[MAX];
}S;
void init_S(S * s) {
	s->cur = 0;
}
void push(S * s,int n) {

	s->ele[s->cur] = n;
	s->cur++;
}
int pop(S * s) {
	s->cur--;
	return s->ele[s->cur];
}

void add_edge(Alist * list, int start, int end) {
	element * newnode = NULL; // 오름차순 
	element * pnode = NULL;
	newnode = (element *)malloc(sizeof(element));
	newnode->vertex = end;
	pnode = list->plink[start];
	if (pnode == NULL) {
		list->plink[start] = newnode;
		newnode->link = NULL;
	}
	else {
		while (pnode->link != NULL) {
			pnode = pnode->link;
		}
		newnode->link = pnode->link;
		pnode->link = newnode;
	}

}

void dfs(Alist * list) {
	element * plink = NULL;
	S* stack = NULL;
	int n;
	stack = (S*)malloc(sizeof(S));
	init_S(stack);
	push(stack, 0);
	while (stack->cur != 0) {

		n = pop(stack);
		if (visit[n] == 0)
			visit[n] = 1;
			printf("방문 : %d\n", n);
			plink = list->plink[n];  
			while (plink != NULL) {
				if (!visit[plink->vertex]) {
					push(stack, plink->vertex);
					plink = plink->link;
				}
				else
					plink = plink->link;
			}
		
	}

	

}
int main() {
	Alist * list = NULL;
	list = (Alist *)malloc(sizeof(Alist));
	list->n = 5;
	for (int i = 0; i <= 6; i++) {
		list->plink[i] = NULL;
	}
	add_edge(list, 0, 1);
	add_edge(list, 0, 2);
	add_edge(list, 0, 3);
	add_edge(list, 1, 0);
	add_edge(list, 1, 2);
	add_edge(list, 1, 4);
	add_edge(list, 2, 0);
	add_edge(list, 2, 1);
	add_edge(list, 3, 0);
	add_edge(list, 3, 4);
	add_edge(list, 4, 1);
	add_edge(list, 4, 3);
	dfs(list);
	return 0;
}