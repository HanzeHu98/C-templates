#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node_{
  // A doubly linked list node struct for storing data
  struct linked_list_node_ *next;   // Next Node
  struct linked_list_node_ *prev;   // Previous Node
  // Data can be updated below
  int from_node;       // The source node ID
  int dest_node;         // The destination node ID
} LLNode;

typedef struct linked_list_{
  // A binary heap structure that uses 1 based indexing to implement a binary heap
  LLNode *head;       // An array of BinNode pointers of the actual heap
  LLNode *tail;       // Address of the tail of the linked list
  int size;           // Size of the Linked List
  // Data that can be updated accordingly
  // int originID;       // The ID of the origin ID
} linked_list_t;



/* listCreate - creates a linked_list_t structure and returns a pointer to it
 * 
 * Any data that needs to be added to the linked_list_t structure upon creation
 * can be an input to this function
 */
linked_list_t* list_create();

/* node_create - creates a linked_list_t structure and returns a pointer to it
 * 
 * Any data that needs to be added to the linked_list_t structure upon creation
 * can be an input to this function
 */
LLNode* node_create();


/* list_append - append a LLNode structure to the end of a linked list
 *
 * list: a pointer to the linked_list_t structure to append to
 * node: a LLnode structure to append to the end of list
 */
void list_append(linked_list_t *list, LLNode *node);

/* list_delete - delete a LLNode structure from a linked list
 *
 * list: a pointer to the linked_list_t structure to delete from
 * node: the LLnode structure to delete from the linked list
 */
void list_delete(linked_list_t *list, LLNode *node);

/* print_list - prints the linked list given the head node
 *
 * linked_list: a pointer to the linked_list_t structure to print
 */
void print_list(linked_list_t* linked_list);

/* free_list - frees the linked list given the head node
 *
 * linked_list: a pointer to the linked_list_t structure to free
 */
void free_list(linked_list_t* linked_list);