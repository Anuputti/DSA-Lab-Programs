#include<stdio.h>
#include<stdlib.h>
#define DAYS 7
struct day
{
char *name;
int date;
char *activity;
};
void create(struct day cal[DAYS])
{
for(int i=0; i<DAYS; i++)
{
cal[i].name=(char *)malloc(20*sizeof(char));
cal[i].activity=(char *)malloc(20*sizeof(char));
}
}

void read(struct day cal[DAYS])
{
int i;
for(i=0;i<DAYS;i++)
{
printf("Enter name of day %d : ",i+1);
scanf("%s",cal[i].name);
printf("Enter date of day %d :",i+1);
scanf("%d",&cal[i].date);
printf("Enter activity of day %d :",i+1);
scanf("%s",cal[i].activity);
}
}

void display(struct day cal[DAYS])
{
int i;
printf("\nDay\t\t\tDate\tActivity\n");
for(i=0;i<DAYS;i++)
{
printf("%s\t\t\t%d\t%s\n",cal[i].name,cal[i].date,cal[i].activity);
}
}

int main()
{
struct day cal[DAYS];
create(cal);
read(cal);
display(cal);
for(int i=0;i<DAYS;i++)
{
free(cal[i].name);
free(cal[i].activity);
}
return 0;
}
