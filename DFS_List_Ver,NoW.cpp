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

void add_edge(Alist * list, int start, int end) {
	element * newnode = NULL;
	newnode = (element *)malloc(sizeof(element));
	newnode->vertex = end;// 원래는 start와 end의 유효성 검사도 해야함
	newnode->link = list->plink[start];
	list->plink[start] = newnode;

}
void dfs(Alist * list,int n) {
	element * plink=NULL;
	printf("방문 : %d\n", n);
	visit[n] = 1;
	plink = list->plink[n];
	while(plink!=NULL) {
		if (!visit[plink->vertex]) {
			dfs(list, plink->vertex);

		}
	}
}
void print_graph(Alist * list) {
	element * plink = NULL;
	for (int i = 0; i <= 6; i++) {
		plink = list->plink[i];
		printf("%d행 : ", i);
		while (plink != NULL) {
			printf("%d ", plink->vertex);
			plink = plink->link;
		}
		printf("\n");

	}
}
int main()
{
	Alist * list = NULL;
	int n = 4; // 원소개수
	list = (Alist *)malloc(sizeof(Alist));
	memset(list, 0, sizeof(Alist));
	list->n = n;
	for (int i = 0; i <= 6; i++) {
		list->plink[i] = NULL;
	}
	add_edge(list, 0, 1);
	add_edge(list, 0, 2);
	add_edge(list, 1,0);
	add_edge(list, 1,2);
	add_edge(list, 1, 3);
	add_edge(list, 2,0);
	add_edge(list, 2,1);
	add_edge(list, 3, 1);
	print_graph(list);
	dfs(list, 0);
	return 0;
}