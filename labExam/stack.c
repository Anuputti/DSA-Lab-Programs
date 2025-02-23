#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int s[SIZE],top=-1;
int rev[SIZE];
int temp,flag=1;
void push(int);
void pop();
void pali();
void display();
void main()
{
int ch,ele,i,item;
int del;
printf("1.push\n2.pop\n3.palindrome\n4.display\n5.exit\n");
while(1)
{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:if(top==(SIZE-1))
{ printf("\nstack overflow");  }
else
{
printf("\nEnter element:");
scanf("%d",&ele);
push(ele);
}
temp=top;
break;

case 2:pop();
if(flag)
{  printf("\nDeleted element is\t");
printf("%d",del);
}
temp=top;
break;

case 3: pali(); 
top=temp; break;

case 4: display();break;
case 5: exit(0);
}
}
}

void push(int ele)
{
top++;
s[top]=ele;
temp=top;
}


void pop()
{
int del;
if(top<=-1)
{
printf("\nSTack underflow");
flag=0;
}
else
{
fflush(stdin);
del = s[top];
top=top-1;
}
}

void pali()
{
int i;
if(top<=-1)
{
printf("\nPush some elements");
return;
}
else
{
while(top!=-1)
{
rev[top]=s[top];
pop();
}
top=temp;
for(i=0;i<=temp;i++)
{
if(s[top--]==rev[i])
{
if(i==temp)
{ printf("\nPAlindrome");
return;
}
}
}
printf("\nNot pali");
}
}

void display()
{
top=temp;
if(top<=-1)
  printf("\nEmpty");
else
{
printf("\nThe elements are:\n");
for(int i=top; i>=0;i--)
{
printf("%d\n",s[i]);
}
}
}
