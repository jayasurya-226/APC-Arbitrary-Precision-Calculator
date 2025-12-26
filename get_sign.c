#include "apc.h"

// Function to get the sign of the number represented by the linked list
int get_sign(Dlist **head) 
{
    if ((*head)->data < 0)  // Negative number
    {
        (*head)->data = -(*head)->data; // make positive for easy processing
        return -1;
    }
    return 1; // Positive number
}