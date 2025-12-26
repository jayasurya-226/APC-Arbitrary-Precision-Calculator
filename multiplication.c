
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    // Step 1: If any number is zero, answer is zero
    delete_zeroes_present_at_first(head1); // Remove leading zeroes
    delete_zeroes_present_at_first(head2);  // Remove leading zeroes

    if (*head1 == NULL || (*head1)->data == 0 ||   
        *head2 == NULL || (*head2)->data == 0) 
    {
        insert_at_last(headR, tailR, 0);
        return SUCCESS;
    }

    Dlist *ptr2 = *tail2;
    int pos_shift = 0;

    // Step 2: Multiply each digit of num2 with num1 (like row-wise multiplication)
    while (ptr2)  
    {
        int carry = 0;
        Dlist *tempRowHead = NULL;
        Dlist *tempRowTail = NULL;

        // Add required shifting (like placing zeros at end in school method)
        for (int i = 0; i < pos_shift; i++)
            insert_at_last(&tempRowHead, &tempRowTail, 0);

        int digit2 = ptr2->data;
        Dlist *ptr1 = *tail1;

        // Multiply digit2 with each digit of num1
        while (ptr1)
        {
            int mul = digit2 * ptr1->data + carry;
            carry = mul / 10;
            mul = mul % 10;
            insert_at_first(&tempRowHead, &tempRowTail, mul);
            ptr1 = ptr1->prev;
        }
        if (carry)
            insert_at_first(&tempRowHead, &tempRowTail, carry);

        // Step 3: Add this row to result
        if (*headR == NULL)
        {
            *headR = tempRowHead;
            *tailR = tempRowTail;
        }
        
        else
        {
            // Add tempRow to current result in headR
            Dlist *sumHead = NULL;
            Dlist *sumTail = NULL;
            addition(headR, tailR, &tempRowHead, &tempRowTail, &sumHead, &sumTail);
            *headR = sumHead;
            *tailR = sumTail;
        }

        pos_shift++;  // Increase position shift for next higher digit
        ptr2 = ptr2->prev;  // Move to next digit of num2
    }

    delete_zeroes_present_at_first(headR); // Remove leading zeros from result
    return SUCCESS;
}
