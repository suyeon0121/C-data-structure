#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;										// ���� ����(element)�� �ڷ����� int�� ����

element stack[STACK_SIZE];									// 1���� �迭 ���� ����
int top = -1;												// top �ʱ�ȭ 

// ������ ���� �������� Ȯ���ϴ� ���� 
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// ������ ��ȭ �������� Ȯ���ϴ� ���� 
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ���� 
void push(element item) {
	if (isFull()) {											// ������ ��ȭ ������ ���
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;								// top�� ������Ų �� ���� top�� ���� ����
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	if (isEmpty()) {										// ������ ���� ������ ���
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];								// ���� top�� ���Ҹ� ������ �� top ����
}

// ������ top ���Ҹ� �˻��ϴ� ���� 
element peek() {
	if (isEmpty()) {										// ������ ���� ������ ���
		printf("\n\n Stack is Empty !\n");
		exit(1);
	}
	else return stack[top];									// ���� top�� ���� Ȯ��
}

// ������ ���Ҹ� ����ϴ� ���� 
void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

void main(void) {
	element item;
	printf("\n** ���� ���� ���� **\n");
	printStack();
	push(1);	printStack();								// 1 ����
	push(2);	printStack();								// 2 ����
	push(3);	printStack();								// 3 ����

	item = peek(); printStack();							// ���� top�� ���� ��� 
	printf("peek => %d", item);

	item = pop(); printStack();								// ����		
	printf("\t pop => %d", item);

	item = pop(); printStack();								// ����
	printf("\t pop => %d", item);

	item = pop(); printStack();								// ����
	printf("\t pop => %d", item);

	getchar();
}