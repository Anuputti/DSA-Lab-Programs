
#include<stdio.h>
#include<stdlib.h>
int key[30],m,n;
int *ht,count=0;
void insert(int);
void display();
int main()
{
printf("Enter number of employee records:\n");
scanf("%d",&n);
printf("Enter 2 digit memory locations for hassh table\n");
scanf("%d",&m);
ht=(int *)malloc(m*sizeof(int));
for(int i=0;i<m;i++)
{
ht[i]=-1;
}

printf("Enter 4 digit key for employee records\n");
for(int i=0;i<n;i++)
{
scanf("%d",&key[i]);
}
for(int i=0;i<n;i++)
{
if(count==m)
{
printf("Hash table is full\n");
return 0;
}
insert(key[i]);
}
display();
return 0;
}

void insert(int k)
{
int index;
index=k%m;
while(ht[index]!=-1)
{
index=(index+1)%m;
}
ht[index]=k;
count++;
}

void display()
{
if(count==0)
{
printf("Hash table is empty\n");
return ;
}
for(int i=0;i<m;i++)
{
printf("T[%d] ---> %d\n",i,ht[i]);
}
}
