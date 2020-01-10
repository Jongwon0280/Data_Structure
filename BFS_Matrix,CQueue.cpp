#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int mat[MAX][MAX] = { { 0,1,1,0 },{ 1,0,1,1 },{ 1,1,0,0 },{ 0,1,0,0 } };
int visit[4];
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
void BFS() {
	CQ * q = NULL;
	int n;
	q = (CQ *)malloc(sizeof(CQ));
	init(q);
	enqueue(q, 0);
	visit[0] = 1;
	while (!is_empty(q)) {
		n = dequeue(q);
		printf("¹æ¹® : %d\n", n);
		for (int i = 0; i <= 3; i++) {
			if (mat[n][i] == 1 && !visit[i]) {
				enqueue(q, i);
				visit[i] = 1;
				}
		}
	}

}

int main()
{
	BFS();

	return 0;
}