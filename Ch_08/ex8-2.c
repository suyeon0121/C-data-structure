#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30						// ��� ������ �迭�� �ִ� ũ��

// ���� ����Ʈ�� ��� ������ ����ü�� ���� 
typedef struct graphNode {
	int vertex;								// ������ ��Ÿ���� ������ �ʵ�
	struct graphNode* link;					// ���� ���� ������ �����ϴ� ��ũ �ʵ�
}graphNode;

// �׷����� ���� ����Ʈ�� ǥ���ϱ� ���� ����ü ���� 
typedef struct graphType {
	int n;									// �׷����� ���� ���� 
	graphNode* adjList_H[MAX_VERTEX];		// �׷��� ������ ���� ��� ������ �迭  
} graphType;

// ���� �׷����� �����ϴ� ���� 
void createGraph(graphType* g) {
	int v;
	g->n = 0;							// �׷����� ���� ������ 0���� �ʱ�ȭ
	for (v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL;			// �׷����� ������ ���� ��� ������ �迭�� NULL�� �ʱ�ȭ
}

// �׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;								// �׷����� ���� ���� n�� �ϳ� ����
}

// �׷��� g�� ���� (u, v)�� �����ϴ� ����
void x(graphType* g, int u, int v) {
	graphNode* node;

	// ���� (u, v)�� �����ϱ� ���� ���� u�� ���� v�� ���� �׷����� �ִ��� Ȯ��
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];	// ���� ������ ���� ��带 ����Ʈ�� ù ��° ���� ����
	g->adjList_H[u] = node;
}

// �׷��� g�� �� ������ ���� ���� ����Ʈ�� ����ϴ� ����
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65); // ���� 0~3�� A~D�� ���
			p = p->link;
		}
	}
}

int main(void) {
	int i;
	graphType* G1, * G2, * G3, * G4;
	G1 = (graphType*)malloc(sizeof(graphType));
	G2 = (graphType*)malloc(sizeof(graphType));
	G3 = (graphType*)malloc(sizeof(graphType));
	G4 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1); createGraph(G2); createGraph(G3); createGraph(G4);

	// �׷��� G1 
	for (i = 0; i < 4; i++)
		insertVertex(G1, i);	//G1�� ���� 0~3 ����
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);
	printf("\n G1�� ���� ����Ʈ");
	print_adjList(G1);

	// �׷��� G2
	for (i = 0; i < 3; i++)
		insertVertex(G2, i);	// G2�� ���� 0~2 ����
	insertEdge(G2, 0, 2);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 2, 1);
	insertEdge(G2, 2, 0);
	printf("\n\n G2�� ���� ����Ʈ");
	print_adjList(G2);

	// �׷��� G3 
	for (i = 0; i < 4; i++)
		insertVertex(G3, i);	// G3�� ���� 0~3 ����
	insertEdge(G3, 0, 3);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 2, 3);
	printf("\n\n G3�� ���� ����Ʈ");
	print_adjList(G3);

	// �׷��� G4 
	for (i = 0; i < 3; i++)
		insertVertex(G4, i);	// G4�� ���� 0~2 ����
	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);
	printf("\n\n G4�� ���� ����Ʈ");
	print_adjList(G4);

	getchar();  
}