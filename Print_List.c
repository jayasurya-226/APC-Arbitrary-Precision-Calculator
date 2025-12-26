#include "apc.h"

// Utility function to print the linked list representation of the number
void print_list(Dlist *head)
{
   if (head == NULL)
    {
        printf("head-><-tail\n"); // Empty list
        return;
    }

    // Temporary pointer to traverse the list
    Dlist *temp = head;

    printf("head->");  // Print head indicator

    while (temp)
    {
        // Print data directly (handles both positive and negative digits)
        printf("%d", temp->data);

        if (temp->next)
            printf("->");  // Print arrow if not the last node

        temp = temp->next;  // Move to next node
    }

    printf("<-tail\n");  // Print tail indicator
}