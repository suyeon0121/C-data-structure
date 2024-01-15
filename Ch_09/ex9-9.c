#include <stdio.h>
#include <stdlib.h>

typedef int element;			// ���� Ž�� Ʈ�� element�� �ڷ����� int�� ���� 
typedef struct treeNode {
	element key;				// ������ �ʵ� 
	struct treeNode* left;		// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;		// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

// ��� x�� �����ϴ� ����
treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ��θ� ����ϴ� ���� 
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("%d ", root->key);
		displayInorder(root->right);
	}
}

// Ʈ�� ���� ���� 
void treeSort(element a[], int n) {
	treeNode* root = NULL;				// ���� ���� Ž�� Ʈ�� ����
	root = insertNode(root, a[0]);		// a[0]�� ���� ���� Ž�� Ʈ���� ��Ʈ�� ���� 

	for (int i = 1; i < n; i++)			// a[1]~a[n-1]�� ���ҵ��� 
		insertNode(root, a[i]);			// �����ϸ鼭 ���� Ž�� Ʈ�� ����
	displayInorder(root);				// ���� Ž�� Ʈ���� ���� ��ȸ�� ��� ��� 
}

int main() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	printf("\n <<<<< Ʈ�� ���� ���� >>>>> \n\n  ");
	treeSort(list, size);

	getchar();
}