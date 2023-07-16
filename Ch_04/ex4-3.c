#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ���� ����Ʈ�� ��� ������ ����ü�� ���� 
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ���� 
typedef struct {
	listNode* head;
} linkedList_h;

// ���� ���� ����Ʈ�� �����ϴ� ���� 
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));		// ��� ��� �Ҵ�
	CL->head = NULL;										// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return CL;
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* CL) {
	listNode* p;
	printf(" CL = (");
	p = CL->head;
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

// ù ��° ��� ���� ���� 
void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));			// ������ �� ��� �Ҵ�
	strcpy(newNode->data, x);								
	if (CL->head == NULL) {									// ���� ���� ����Ʈ�� ������ ���
		CL->head = newNode;									// �� ��带 ����Ʈ�� ���� ���� ���� 
		newNode->link = newNode;
	}
	else {													// ���� ���� ����Ʈ�� ������ �ƴ� ���
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;								// ������ ��带 ù ��° ����� new�� ���� ���� 
		CL->head = newNode;
	}
}

// pre �ڿ� ��带 �����ϴ� ���� 
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL) {										// ���� ����Ʈ�� ���
		CL->head = newNode;
		newNode->link = newNode;							// �� ��带 ù ��°���� ������ ���� ����
	}
	else {
		newNode->link = pre->link;							// ������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}

// ���� ���� ����Ʈ�� pre �ڿ� �ִ� ��� old�� �����ϴ� ���� 
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;											// ������ ����� ������ ��带 ��Ÿ���� ������
	if (CL->head == NULL) return;							// ���� ����Ʈ�� ��� ���� ���� �ߴ�
	if (CL->head->link == CL->head) {						// ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(CL->head);										// ù ��° ����� �޸𸮸� �����ϰ� 
		CL->head = NULL;									// ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (old == NULL) return;							// ������ ��尡 ���� ��� ���� ���� �ߴ� 
	else {				
		pre = CL->head;										// ������ pre�� ����Ʈ�� ���� ��忡 ����
		while (pre->link != old) {
			pre = pre->link;								// ������ ��带 ������ pre�� �̿��� ã�� 
		}
		pre->link = old->link;
		if (old == CL->head)
			CL->head = old->link;
		free(old);											// ���� ����� �޸𸮸� ����
	}
}

// ���� ���� ����Ʈ���� x ��带 Ž���ϴ� ���� 
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp;
	temp = CL->head;
	if (temp == NULL) return NULL;
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	} while (temp != CL->head);
	return NULL;
}

int main() {
	linkedList_h* CL;
	listNode* p;
	CL = createLinkedList_h();								// ���� ���� ���� ����Ʈ ����
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	getchar();

	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertFirstNode(CL, "��");
	printList(CL); getchar();

	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printList(CL); getchar();

	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printList(CL); getchar();

	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); deleteNode(CL, p);
	printList(CL); getchar();

	return 0;
}
