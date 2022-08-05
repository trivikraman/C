#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct list_node {
   char* name;
   int age;
   struct list_node* previous;
   struct list_node* next;
};

typedef struct list_node node;

int count(node* head) {
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}
	return count;
}

node* get_by_index(int index, node* head) {
	int counter = count(head);
	int i = 0;
	if (index < 0 || index > counter) {
		return NULL;
	}
	for (i = 0; i <= index; i++) {
		if (i == index) {
			return head;
		}
		head = head->next;
	}
	return head;
}

node* remove_first(node* head) {
	head = head->next;
	free(head->previous);
	head->previous = NULL;
	return head;
}

int remove_last(node* head) {
	while(head) {
		if (head->next->next == NULL) {
			free(head->next);
			head->next = NULL;
			return 0;
		}
		head = head->next;
	}
	return -1;
}

node* remove_at_index(int index, node* head) {
	node* current;
	if (index == 0) {
		return remove_first(head);
	} else if ( index < 0) {
		return head;
	}
	current = get_by_index(index, head);
	if (current == NULL) {
		return head;
	}
	current->previous->next = current->next;
	if (current->next != NULL) {
		current->next->previous = current->previous;
	}
	free(current);
	return head;
}

node* add_first(char* name, int age, node* head) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node->name = name;
	new_node->age = age;
    new_node->next = head;
	if (head != NULL) {
		head->previous = new_node;
	}
    head = new_node;
	return head;
}

void add_after(char* name, int age, node* head) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	new_node->name = name;
	new_node->age = age;
	new_node->next = head->next;
	new_node->previous = head;
	new_node->next->previous = new_node;
	head->next = new_node;
}

void add_last(char* name, int age, node* current) {
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	while(current) {
		if (current->next == NULL) {
			current->next = new_node;
			new_node->name = name;
			new_node->age = age;
			new_node->previous = current;
			return;
		}
		current = current->next;
	}
}

void print_list(node* current) {
	printf("HEAD: ");
	while(current) {
		printf("%s %d", current->name, current->age);
		printf(" -> ");
		current = current->next ;
	}
	printf("\b\b\b\b :TAIL\n");
}

void print_list_from_tail(node* current) {
	current = get_by_index(count(current)-1, current);
	printf("TAIL: ");
	while(current) {
		printf("%s %d", current->name, current->age);
		printf(" <- ");
		current = current->previous ;
	}
	printf("\b\b\b\b :HEAD\n");
}

void print_list_backwards(node* current) {
	printf("TAIL: ");
	while(current) {
		printf("%s %d", current->name, current->age);
		printf(" <- ");
		current = current->previous ;
	}
	printf("\b\b\b\b :HEAD\n");
}

int main(void) {
	node* head = NULL;
	node* tail = NULL;
	int number;
	unsigned int age = 0;
	
	/* adding the first element requires setting the head. */
	head = add_first("Alpha", age++, head);
	
	/* adding the rest as the last element. */
	add_last("Bravo", age++, head);
	add_last("Charlie", age++, head);
	add_last("Delta", age++, head);
	add_last("Echo", age++, head);
	add_last("Foxtrot", age++, head);
	add_last("Golf", age++, head);
	add_last("Hotel", age++, head);
	add_last("India", age++, head);
	add_last("Juliet", age++, head);
	add_last("Kilo", age++, head);
	add_last("Lima", age++, head);
	add_last("Mike", age++, head);
	add_last("November", age++, head);
	add_last("Oscar", age++, head);
	add_last("Papa", age++, head);
	add_last("Quebec", age++, head);
	add_last("Romeo", age++, head);
	add_last("Sierra", age++, head);
	add_last("Tango", age++, head);
	add_last("Uniform", age++, head);
	add_last("Victor", age++, head);
	add_last("Whiskey", age++, head);
	add_last("X-ray", age++, head);
	add_last("Yankee", age++, head);
	add_last("Zulu", age++, head);
	
	/* printing the original list. */
	printf("Original List:\n");
	print_list(head);
	tail = get_by_index(count(head)-1, head);
	printf("\nPrinted backwards:\n");
	print_list_backwards(tail);
	printf("\n");
	
	/* remove first element. */
	tail = get_by_index(0, head);
	printf("Remove the first element: [%s %d]\n", tail->name, tail->age);
	head = remove_first(head);
	print_list(head);
	printf("\n");
	
	/* remove last element. */
	tail = get_by_index(count(head)-1, head);
	printf("Remove the last element: [%s %d]\n", tail->name, tail->age);
	number = remove_last(head);
	print_list(head);
	printf("\n");
	
	/* bounds checking says no. */
	head = remove_at_index(-15, head);
	head = remove_at_index(40, head);
	
	/* remove element 15. */
	tail = get_by_index(15, head);
	printf("Remove at index=15: [%s %d]\n", tail->name, tail->age);
	head = remove_at_index(15, head);
	print_list(head);
	printf("\n");
	
	return 0;
}