#include "apc.h"

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    // Determine signs of both numbers
    int sign1 = get_sign(head1);    
    int sign2 = get_sign(head2);
    int carry = 0, sum = 0;

    if (sign1 == sign2)
    {
        // --- Case 1 & 2: same signs ---
        Dlist *temp1 = *tail1;
        Dlist *temp2 = *tail2;
       // Perform addition from least significant digit
        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            
            int val1 = (temp1) ? temp1->data : 0; // Get digit or 0 if list exhausted
            int val2 = (temp2) ? temp2->data : 0; // Get digit or 0 if list exhausted

            sum = val1 + val2 + carry; // Calculate sum including carry
            carry = sum / 10;   // Update carry for next iteration
            sum = sum % 10;     // Digit to store in result

            insert_at_first(headR, tailR, sum); // Insert sum digit at front of result list

            if (temp1) temp1 = temp1->prev; // Move to next digit
            if (temp2) temp2 = temp2->prev;  // Move to next digit
        }

      //  if (sign1 == -1)
         //   (*headR)->data = -(*headR)->data; // mark result as negative
    }
    else
    {
        // --- Case 3: signs different → perform subtraction ---
        int cmp = compare_list(*head1, *head2);
        if (cmp == 0)
        {
            insert_at_first(headR, tailR, 0);
            return SUCCESS;
        }
      // Identify larger and smaller absolute values
        Dlist *bigHead, *bigTail; // larger number
        Dlist *smallHead, *smallTail; // smaller number
        int resultSign;

        if (cmp > 0) // first number is larger
        {
            bigHead = *head1; bigTail = *tail1; 
            smallHead = *head2; smallTail = *tail2;
            resultSign = sign1;
        }
        else
        {
            // second number is larger
            bigHead = *head2; bigTail = *tail2;
            smallHead = *head1; smallTail = *tail1;
            resultSign = sign2;
        }

        // perform subtraction: big - small
        subtraction(&bigHead, &bigTail, &smallHead, &smallTail, headR, tailR);

        if (resultSign == -1)
            (*headR)->data = -(*headR)->data; // mark result as negative
    }

    delete_zeroes_present_at_first(headR); // Remove leading zeros from result

    return SUCCESS;
}
