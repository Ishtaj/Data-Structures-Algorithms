#include<stdio.h>
#include<stdlib.h>

struct node
{
    int row;
    int column;
    int value;
    struct node* next;
};

struct node* createNode(int row,int column,int value){
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->row=row;
    new->column=column;
    new->value=value;
    new->next=NULL;
    return new;
}


void display(struct node* head){
    struct node* ptr = head;
    while(ptr!=NULL){
        printf("%d\t%d\t%d\n",ptr->row,ptr->column,ptr->value);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node* createLL(int r,int c,int mat[r][c])
{
    struct node* head,*new,*ptr;
    head=(struct node*)malloc(sizeof(struct node));
    head->row=r;
    head->column=c;
    head->value=0;
    head->next=NULL;
    ptr=head;
    int size = 0;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (mat[i][j] != 0){
                new=createNode(i,j,mat[i][j]);
                new->next=NULL;
                ptr->next=new;
                ptr=ptr->next;
				size++;
            }
        }
    }
    head->value=size;
    return head;
};

struct node* add(struct node* head1,struct node* head2){
    
    struct node* ptr1=head1->next,*ptr2=head2->next,*ptr,*head;
    head=(struct node*)malloc(sizeof(struct node));
    head->row=head1->row;
    head->column=head1->column;
    head->value=0;
    head->next=NULL;
    ptr=head;
       while(ptr1!=NULL&&ptr2!=NULL)
       {
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->next=NULL;

        if(ptr1->row<ptr2->row)
        {
            new->row=ptr1->row;
            new->column=ptr1->column;
            new->value=ptr1->value;
            ptr1=ptr1->next;
        }

        else if(ptr1->row>ptr2->row)
        {
            new->row=ptr2->row;
            new->column=ptr2->column;
            new->value=ptr2->value;
            ptr2=ptr2->next;
        }

        else
        {
            if(ptr1->column>ptr2->column)
            {
            new->row=ptr2->row;
            new->column=ptr2->column;
            new->value=ptr2->value;
            ptr2=ptr2->next;
            }

            else if(ptr1->column<ptr2->column)
            {
                new->row=ptr1->row;
                new->column=ptr1->column;
                new->value=ptr1->value;
                ptr1=ptr1->next;
            }

            else
            {
                new->row=ptr1->row;
                new->column=ptr1->column;
                new->value=ptr1->value+ptr2->value;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
        }
            ptr->next=new;
            ptr=ptr->next;
    }

    while(ptr1!=NULL)
    {
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        new->row=ptr1->row;
        new->column=ptr1->column;
        new->value=ptr1->value;
        ptr1=ptr1->next;
        ptr->next=new;
        ptr=ptr->next;
    }

    while(ptr2!=NULL)
    {
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        new->row=ptr2->row;
        new->column=ptr2->column;
        new->value=ptr2->value;
        ptr2=ptr2->next;
        ptr->next=new;
        ptr=ptr->next;
    }

    ptr=head->next;
    int size=0;
    while(ptr!=NULL)
    {
        size++;
        ptr=ptr->next;
    }
    head->value=size;

    return head;
}


int main()
{
    struct node *head1,*head2,*head3;
    
    int m,n,p,q;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d",&m,&n);
	int mat[m][n];
    printf("Enter first matrix elements: ");
    for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			scanf("%d",&mat[i][j]);
        }
    }

	
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d",&p,&q);
	int mat2[p][q];
    printf("Enter second matrix elements: ");
    for (int i = 0; i < p; i++)
    {
		for (int j = 0; j < q; j++)
        {
			scanf("%d",&mat2[i][j]);
        }
    }

	head1=createLL(m,n,mat);
    head2=createLL(p,q,mat2);
    printf("Sparse matrix 1:\n");
    display(head1);
    printf("Sparse matrix 2:\n");
    display(head2);

    if(m==p&&n==q)
    {
        head3=add(head1,head2);
        printf("Resultant sparse matrix:\n");
        display(head3);
    }
    
}