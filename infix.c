#include<stdio.h>
#include<stdlib.h>
char infix[50],stack[50],postfix[50];
int top=-1;
void push(char);
char pop();
void evaluate();
int prec(char);

void main()
{
printf("Enter infix expression:");
scanf("%s",infix);
evaluate();
printf("\nThe corresponnding postfix expression: %s\n",postfix);
}

void evaluate()
{
char symb,temp;
int i=0,j=0;
push('#');
for(i=0;infix[i]!='\0';i++)
{
symb=infix[i];
switch(symb)
{
case '(':push(symb);break;
case ')':temp=pop();
while(temp!='(')
{
postfix[j]=temp;
j++;
temp=pop();
}
break;
case '+':
case '-':
case '*':
case '/':
case '%':
case '^':
case '$':while((prec(stack[top])) >= (prec(symb)))
{
temp=pop();
postfix[j]=temp;
j++;
}
push(symb); break;
default: postfix[j]=symb; 
j++;
}
}
while(top>0)
{
temp=pop();
postfix[j]=temp;
j++;
}
}

void push(char item)
{
top=top+1;
stack[top]=item;
}

char pop()
{
char item;
item=stack[top];
top=top-1;
return item;
}

int prec(char symb)
{
int p;
switch(symb)
{
case '#': p=-1;break;
case '(':
case ')':p=0;break;
case '+':
case '-':p=1;break;
case '*':
case '/':
case '%':p=2;break;
case '^':
case '$':p=3;break;
}
return p;
}

