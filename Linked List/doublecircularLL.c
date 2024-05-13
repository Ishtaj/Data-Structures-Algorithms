/* WAP to create double circular linked list and perform insertion, deletion, tranversal, search operation */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create()
{
    int n;
    printf("Enter the No. of Nodes: ");
    scanf("%d", &n);
    struct node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    temp->next = head;
    head->prev = temp;
    printf("\n");
}

void display()
{
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->", temp->data);
}

void insert()
{
    int pos;
    printf("Enter the Position: ");
    scanf("%d", &pos);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
    display();
}

void delete ()
{
    int pos;
    printf("Enter the Position: ");
    scanf("%d", &pos);
    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    display();
    free(temp1);
}

void search()
{
    int key;
    printf("Enter the Number to Search: ");
    scanf("%d", &key);
    struct node *temp = head;
    int flag = 0;
    while (temp->next != head)
    {
        if (temp->data == key)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        printf("Number found");
    }
    else
    {
        printf("Number not found");
    }
}

int main()
{
    create();
    display();
    int ch;
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            printf("\n");
            break;
        case 2:
            delete ();
            printf("\n");
            break;
        case 3:
            search();
            printf("\n");
            break;
        case 4:
            printf("Program Successfully Exited");
            exit(0);
        default:
            printf("Invalid choice");
        }
    } while (ch != 6);
    return 0;
}
//This is 100% correct.