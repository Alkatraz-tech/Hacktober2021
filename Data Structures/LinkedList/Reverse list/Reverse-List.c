#include <stdio.h> 
#include <stdlib.h> 

struct Node {
	int data;
	struct Node* next;
};

static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL) {
		
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;

	printf("Enter the size of linked list you wish to reverse: ");
	int sizeof_linkedlist;
	scanf("%d", &sizeof_linkedlist);

	printf("Enter space separated inputs for the linked list: ");
	int input;
	for (int i = 0; i < sizeof_linkedlist; i++) {
		scanf("%d", &input);
		push(&head, input);
	}

	printf("Given linked list\n");
	printList(head);
	reverse(&head);
	printf("\nReversed Linked list \n");
	printList(head);
	getchar();
}