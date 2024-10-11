#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],top=-1;
int flag=1,temp,item;
int rev[MAX];
void push();
void pop();
void pali();
void display();

int main()
{
int ch,i;
printf("1.Push\n2.pop\3.pali\4.display\n5.exit\n");
while(1)
{
printf("\nEnter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:push(); break;
case 2:pop();
if(flag)
  printf("\nThe popped element is: %d\n",item);
temp=top;
break;
case 3:pali();
top=temp;
break;
case 4:display(); break;
case 5:exit(0);
}
}
return 0;
}

void push()
{
if(top==(MAX-1))
{
printf("\nOverflow\n");
return;
}
else
{
printf("Enter elemnt to be inserted:\n");
scanf("%d",&item);
top=top+1;
stack[top]=item;
}
temp=top;
}

void pop()
{
if(top==-1)
{
printf("UNDERFLOW\n");
flag=0;
}
else
{
item=stack[top];
top=top-1;
}
}

void pali()
{
int i;
if(top==-1)
{
printf("\nPush some elements");
}
else
{
while(top!=-1)
{
rev[top]=stack[top];
pop();
}
top=temp;
for(i=0;i<=temp;i++)
{
if(stack[top--]==rev[i])
{
if(i==temp)
{
printf("\nPalindrome");
return;
}
}
}
printf("\nNot palindrome");
}
}

void display()
{
int i;
top=temp;
if(top==-1)
{
printf("\nEmprty");
}
else
{
printf("\nThe elements are\n");
for(i=top;i>=0;i--)
{
printf("%d",stack[i]);
}
}
}
