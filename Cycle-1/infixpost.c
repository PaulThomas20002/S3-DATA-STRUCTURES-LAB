#include<stdio.h>
#include<stdlib.h>  /* for exit(0)*/
#include<ctype.h>   /* for isalnum(char ) */

char stack[100];  /* declared here as global variable because stack[]* is used by more than one functions */

int top = -1;

void push(char x)       /* define push operation */
{
    if(top >= 100-1)
    printf("\nStack Overflow.");
    else
    stack[++top] = x;
}

char pop()              /* define pop operation */
{
    if(top == -1){
        printf("stack under flow: invalid infix expression");
        exit(0);
    }
    else
        return stack[top--];
}

/* define function that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this function we assume that higher integer value
* means higher precendence */

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')        /* lowest precedence */
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')            /* exponent operator, highest precedence*/
        return 3;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the Expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')                    /* run loop till end of infix expression */
    {
        if(isalnum(*e))             //( isdigit(item) || isalpha(item))
            printf("%c ",*e);       /*if it is a operand , then direct to output*/
        else if(*e == '(')           
            push(*e);               /* push '(' onto stack */
        else if(*e == ')')
        {
            while((x = pop()) != '(')         /* pop and keep popping until '(' encounterd  */
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))     /* so pop all higher precendence operator and */
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
