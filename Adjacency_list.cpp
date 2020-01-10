#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct Adj_element { //���
	int vertex; // 1,2
	Adj_element * link;
}element;
typedef struct Adj_list { //��������Ʈ
	int n; // �������� 
	element * plink[MAX];

}Alist;

void add_edge(Alist * list, int start, int end) {
	//��������
	/*element * newnode = NULL;
	newnode = (element *)malloc(sizeof(element));
	newnode->vertex = end;// ������ start�� end�� ��ȿ�� �˻絵 �ؾ���
	newnode->link = list->plink[start];
	list->plink[start] = newnode;  */
	element * newnode = NULL; // �������� 
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
void del_node(Alist * list, int u, int v) {
	element * prev;
	element * del;
	prev=list->plink[u];
	while (prev != NULL && prev->link->vertex != v) {
		prev = prev->link;
	}
	if (prev != NULL) {
		del = prev->link;
		prev->link = del->link;
	}
/*	prev = NULL;
	del = NULL;
	prev = list->plink[v];
	while (prev != NULL && prev->link->vertex != u) {
		prev = prev->link;
	}
	if (prev != NULL) {
		del = prev->link;
		prev->link = del->link;
	}*/
}
void print_graph(Alist * list) {
	element * plink = NULL;
	for (int i = 0; i <= 6; i++) {
		plink = list->plink[i];
		printf("%d�� : ",i);
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
	int n = 7; // ���Ұ���
	list = (Alist *)malloc(sizeof(Alist));
	memset(list, 0, sizeof(Alist));
	list->n = 7;
	for (int i = 0; i <= 6; i++) {
		list->plink[i] = NULL;
	}
	add_edge(list, 0, 1);
	add_edge(list, 0, 2);
	add_edge(list, 0, 3);
	add_edge(list, 0, 4);
	add_edge(list, 1, 0);
	add_edge(list, 1, 2);
	add_edge(list, 1, 3);
    del_node(list, 1, 2);
	print_graph(list);

	return 0;
}