#include "apc.h"

int modulo(Dlist **head1, Dlist **tail1,
           Dlist **head2, Dlist **tail2,
           Dlist **headR, Dlist **tailR,
           int sign1, int sign2)
{
    
    // Step 1: Remove leading zeros
    delete_zeroes_present_at_first(head1);
    delete_zeroes_present_at_first(head2);

    // Step 2: Division by zero check
    if (*head2 == NULL || (*head2)->data == 0)
    {
       // printf("Error: Modulo by zero\n");
        return FAILURE;
    }

    // Step 3: If dividend < divisor → remainder = 0
    if (compare_list(*head1, *head2) < 0)
    {
        insert_at_last(headR, tailR, 0);
        return SUCCESS;
    }

   // Step 4: Prepare partial remainder (like long division)
    Dlist *tempHead = NULL, *tempTail = NULL;
    Dlist *curr = *head1;

    while (curr)
    {
        // Append current digit to partial remainder
        insert_at_last(&tempHead, &tempTail, curr->data);
        delete_zeroes_present_at_first(&tempHead);

        // Subtract divisor until smaller
        while (compare_list(tempHead, *head2) >= 0)
        {
            Dlist *subHead = NULL, *subTail = NULL;
            subtraction(&tempHead, &tempTail, head2, tail2, &subHead, &subTail);
            tempHead = subHead;
            tempTail = subTail;
        }

        curr = curr->next;
    }

    delete_zeroes_present_at_first(&tempHead);

    // Step 5: If remainder becomes NULL → remainder = 0
    if (tempHead == NULL)
        insert_at_last(&tempHead, &tempTail, 0);

    // Step 6: Assign remainder to result
    *headR = tempHead;
    *tailR = tempTail;

    // Step 7: Sign = dividend’s sign
    if (sign1 < 0 && !((*headR)->data == 0 && (*headR)->next == NULL))
        (*headR)->data = -((*headR)->data);

    return SUCCESS;
}