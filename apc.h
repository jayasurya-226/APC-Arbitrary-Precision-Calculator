#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

/* Pillar Functions */
int insert_at_first(Dlist **head, Dlist **tail, int data);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int compare_list(Dlist *head1, Dlist *head2);
void delete_zeroes_present_at_first(Dlist **headR);
int delete_list(Dlist **head, Dlist **tail);
int get_sign(Dlist **head);
int compare_list(Dlist *head1, Dlist *head2);
void convert_to_list(Dlist **head, Dlist **tail, const char *num);


/* Arithmetic Functions */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);
int modulo(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
           Dlist **headR, Dlist **tailR,int sign1 , int sign2);

/* Utility */
void print_list(Dlist *head);

#endif
