#include "apc.h"

void delete_zeroes_present_at_first(Dlist **headR)
{
    if (*headR == NULL) return;  // Empty list, nothing to delete

    Dlist *temp = *headR;  // Start from head

    while (temp && temp->data == 0 && temp->next != NULL)  // While leading zero and not the only node
    {
        Dlist *del = temp;  // Node to delete
        temp = temp->next;   // Move to next node
        temp->prev = NULL;   // Update prev pointer of new head
        free(del);          // Free the deleted node
    }

    *headR = temp;  // Update head to new head
}
