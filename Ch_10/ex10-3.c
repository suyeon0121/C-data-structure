#include <stdio.h>
#define INDEX_SIZE 3					// �ε��� ���̺��� ũ�⸦ 3���� ���� 
typedef int element;

// �ε��� ���̺��� ����(index, key)�� ���� 
typedef struct {
	int index;
	element key;
} iTable;

iTable indexTable[INDEX_SIZE];			// �ε��� ���̺� indexTable ����

// �迭 a�� begin ���ҿ� end ���� ���̿��� key�� ���� �˻� 
void sequentialSearch2(element a[], int begin, int end, element key) {
	int i = begin;

	printf("\n %d�� �˻��϶�! ->> ", key);
	while (i < end && a[i] < key) i++;

	if (a[i] == key) printf("%d��°�� �˻� ����!\n\n", (i - begin) + 1);
	else printf("%d��°�� �˻� ����! \n\n", (i - begin) + 1);
}

// �迭 a�� ���� �ε��� ���̺� �����
void makeIndexTable(element a[], int size) {
	int i, n;
	n = size / INDEX_SIZE;				// �ε��� ���̺� ���� �迭 ������ ���� ���
	if (size % INDEX_SIZE > 0) n = n + 1;
	for (i = 0; i<INDEX_SIZE; i++) {	// �ε��� ���̺��� ä���
		indexTable[i].index = i * n;
		indexTable[i].key = a[i * n];
	}
}

// ���� ���� �˻�
void indexSearch(element a[], int n, element key) {
	int i, begin, end;
	if (key < a[0] || key > a[n - 1])
		printf("\nã�� Ű�� �����ϴ�. �˻� ����! \n");

	// �ε��� ���̺��� �˻��Ͽ� �˻� ���� ����
	for (i = 0; i<INDEX_SIZE; i++)
		if ((indexTable[i].key <= key) && (indexTable[i + 1].key > key)) {
			begin = indexTable[i].index;
			end = indexTable[i + 1].index;
			break;
		}
	if (i == INDEX_SIZE) {
		begin = indexTable[i - 1].index;
		end = n;
	}

	sequentialSearch2(a, begin, end, key);		// �˻� ������ ���� ���� �˻� ����
}

void main() {
	element a[] = { 1, 2, 8, 9, 11, 19, 29 };
	int n = 7;
	printf("\n\t<< ���� ���� �˻� >>\n");
	makeIndexTable(a, n);
	indexSearch(a, n, 9);			// �迭 a�� n�� ���� �߿��� Ž��Ű�� 9�� ���� �˻�
	indexSearch(a, n, 6);			// �迭 a�� n�� ���� �߿��� Ž��Ű�� 6�� ���� �˻�

	getchar();
}