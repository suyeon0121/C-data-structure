#include <stdio.h>
typedef int element;

void sequentialSearch2(element a[], int n, int key) {
	int i = 0;
	printf("\n %d�� �˻��϶�! ->> ", key);
	while (a[i] < key) i++;
	if (a[i] == key) printf("%d��°�� �˻� ����! \n\n", i + 1);
	else printf("%d��°�� �˻� ����! \n\n", i + 1);
}

void main() {
	element a[] = { 1, 2, 8, 9, 11, 19, 29 };
	int n = 7;

	sequentialSearch2(a, n, 9);		// �迭 a�� n�� ���� �߿��� Ž��Ű�� 9�� ���� �˻�
	sequentialSearch2(a, n, 6);		// �迭 a�� n�� ���� �߿��� Ž��Ű�� 6�� ���� �˻�

	getchar();
}