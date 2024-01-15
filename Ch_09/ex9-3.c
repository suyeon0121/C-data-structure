#include <stdio.h>
typedef int element;
int size, i = 0;

// �ֿ��� �κ����� �ȿ��� �Ǻ� ��ġ�� Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����
int partition(element a[], int begin, int end) {
	int pivot, L, R, t;
	element temp;
	L = begin;
	R = end;
	pivot = (int)((begin + end) / 2.0);		// �߰��� ��ġ�� ���Ҹ� �Ǻ� ���ҷ� ����

	printf("\n [ %d�ܰ� : pivot=%d ] \n", ++i, a[pivot]);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R) {						// L�� R ���Ҹ� �ڸ� ��ȯ
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;

			if (L == pivot)					// L�� �Ǻ��� ���,
				pivot = R;					// ����� �Ǻ� ��ġ(R) ����!
		}									// if(L < R)
	}										// while(L < R)

	// (L = R)�� �� ���,
	// �� �̻� ������ �� �����Ƿ� R ���ҿ� �Ǻ� ������ �ڸ��� ��ȯ�Ͽ� ������
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++) printf(" %d", a[t]);		// ������ ���� ���� ��� 
	printf("\n");
	return R;								// ���ĵǾ� Ȯ���� �Ǻ��� ��ġ ��ȯ
}

void quickSort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end);		// �Ǻ� ��ġ�� ���� ���� ��ġ ����
		quickSort(a, begin, p - 1);			// �Ǻ� ���� �κ����տ� ���� �� ������ ���ȣ��
		quickSort(a, p + 1, end);			// �Ǻ� ������ �κ����տ� ���� �� ������ ���ȣ��
	}
}

void main() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;								// list �迭�� ���� ����
	printf("\n [ �ʱ� ���� ] \n");
	for (int i = 0; i < size - 1; i++) printf(" %d", list[i]);
	printf("\n");

	quickSort(list, 0, size - 1);

	getchar();
}