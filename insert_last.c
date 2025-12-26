#include "apc.h"
// Function to insert a new node at the end of the doubly linked list
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for new node
    Dlist *newnode = malloc(sizeof(Dlist));
    if (!newnode) return FAILURE;   // Memory allocation failed

    newnode->data = data; // Set data
    newnode->next = NULL; // New node will be the new tail, so next is NULL
    newnode->prev = NULL;  // Prev will be set later

    // If list is empty, new node becomes both head and tail
    if (*head == NULL) {
        *head = *tail = newnode;
        return SUCCESS;
    }
// Link new node at the end
    (*tail)->next = newnode;
    newnode->prev = *tail;
    *tail = newnode;

    return SUCCESS;
}
