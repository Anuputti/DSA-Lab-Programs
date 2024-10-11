#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[40],name[40],branch[50];
int sem;
long int phone;
struct node *link;
};
typedef struct node *NODE;

NODE start=NULL;
int count=0;

NODE create();
NODE insertfront();
NODE deletefront();
NODE insertend();
NODE deletend();
void display();
void stackdemo();

int main()
{
int ch,i;
int n;
printf("1.create SLL\n2.Display and count\n3.insertend\n4.deleteend\n5.STackdemo\n6.EXIT\n");
while(1)
{
printf("\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nEnter no. of students: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
start=insertfront();
}
break;

case 2: display();break;
case 3:start=insertend();break;
case 4:start=deletend(); break;
case 5:stackdemo(); break;
case 6:exit(0);
}
}
return 0;
}

NODE create()
{
NODE snode;
snode=(NODE)malloc(sizeof(struct node));
if(snode==NULL)
{
printf("No memory\n");
exit(1);
}
printf("\nEnter student usn,name,branch,sem,phone number\n");
scanf("%s %s %s %d %ld",snode->usn,snode->name,snode->branch,&snode->sem,&snode->phone);
snode->link=NULL;
count++;
return snode;
}

NODE insertfront()
{
NODE temp;
temp=create();
if(start==NULL)
{
return temp;
}
temp->link=start;
return temp;
}

NODE deletefront()
{
NODE temp;
if(start==NULL)
{
printf("SLL is empty\n");
return NULL;
}
if(start->link==NULL)
{
printf("node delted with usn %s\n",start->usn);
free(start);
count--;
return NULL;
}
temp=start;
start=start->link;
printf("Node deleted with usn %s\n",temp->usn);
free(temp);
count--;
return start;
}

NODE insertend()
{
NODE cur,temp;
temp=create();
if(start==NULL)
{
return temp;
}
cur=start;
while(cur->link!=NULL)
{
cur=cur->link;
}
cur->link=temp;
return start;
}

NODE deletend()
{
NODE cur,prev;
if(start==NULL)
{
printf("SLL is empty\n");
return NULL;
}
if(start->link==NULL)
{
printf("Node deleted with usn %s \n",start->usn);
free(start);
count--;
return NULL;
}
prev=NULL;
cur=start;
while(cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
prev->link=NULL;
printf("Node delted with usn %s\n",cur->usn);
free(cur);
count--;
return start;
}

void display()
{
int num=1;
NODE cur;
if(start==NULL)
{
printf("SLL is empty\n");
return;
}
cur=start;
while(cur!=NULL)
{
printf("\n%d || %s|%s|%s|%d|%ld ||",num,cur->usn,cur->name,cur->branch,cur->sem,cur->phone);
cur=cur->link;
num++;
}
printf("\nNo. of nodes :%d",count);
}

void stackdemo()
{
int ch,i;
printf("1.Push\n2.pop\n");
while(1)
{
printf("\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: start=insertfront(); break;
case 2:start=deletefront(); break;
case 3:return;
}
}
}
