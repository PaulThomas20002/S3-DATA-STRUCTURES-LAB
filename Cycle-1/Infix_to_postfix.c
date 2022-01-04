/*
Algorithm to convert Infix to postfix expression
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.

Algorithm for evaluation postfix expressions. 
1) Create a stack to store operands (or values). 
2) Scan the given expression and do the following for every scanned element. 
…..a) If the element is a number, push it into the stack 
…..b) If the element is an operator, pop 2 operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
3) When the expression is ended, the number in the stack is the final answer
*/

/* This program converts infix expression to postfix expression.
* This program assume that there are Five operators: (*, /, +, -,^) 
in infix expression and operands can be of single-digit only.
* This program will not work for fractional numbers.
* Further this program does not check whether infix expression is 
valid or not in terms of number of operators and operands.*/

#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isalnum(char ) */
#include<string.h>    /* for strcat() */
#define SIZE 100


/* declared here as global variable because stack[]
* is used by more than one functions */

char stack[SIZE];
int top = -1;

/* define push operation */

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/* define pop operation */
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

/* define function that is used to determine whether any symbol is operator or not
(that is symbol is operand)
* this function returns 1 if symbol is operator else return 0 */

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */

int precedence(char symbol)
{
	if(symbol == '^')                               /* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if(isalnum(item))  //( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			
                  /* because just above while loop will terminate we have
			popped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	
	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}

/* main function begins */

int main()
{
	char infix[SIZE], postfix[SIZE];         /* declare infix string and postfix string */

	/* why we asked the user to enter infix expression
	* in parentheses ( )
	* What changes are required in porgram to
	* get rid of this restriction since it is not
	* in algorithm
	* */
	printf("\nEnter Infix expression : ");
	scanf("%s",infix);

	InfixToPostfix(infix,postfix);                   /* call to convert */
	
      printf("Postfix Expression: ");
	printf("%s",postfix);                     /* print postfix expression */

	return 0;
}
