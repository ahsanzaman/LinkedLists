/*
Simple simply linked list code in c
*/
#include <stdio.h>
#include <stdlib.h>

// macro for debugging
#define NDEBUG

struct Node {
	int num;
	struct Node *next;
};

// function definitions
void printMenu();
void printList( struct Node *head, struct Node *temp);
void insertNodeSort( struct Node *head, struct struct Node *temp);
void deleteList( struct Node *head);

int main( int argc, char* argv[] ){
	// test linked lists here
}

// printing the sorted list using a traversal pointer
void printList( struct Node *head ) {
	struct Node *trav;
	trav=head->next;
	printf("List: ");
	while( trav!=NULL ) {
		printf("%d ", trav->num);
		trav = trav->next;
	}
	printf("\n");
}

// inserting a node into the list keeping the list sorted ascending.
void insertNodeSort( struct Node *head, struct Node *temp ) {
	if( head->next!=NULL ) {
		// trav through list 

		#ifndef NDEBUG		// printing a marker for debugging 
		printf("\nInsert Node function\n");
		#endif
	
		struct Node *curr = head;

		// traversing to the place in the list where node is to be inserted
		while( curr->next!=NULL ) {
			// keep traversing if the next node has a num less than temp->num
			// this works because here the head is a dummy node
			if( curr->next->num < temp->num ) curr=curr->next;
			// when next num is less than or equal to temp->num insert at current node 
			else if( curr->next->num >= temp->num ) {
				#ifndef NDEBUG 	
				printf("\nInsert node here.\n");
				#endif

				// insert node here
				temp->next=curr->next;
				curr->next=temp;
				break;
			}
			if( curr->next==NULL ) {
				#ifndef NDEBUG
				printf("\nNull Condition.\n");
				#endif
				curr->next=temp;
				break;
			}
		}
	}
	else {
		// in the event that this is the first node in the list
		head->next = temp;
	}
}

// systematically delete each node using a traversal pointer
// free memory for every node to delete it
void deleteList( struct Node *head ){ 
	// check for empty list
	if( head->next!=NULL ) {
		while( head->next!=NULL ) {
			struct Node *curr = head->next;
			head->next=curr->next;
			#ifndef NDEBUG
			printf("\nDeleting %d\n", curr->num);
			#endif
			free(curr);
		}	
	}
	free(head);
	printf("\nList freed.\n");
}
