#include <stdio.h>
typedef int element;

void sequentialSearch1(element a[], int n, int key) {
	int i = 0;
	printf("\n %d�� �˻��϶�! ->> ", key);
	while (i < n && a[i] != key) i++;
	if (i < n) printf("%d��°�� �˻� ����! \n\n", i + 1);
	else printf("%d��°�� �˻� ����! \n\n", i + 1);
}

void main() {
	element a[] = { 8, 30, 1, 9, 11, 19, 2 };
	int n = 7;

	sequentialSearch1(a, n, 9);		// �迭 a�� n�� ���� �߿��� Ž��Ű�� 9�� ���� �˻�
	sequentialSearch1(a, n, 6);		// �迭 a�� n�� ���� �߿��� Ž��Ű�� 6�� ���� �˻�

	getchar();
}