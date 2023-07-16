#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� ���� ����Ʈ�� ��� ������ ����ü�� ���� 
typedef struct ListNode {
	struct ListNode* llink;									// ����(����) ��忡 ���� ��ũ
	char data[4];											
	struct ListNode* rlink;									// ������(����) ��忡 ���� ��ũ
} listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ���� 
typedef struct {
	listNode* head;
} linkedList_h;

// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));		// ��� ��� �Ҵ�
	DL->head = NULL;										// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return DL;
}

// ���� ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* DL) {
	listNode* p;
	printf(" DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// pre �ڿ� ��带 �����ϴ� ����
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)							// ���� �ڸ��� ���� ��尡 �ִ� ���
			newNode->rlink->llink = newNode;
	}
}

// ���� ���� ����Ʈ���� old ��带 �����ϴ� ���� 
void deleteNode(linkedList_h* DL, listNode* old) {
	if (DL->head == NULL) return;							// ���� ����Ʈ�� ��� ���� ���� �ߴ�
	else if (old == NULL) return;							// ������ ��尡 ���� ��� ���� ���� �ߴ�
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);											// ���� ����� �޸� ����
	}
}

// ����Ʈ���� x ��带 Ž���ϴ� ���� 
listNode* searchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}

int main() {
	linkedList_h* DL;
	listNode* p;
	DL = createLinkedList_h();								// ���� ����Ʈ ����
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	printList(DL); getchar();

	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertNode(DL, NULL, "��");
	printList(DL); getchar();

	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(DL, "��"); insertNode(DL, p, "��");
	printList(DL); getchar();

	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(DL, "��"); insertNode(DL, p, "��");
	printList(DL); getchar();

	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(DL, "��"); deleteNode(DL, p);
	printList(DL); getchar();

	return 0;
}
