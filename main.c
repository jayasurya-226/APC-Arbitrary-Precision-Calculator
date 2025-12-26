#include "apc.h"
#include <ctype.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: ./a.out <num1> <operator> <num2>\n");
        return 1;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    // ----- Operand & Operator -----
    const char *num1 = argv[1];
    const char *op = argv[2];
    const char *num2 = argv[3];

    // ----- Validate Operator -----
    if (strlen(op) != 1 || !(strchr("+-x/%", op[0]))) {
        printf("Error: Invalid operator '%s'\n", op);
        return 1;
    }

    // ----- Detect and Handle Signs -----
    int sign1 = 1, sign2 = 1;

    if (num1[0] == '-') {
        sign1 = -1;
        num1++;
    } else if (num1[0] == '+') {
        num1++;
    }

    if (num2[0] == '-') {
        sign2 = -1;
        num2++;
    } else if (num2[0] == '+') {
        num2++;
    }

    // ----- Validate Operands -----
    for (int i = 0; num1[i]; i++) {
        if (num1[i] < '0' || num1[i] > '9') {
            printf("Error: Invalid operand 1. Only digits 0-9 are allowed.\n");
            return 1;
        }
    }
    for (int i = 0; num2[i]; i++) {
        if (num2[i] < '0' || num2[i] > '9') {
            printf("Error: Invalid operand 2. Only digits 0-9 are allowed.\n");
            return 1;
        }
    }

    // ----- Convert Numbers to Linked Lists -----
    convert_to_list(&head1, &tail1, num1);
    convert_to_list(&head2, &tail2, num2);

    // ----- Print Operands -----
    printf("\nOperand 1: %s (Sign: %d)\n", argv[1], sign1);
    print_list(head1);

    printf("Operand 2: %s (Sign: %d)\n", argv[3], sign2);
    print_list(head2);

    printf("\nPerforming Operation: %s\n\nResult:\n", op);

    // ----- Perform Operation -----
    switch (op[0]) {
        case '+': {
            if (sign1 == sign2)
    {
        // Same signs → perform addition
        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);

        // If both were negative, make result negative
        if (sign1 == -1)
            headR->data = -(headR->data);
    }
    else
    {
        // Different signs → perform subtraction
        int cmp = compare_list(head1, head2);

        if (cmp == 0)
        {
            insert_at_first(&headR, &tailR, 0);
        }
        else if (cmp > 0)
        {
            // num1 has greater magnitude
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            if (sign1 == -1)
                headR->data = -(headR->data); // result follows num1's sign
        }
        else
        {
            // num2 has greater magnitude
            subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
            if (sign2 == -1)
                headR->data = -(headR->data); // result follows num2's sign
        }
    }

    delete_zeroes_present_at_first(&headR);
    print_list(headR);
    break;
           }


        case '-': {
           if (sign1 == sign2)
    {
        // both operands have same sign → do subtraction
        int cmp = compare_list(head1, head2);

        if (cmp == 0)
        {
            insert_at_first(&headR, &tailR, 0);
        }
        else if (cmp > 0)
        {
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            if (sign1 == -1)  // e.g. (-5) - (-2) = -3
                headR->data = -(headR->data);
        }
        else
        {
            subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
            if (sign1 == 1)   // e.g. (2) - (5) = -3
                headR->data = -(headR->data);
        }
    }
    else
    {
        // operands have different signs → perform addition
        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);

        // sign of result follows first operand
        if (sign1 == -1)
            headR->data = -(headR->data);
    }

    delete_zeroes_present_at_first(&headR);
    print_list(headR);
    break;
}
        case 'x':
        case 'X':
        case '*': {
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
             if ((sign1 == -1 && sign2 == 1) || (sign1 == 1 && sign2 == -1))
    {
        // If one operand is negative, make result negative
        if (headR)
            headR->data = -(headR->data);
    }

    delete_zeroes_present_at_first(&headR);
    print_list(headR);
    break;
}

        case '/': {
            int div_status = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);

    if (div_status == FAILURE)
    {
        printf("Error: Division by zero\n");
    }
    else
    {
        // --- Handle sign: ( - / + ) or ( + / - ) => negative result ---
        if ((sign1 == -1 && sign2 == 1) || (sign1 == 1 && sign2 == -1))
        {
            if (headR)
                headR->data = -(headR->data);
        }

        delete_zeroes_present_at_first(&headR);
        print_list(headR);
    }
    break;
}
        case '%': {
           int mod_status = modulo(&head1, &tail1, &head2, &tail2, &headR, &tailR, sign1, sign2);
    if (mod_status == FAILURE)
    {
        printf("Error: Modulo by zero\n");
    }
    else
    {
        // --- Handle sign ---
        // In C, result of (a % b) takes the sign of the dividend (a)
        if (sign1 == -1)
        {
            if (headR)
                headR->data = -(headR->data);
        }

        delete_zeroes_present_at_first(&headR);
        print_list(headR);
    }
    break;
              }

    printf("\n");
    return 0;
            }
}
