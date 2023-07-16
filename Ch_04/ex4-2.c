#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ���� 
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
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;			// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ���� 
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// ù ��° ���� �����ϴ� ���� 
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));			// ������ �� ��� �Ҵ�
	strcpy(newNode->data, x);								// �� ����� ������ �ʵ忡 x ����
	newNode->link = L->head;
	L->head = newNode;
}

// ��带 pre �ڿ� �����ϴ� ���� 
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L == NULL) {										// ���� ����Ʈ�� ���
		newNode->link = NULL;								// �� ��带 ù ��°���� ������ ���� ����
		L->head = newNode;
	}
	else if (pre == NULL) {									// ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
		L->head = newNode;									// �� ��带 ù ��° ���� ����
	}
	else {
		newNode->link = pre->link;							// ������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}

// ������ ���� �����ϴ� ���� 
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {									// ���� ����ũ�� ������ ���
		L->head = newNode;									// �� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;			// ���� ����Ʈ�� ������ ��带 ã��
	temp->link = newNode;									// �� ��带 ������ ���(temp)�� ���� ���� ����
}

// ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;											// ������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL) return;							// ���� ����Ʈ��� ���� ���� �ߴ�
	if (L->head->link == NULL) {							// ����Ʈ�� ��尡 �� ���� �ִ� ���	
		free(L->head);										// ù ��° ��带 �޸𸮿��� �����ϰ�
		L->head = NULL;										// ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (p == NULL) return;								// ������ ��尡 ���ٸ� ���� ���� �ߴ�
	else {													// ������ ��� p�� ������ ��带 ������ pre�� �̿��� ã��
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;								// ������ ��� p�� ������ ���� ���� ��带 ����
		free(p);											// ���� ����� �޸� ����
	}
}

// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

// ����Ʈ�� ��� ������ �������� �ٲٴ� ����
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;											// ������ p�� ù ��° ��忡 ����
	q = NULL;
	r = NULL;

	// ����Ʈ�� ù ��° ������ ��ũ�� ���� ���� ���� �̵��ϸ鼭 
	// ��� ���� ������ �ٲ�
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q -> link = r;
	}
	L->head = q;
}

int main() {
	linkedList_h* L;
	listNode* p;
	L = createLinkedList_h();								// ���� ����Ʈ ���� 
	printf("(1) ����Ʈ�� [��], [��], [��] ��� �����ϱ�! \n");
	insertLastNode(L, "��"); insertLastNode(L, "��"); insertLastNode(L, "��");
	printList(L); getchar();

	printf("(2) ����Ʈ�� [��] ��� Ž���ϱ�! \n");
	p = searchNode(L, "��");
	if (p == NULL) printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
	getchar();

	printf("(3) ����Ʈ���� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(L, p, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(L, "��");									// ������ ��� ��ġ p�� ã��
	deleteNode(L, p);										// ������ p ��� ����
	printList(L); getchar();

	printf("(5) ����Ʈ ������ �������� �ٲٱ�! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);									// ����Ʈ�� �޸� ����
	getchar();

	return 0;
}