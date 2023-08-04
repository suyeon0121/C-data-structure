#include <stdio.h>
#include <stdlib.h>
#define cQ_SIZE 4

typedef char element;										// ť ����(element)�� �ڷ����� char�� ���� 
typedef struct {
	element queue[cQ_SIZE];									// 1���� �迭 ť ���� 
	int front, rear;
} QueueType;

// ���� ���� ť�� �����ϴ� ����
QueueType* createQueue() {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;											// front �ʱ갪 ����
	cQ->rear = 0;											// rear �ʱ갪 ����
	return cQ;
}

// ���� ť�� ���� �������� �˻��ϴ� ���� 
int isEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) {
		printf(" Circular Queue is empty! ");
		return 1;
	}
	else return 0;
}

// ���� ť�� ��ȭ �������� �˻��ϴ� ���� 
int isFull(QueueType* cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {
		printf(" Circular Queue is full! ");
		return 1;
	}
	else return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ���� 
void enQueue(QueueType* cQ, element item) {
	if (isFull(cQ)) return;									
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

// ���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deQueue(QueueType* cQ) {
	if (isEmpty(cQ)) exit(1);									
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ���� 
element peek(QueueType* cQ) {
	if (isEmpty(cQ)) exit(1);								// ���� �����̸� ���� �ߴ� 
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

// ���� ť�� ���Ҹ� ����ϴ� ���� 
void printQ(QueueType* cQ) {
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ] ");
}

void main(void) {
	QueueType* cQ = createQueue();							// ť ����
	element data;
	printf("\n ***** ���� ť ���� ***** \n");
	printf("\n ���� A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n ���� B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n ���� C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ); printf(" peek item : %c \n", data);
	printf("\n ����  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������ : %c", data);
	printf("\n ����  >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t\t���� ������ : %c", data);
	printf("\n ���� D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n ���� E>>"); enQueue(cQ, 'E'); printQ(cQ);
	getchar();
}