// Program to add two polynomials using linked list

#include <stdio.h>
#include <stdlib.h>

/* defining structure of each node */

struct Node
{
    int co;
    int ex;
    struct Node *next;     
};


/* function to insert nodes in resultant polynomial */

struct Node * insert (struct Node * Head3, int ex1, int co1)
{
    struct Node * New, * PTR;

    New = (struct Node *)malloc(sizeof(struct Node));

    New -> ex = ex1;
    New -> co = co1;
    New -> next = NULL;

    if (Head3 == NULL)
    {
        Head3 = New;
    }
    else
    {
        PTR = Head3;

        while (PTR -> next != NULL)
        {
            PTR = PTR -> next;
        }

        PTR -> next = New;
    }

    return (Head3);
}


/*  Function to create linked list to store polynomial data */

struct Node * Create (struct Node * Head)
{
    Head = NULL;
    
    struct Node * New, * PTR;

    New = (struct Node *) malloc (sizeof (struct Node)); // creating the first node

    printf("Enter the coefficient and exponent of the term:\n");
    scanf ("%d%d", &New -> co, &New -> ex);

    New -> next = NULL;
    Head = New; // Head pointing to the first node

    PTR = Head;

    char ch;

    printf("Do you want to add another term (y/n):\n");
    scanf (" %c", &ch);

    loop:

    while (ch == 'y' || ch == 'Y')
    {
        struct Node * Newnode;
        Newnode = (struct Node *)malloc(sizeof (struct Node));

        printf("Enter the coefficient and exponent of the term:\n");
        scanf ("%d%d", &Newnode -> co, &Newnode -> ex);

        Newnode -> next = NULL;
        PTR = Newnode;

        char chnew;

        printf("Do you want to add another term (y/n):\n");
        scanf (" %c", &chnew);

        if (chnew == 'y' || chnew == 'Y')
        {
            goto loop;
        }

        else if (chnew == 'n' || chnew == 'N')
        {
            break;
        }
        
        else
        {
            printf("\nInvalid input...Terminating program\n");
        }

    }

    return (Head);
}


/* function to add two polynomials */

struct Node * polyadd (struct Node * Head1, struct Node * Head2)
{
    struct Node * Head3, * PTR1, * PTR2;

    PTR1 = Head1;
    PTR2 = Head2;

    Head3 = NULL;

    while (PTR1 != NULL && PTR2 != NULL)
    {
        if (PTR1-> ex == PTR2 -> ex)
        {
            Head3 = insert(Head3, PTR1 -> ex, PTR1 -> co + PTR2 -> co);
            PTR1 = PTR1 -> next;
            PTR2 = PTR2 -> next;
        }
        
        else if (PTR1 -> ex > PTR2 -> ex)
        {
            Head3 = insert(Head3, PTR1 -> ex, PTR1 -> co);
            PTR1 = PTR1 -> next;
        }

        else
        {
            Head3 = insert(Head3, PTR2 -> ex, PTR2 -> co);
            PTR2 = PTR2 -> next;
        }

        // if PTR1 is empty, copy PTR2 data

        while (PTR2 != NULL)
        {
            Head3 = insert(Head3, PTR2 -> ex, PTR2 -> co);
        }

        while (PTR1 != NULL)
        {
            Head3 = insert(Head3, PTR1 -> ex, PTR1 -> co);
        }
    }

    return (Head3);
}


/* Driver Code */

int main()
{
    struct Node *Head1, *Head2;
    struct Node * PTR;

    Head1 = NULL;
    Head2 = NULL;

    printf("POLYNOMIAL 1:\n\n");

    Create (Head1);

    printf("\nPOLYNOMIAL 2:\n\n");

    Create (Head2);

    struct Node *Head3 = polyadd (Head1, Head2);

    PTR = Head3;

    printf ("\nThe resultant polynomial is: ");

    while (PTR != NULL)
    {
        printf("%dx^%d + ", PTR -> co, PTR -> ex);
    }

    printf("\b\b\b");
    printf(" ");

    return 0;
}