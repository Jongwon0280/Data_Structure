  #include<stdio.h>
#define MAX 50
int mat[MAX][MAX] = { {0,1,1,0},{1,0,1,1},{1,1,0,0},{0,1,0,0} };
int visit[4];
void dfs(int n) {
	printf("�湮 : %d\n", n);
	visit[n] = 1;
	for (int i = 0; i <= 3; i++) { // 3�� ����-1�Ѱ� 
		if (!visit[i]&&mat[n][i] == 1) {
			dfs(i);
		}
	}
}
int main() {
	dfs(0);
	return 0;
}