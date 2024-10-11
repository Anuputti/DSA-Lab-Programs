#include<stdio.h>
#include<stdlib.h>
struct node
{
char ssn[30],name[30],dept[30],desig[30];
int sal;
long int phone;
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;
int count=0;
NODE create();
NODE insertfront();
NODE deletefront();
NODE insertend();
NODE deletend();
void display();
void deque();

void main()
{
int ch,i,n;
printf("1.Create a DLL\n2.Display and count\n3.Insertend\n4.Deletend\n5.Insertfront\n6.Deletefront\n7.Deque demonstartion\n8.exit\n");
while(1)
{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\nEnter no. of employees");
scanf("%d",&n);
for(i=0;i<n;i++)
{
first=insertend();
}
break;
case 2:display(); break;
case 3:first=insertend(); break;
case 4:first=deletend();break;
case 5:first=insertfront(); break;
case 6:first=deletefront();break;
case 7:deque();break;
case 8:exit(0);
}
}
}

NODE create()
{
NODE enode;
enode=(NODE)malloc(sizeof(struct node));
if(enode==NULL)
{
printf("No memory");
exit(1);
}
printf("\nEnter employee SSN,Name,Dept,Desig,sal,phone\n");
scanf("%s %s %s %s %d %ld",enode->ssn,enode->name,enode->dept,enode->desig,&enode->sal,&enode->phone);
enode->rlink=NULL;
enode->llink=NULL;
count++;
return enode;
}

NODE insertfront()
{
NODE temp;
temp=create();
if(first==NULL)
{
return temp;
}
temp->rlink=first;
first->llink=temp;
return temp;
}

NODE deletefront()
{
NODE temp;
if(first==NULL)
{
printf("\nDLL is empty");
return NULL;
}
if(first->rlink==NULL)
{
printf("\nDeleted node with ssn %s",first->ssn);
free(first);
count--;
return NULL;
}
temp=first;
first=first->rlink;
printf("\nnode deleted with sssn %s",temp->ssn);
temp->rlink=NULL;
first->llink=NULL;
free(temp);
count--;
return first;
}

NODE insertend()
{
NODE cur,temp;
temp=create();
if(first==NULL)
{
return temp;
}
cur=first;
while(cur->rlink!=NULL)
{
cur=cur->rlink;
}
cur->rlink=temp;
temp->llink=cur;
return first;
}

NODE deletend()
{
NODE prev,cur;
if(first==NULL)
{
printf("\nDLL is empty\n");
return NULL;
}
if(first->rlink==NULL)
{
printf("\nNode deleted with ssn %s",first->ssn);
free(first);
count--;
return NULL;
}
prev=NULL;
cur=first;
while(cur->rlink!=NULL)
{
prev=cur;
cur=cur->rlink;
}
cur->llink=NULL;
prev->rlink=NULL;
printf("\nNode deleted with ssn %s",cur->ssn);
free(cur);
count--;
return first;
}

void display()
{
int n=1;
NODE cur;
if(first==NULL)
{
printf("\nDLL is empty");
return;
}
cur=first;
while(cur!=NULL)
{
printf("\n%d || %s|%s|%s|%s|%d|%ld ||",n,cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->phone);
cur=cur->rlink;
n++;
}
printf("\nNo. of nodes in DLL are %d\n",count);
}

void deque()
{
int ch;
printf("\n1.EnqueEnd\n2.DequeRear\n3.Enquefront\n4.DequeFront\n5.Display\n6Exit\n");
while(1)
{
printf("\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:first=insertend();break;
case 2:first=deletend();break;
case 3:first=insertfront();break;
case 4:first=deletefront();break;
case 5:display();break;
case 6:exit(0);
}
}
}


