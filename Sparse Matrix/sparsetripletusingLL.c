#include<stdio.h>
#include<stdlib.h>

struct node
{
    int row;
    int column;
    int value;
    struct node* next;
};

struct node* createNode(int row,int column,int value)
{    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->row=row;
    new->column=column;
    new->value=value;
    new->next=NULL;
    return new;
}


void display(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
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
	for (int i = 0; i < r; i++)
    {
		for (int j = 0; j < c; j++)
        {
			if (mat[i][j] != 0)
            {
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


int main()
{
    struct node *head;
    
    int m,n,p,q;
    printf("Enter rows and columns of the sparse matrix: ");
    scanf("%d %d",&m,&n);

	int mat[m][n];

    printf("Enter the matrix elements: ");

    for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			scanf("%d",&mat[i][j]);
        }
    }

	head=createLL(m,n,mat);
    printf("\nSparse matrix triplet representation:\n\n");
    printf("Row\tColumn\tValue\n---\t------\t-----\n\n");
    display(head);

    return 0;    
}