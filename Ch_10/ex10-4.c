#include <stdio.h>
typedef int element;
int i;		// ���� �˻��� ���� Ƚ��

void binarySearch(element a[], int begin, int end, element key) {
	int middle;
	i++;							// ���� �˻� ���� Ƚ�� 1 ����
	if (begin == end) {				// �˻� ������ �� ���� ���
		if (key == a[begin]) printf("%d��°�� �˻� ����\n\n", i);
		else printf("%d��°�� �˻� ����! \n\n", i);
		return;
	}

	middle = (begin + end) / 2;		// �˻� ������ ���� ���ҵǴ� ���� ��ġ ����
	if (key == a[middle]) printf("%d��°�� �˻� ����!\n\n", i);
	else if (key < a[middle] && (middle - 1 >= begin))
		binarySearch(a, begin, middle - 1, key);
	else if (key > a[middle] && (middle + 1 <= end))
		binarySearch(a, middle + 1, end, key);
	else printf("%d��°�� �˻� ����! \n\n", i);
}

void main() {
	element a[] = { 1, 2, 8, 9, 11, 19, 29 }, key;
	int n = 7;

	i = 0; printf("\n %d�� �˻��϶�! ->> ", key = 11);
	binarySearch(a, 0, n - 1, key);		// Ž��Ű�� 11�� ���� �˻�

	i = 0; printf("\n %d�� �˻��϶�! ->> ", key = 6);
	binarySearch(a, 0, n - 1, key);		// Ž��Ű�� 6�� ���� �˻�

	printf("\n %d�� �˻��϶�! ->> ", key = 2); i = 0;
	binarySearch(a, 0, n - 1, key);		// Ž��Ű�� 2�� ���� �˻�

	getchar();
}