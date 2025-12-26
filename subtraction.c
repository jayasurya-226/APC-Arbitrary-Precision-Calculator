
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    int borrow = 0, diff;  // To hold borrow and difference

    // Step 1: Find which number is larger
    Dlist *t1 = *head1, *t2 = *head2;
    int len1 = 0, len2 = 0;

    while (t1)  // Calculate lengths
    {
        len1++;
        t1 = t1->next;  // Move to next node
    }
    while (t2)
    {
        len2++;
        t2 = t2->next;  // Move to next node
    }

    Dlist *bigTail, *smallTail; // Pointers to larger and smaller numbers
    int sign = 1;               // To track if result should be negative

    if (len1 > len2)           // First number is larger
    {
        bigTail = *tail1;     // larger number
        smallTail = *tail2;   // smaller number
    }
    else if (len1 < len2)
    {
        bigTail = *tail2;     // larger number
        smallTail = *tail1;  // smaller number
        sign = -1;
    }
    else
    {
        // If equal length, compare digit by digit
        t1 = *head1; t2 = *head2;
        while (t1 && t2 && t1->data == t2->data)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
// Determine larger number based on first differing digit
        if (t1 && t2 && t1->data < t2->data)
        {
            bigTail = *tail2; 
            smallTail = *tail1;
            sign = -1;
        }
        else
        {
            bigTail = *tail1;
            smallTail = *tail2;
        }
    }

    // Step 2: Perform subtraction
    Dlist *temp1 = bigTail;
    Dlist *temp2 = smallTail;

    // Subtract digits from least significant to most
    while (temp1 || temp2)
    {
        int val1 = (temp1) ? temp1->data : 0;//
        int val2 = (temp2) ? temp2->data : 0;
// Adjust val1 if there was a borrow from previous digit
        val1 -= borrow;

        if (val1 < val2)
        {
            val1 += 10; // Borrow from next higher digit
            borrow = 1;  // Set borrow for next iteration
        }
        else
        {
            borrow = 0; // Reset borrow
        }

        diff = val1 - val2; // Calculate difference
        insert_at_first(headR, tailR, diff);
// Move to next higher digit
        if (temp1)
        temp1 = temp1->prev;
        if (temp2)
        temp2 = temp2->prev;
    }

    // Step 3: Remove leading zeros
    delete_zeroes_present_at_first(headR);

    // Step 4: Handle negative sign
    if (sign == -1)
    {
        (*headR)->data = -((*headR)->data);
    }

    delete_zeroes_present_at_first(headR);  // Final cleanup of leading zeros

    return SUCCESS;
}
