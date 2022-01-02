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
