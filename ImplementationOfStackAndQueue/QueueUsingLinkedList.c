#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** tail, struct Node** head, int data) {
	
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn -> data = data;
	nn -> next = NULL;
	if(*tail == NULL || *head == NULL) {
		*head = nn;
		*tail = nn;
	}else{
		(*tail) -> next = nn;
		*tail = nn;
	}
}

int isEmpty(struct Node** tail, struct Node** head) {
	return *head == NULL;
}

int pop(struct Node** tail, struct Node** head) {
	if(isEmpty(tail, head))
		return -999;
	struct Node* temp = *head;
	int d = temp -> data;
	*head = (*head) -> next;
	free(temp);
	return d;
}

int peek(struct Node** tail, struct Node** head) {
	if(isEmpty(tail, head))
		return -999;

	return (*tail) -> data;
}


int main() {

	struct Node* tail = NULL;
	struct Node* head = NULL;	



	push(&tail, &head, 10);
	push(&tail, &head, 12);
	push(&tail, &head, 13);
	push(&tail, &head, 14);
	printf("%d\n", isEmpty(&tail, &head));
	printf("%d\n", pop(&tail, &head));
	printf("%d\n", pop(&tail, &head));
	printf("%d\n", pop(&tail, &head));
	printf("%d\n", pop(&tail, &head));
	printf("%d\n", pop(&tail, &head));	
	printf("%d\n", peek(&tail, &head));




}