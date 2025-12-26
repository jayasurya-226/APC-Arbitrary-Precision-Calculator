#include "apc.h"
// Function to insert a new node at the beginning of the doubly linked list
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));  // Allocate memory for new node
    if (!newnode) return FAILURE;            // Memory allocation failed

    newnode->data = data;  // Set data
    newnode->prev = NULL; //    New node will be the new head, so prev is NULL
    newnode->next = *head;   // Next points to current head

    if (*head != NULL) (*head)->prev = newnode;  // Update old head's prev to new node
    else *tail = newnode;    // If list was empty, new node is also the tail

    *head = newnode; // Update head to new node
    return SUCCESS;  // Insertion successful
}
