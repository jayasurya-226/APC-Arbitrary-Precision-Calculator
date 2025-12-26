#include "apc.h"

int compare_list(Dlist *head1, Dlist *head2) 
{
    // Compare lengths first, then digit by digit
    int len1 = 0, len2 = 0; // lengths of both lists
    Dlist *t1 = head1, *t2 = head2;  // temp pointers
    while (t1) { len1++; t1 = t1->next; } // count length of first list
    while (t2) { len2++; t2 = t2->next; }  // count length of second list

    if (len1 > len2) return 1;  // first list is larger
    if (len2 > len1) return -1;  // second list is larger

    // same length — compare digits
    t1 = head1; t2 = head2;
    while (t1 && t2)
    {
        if (t1->data > t2->data) return 1;  // first list is larger
        if (t1->data < t2->data) return -1; // second list is larger
        t1 = t1->next;   // move to next digit  
        t2 = t2->next;   // move to next digit
    }
    return 0;
}