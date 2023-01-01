// Program to evaluate postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 50

int top = -1;
int stack[max];
int A,B,val;

void push(char ch)
{
    if (top == max - 1)
        printf("Stack Overflow");
    else
        stack[++top] = ch;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return 0;
    }

    else
    {
        val = stack[top];
        top--;
        return val;
    }
        
}


int main()
{
    char exp[max];
    printf("Enter the postfix expression:\n");
    gets(exp);

    int n = strlen(exp);
    /* debugging line
    printf ("String length: %d\n", n);
    */

    int val1, val2, valfinal;

    for (int i=0; i<n; i++)
    {
        if (exp[i] == '0' || exp[i] == '1' ||
            exp[i] == '2' || exp[i] == '3' ||
            exp[i] == '4' || exp[i] == '5' ||
            exp[i] == '6' || exp[i] == '7' ||
            exp[i] == '8' || exp[i] == '9')
        {
            int digitval = exp[i] - '0';
            push(digitval);
        }

        else if(exp[i] == '+' || exp[i] =='-'|| exp[i] =='*'|| exp[i] =='/')
        {
			A = pop();
			B = pop();
			
			switch(exp[i])
            {
				case'+':
					val=B+A;
					break;
				case'-':
					val=B-A;
					break;
				case'*':
					val=B*A;
					break;
				case'/':
					val=B/A;
					break;		
			}

			push(val);
		}
    }

    printf("\nThe result of the evaluation of the postfix expression is %d", stack[top]);

    return 0;
}