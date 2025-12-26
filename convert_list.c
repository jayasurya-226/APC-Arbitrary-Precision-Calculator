#include "apc.h"

void convert_to_list(Dlist **head, Dlist **tail, const char *num)
{
    for (int i = 0; num[i]; i++)  // Iterate through each character in the string
    {
        if (num[i] >= '0' && num[i] <= '9')  // Ensure it's a digit
            insert_at_last(head, tail, num[i] - '0'); // Convert char to int and insert
    }
}