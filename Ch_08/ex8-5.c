#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5		// �׷����� ���� ����
#define INF 10000

int weight[MAX_VERTICES][MAX_VERTICES] = {			// �׷��� G11�� ����ġ ���� ���
	{ 0, 10, 5, INF, INF },
	{ INF, 0, 2, 1, INF },
	{ INF, 3, 0, 9, 2},
	{ INF, INF, INF, 0, 4},
	{ 7, INF, INF, 6, 0},
};
int distance[MAX_VERTICES];				// ���� �������� �����ϴ� �ִ� ��� ���� ���� 
int S[MAX_VERTICES];					// ������ ���� S

// �ִ� ��θ� ���� ���� ������ ã�� ���� 
int nextVertex(int n) {
	int i, min, minPos;
	min = INT_MAX;
	minPos = -1;
	for (i = 0; i<n; i++)
		if ((distance[i] < min) && !S[i]) {
			min = distance[i];
			minPos = i;
		}
	return minPos;
}

// �ִ� ��� ���ϴ� ������ ����ϴ� ���� 
int printStep(int step) {
	int i;
	printf("\n%3d �ܰ� : S = {", step);
	for (i = 0; i < MAX_VERTICES; i++)
		if (S[i] == TRUE)
			printf("%3c", i + 65);

	if (step < 1) printf(" } \t\t\t");
	else if (step < 4) printf(" } \t\t");
	else printf(" } \t");
	printf("distance : [");
	for (i = 0; i < MAX_VERTICES; i++)
		if (distance[i] == INF)
			printf("%4c", '*');
		else printf("%4d", distance[i]);
	printf("%4c", ']');
	return ++step;
}

void Dijkstra_shortestPath(int start, int n) {
	int i, u, w, step = 0;

	for (i = 0; i < n; i++) {				// �ʱ�ȭ
		distance[i] = weight[start][i];
		S[i] = FALSE;
	}

	S[start] = TRUE;						// ���� ������ ���� S�� �߰� 
	distance[start] = 0;					// ���� ������ �ִ� ��θ� 0���� ����

	step = printStep(0);					// 0�ܰ� ���¸� ���

	for (i = 0; i < n - 1; i++) {
		u = nextVertex(n);					// �ִ� ��θ� ����� ���� ���� u ã��
		S[u] = TRUE;						// ���� u�� ���� S�� �߰� 
		for (w = 0; w < n; w++)
			if (!S[w])						// ���� S�� ���Ե��� ���� ���� �߿��� 
				if (distance[u] + weight[u][w] < distance[w])
					distance[w] = distance[u] + weight[u][w];		// ��� ���� ���� 

		step = printStep(step);				// ���� �ܰ� ��� 
	}
}

void main(void) {
	int i, j;
	printf("\n********** ����ġ ���� ��� **********\n\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}

	printf("\n ********** ���ͽ�Ʈ�� �ִ� ��� ���ϱ� **********\n\n");
	Dijkstra_shortestPath(0, MAX_VERTICES);

	getchar();
}
