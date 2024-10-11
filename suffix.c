#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
char suffix[50];
float stack[25];
int top=-1;
float data[30];

float evaluate(char [],float[]);
float pop();
void push(float);

void main()
{
float res;
int i;
printf("enter the suffix expression:");
scanf("%s",suffix);
for(i=0;suffix[i]!='\0';i++)
{
if(isalpha(suffix[i]))
{
  fflush(stdin);
  printf("\nEnter value for %c :",suffix[i]);
  scanf("%f",&data[i]);
}
}
res=evaluate(suffix,data);
printf("The result of %s is %.2f",suffix,res);
}

float evaluate(char s[], float d[])
{
float op1,op2;
char c;
for(int i=0; s[i]!='\0';i++)
{
c=s[i];
if(isalpha(s[i]))
  push(d[i]);
else
{
 op2=pop();
 op1=pop();
 switch(c)
{
case '+': push(op1+op2); break;
case '-': push(op1-op2); break;
case '*': push(op1*op2);break;
case '/': push(op1/op2); break;
case '^': push(pow(op1,op2)); break;
case '%': push((int)(op1)%(int)(op2)); break;
}
}
}
return (pop());
}

void push(float d)
{
stack[++top]=d;
}

float pop()
{
return (stack[top--]);
}

