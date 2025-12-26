#include "apc.h"

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)

{
    // Step 1: Remove leading zeros
    delete_zeroes_present_at_first(head1);
    delete_zeroes_present_at_first(head2);

    // Step 2: Check division by zero
    if (*head2 == NULL || (*head2)->data == 0)
    {
       // printf("Error: Division by zero\n");
        return FAILURE;
    }

    // Step 3: If dividend < divisor → quotient = 0
    if (compare_list(*head1, *head2) < 0)
    {
        insert_at_last(headR, tailR, 0);
        return SUCCESS;
    }

    // Step 4: Prepare temp (partial remainder)
    Dlist *tempHead = NULL, *tempTail = NULL;
    Dlist *curr = *head1;

    while (curr)
    {
        // Append next digit to remainder
        insert_at_last(&tempHead, &tempTail, curr->data);
        delete_zeroes_present_at_first(&tempHead);

        int count = 0;

        // Subtract divisor until remainder < divisor
        while (compare_list(tempHead, *head2) >= 0)
        {
            Dlist *subHead = NULL, *subTail = NULL; // To hold subtraction result
            // Subtract divisor from temp
            subtraction(&tempHead, &tempTail, head2, tail2, &subHead, &subTail);
            tempHead = subHead;
            tempTail = subTail;
            count++;
        }

        // Add quotient digit
        insert_at_last(headR, tailR, count);

        curr = curr->next; // Move to next digit of dividend
    }

    // Step 5: Remove leading zeros from quotient
    delete_zeroes_present_at_first(headR);

    // Step 6: If quotient became NULL, insert 0
    if (*headR == NULL)
        insert_at_last(headR, tailR, 0);

    return SUCCESS;
}