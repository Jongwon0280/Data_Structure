#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
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
	/*element * newnode = NULL;
	newnode = (element *)malloc(sizeof(element));
	newnode->vertex = end;// 원래는 start와 end의 유효성 검사도 해야함
	newnode->link = list->plink[start];
	list->plink[start] = newnode;*/
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
typedef struct Queue {
	int cur;
	int rear, front;
	int q[MAX];
}CQ;
int is_empty(CQ * q) {
	return q->cur == 0;
}
int is_full(CQ * q) {
	return q->cur == MAX;
}
void init(CQ * q) {
	q->cur = 0;
	q->front = q->rear = 0;
}
void enqueue(CQ * q, int data) {
	if (!is_full(q)) {
		q->rear = (q->rear + 1) % MAX;
		q->q[q->rear] = data;
		q->cur++;
	}
}
int dequeue(CQ * q) {
	if (!is_empty(q)) {
		q->front = (q->front + 1) % MAX;
		q->cur--;
		return q->q[q->front];

	}
}
void BFS(Alist * list) {
	element * plink;
	CQ * q = NULL;
	int n;
	q = (CQ *)malloc(sizeof(CQ));
	init(q);
	enqueue(q, 0);
	visit[0] = 1;
	while (!is_empty(q)) {
		n = dequeue(q);
		plink = list->plink[n];
		printf("방문 : %d\n", n);
		while(plink!=NULL) {
			if (!visit[plink->vertex]) {
				enqueue(q, plink->vertex);
				visit[plink->vertex] = 1;
				plink = plink->link;
			}
			else
				plink = plink->link;
		}
	}

}

int main()
{
	Alist * list = NULL;
	int n = 4; // 원소개수
	list = (Alist *)malloc(sizeof(Alist));
	memset(list, 0, sizeof(Alist));
	list->n = n;
	for (int i = 0; i <= 3; i++) {
		list->plink[i] = NULL;
	}
	add_edge(list, 0, 1);
	add_edge(list, 0, 2);
	add_edge(list, 1, 0);
	add_edge(list, 1, 2);
	add_edge(list, 1, 3);
	add_edge(list, 2, 0);
	add_edge(list, 2, 1);
	add_edge(list, 3, 1);
	BFS(list);

	return 0;
}