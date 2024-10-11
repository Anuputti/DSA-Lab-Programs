#include<stdio.h>
#include<string.h>
char STR[50], PAT[50],REP[50],ans[50];
int i,j,c,m,k;

void main()
{
int flag=0;
printf("Enter a string :");
fgets(STR,50,stdin);
printf("\nEnter a patern :");
fgets(PAT,50,stdin);
printf("\nEnter replace string:");
fgets(REP,50,stdin);
i=j=c=m=0;

while(STR[c]!='\n')
{
if(STR[m]==PAT[i])
{
i++; m++;
if(PAT[i]=='\n')
{
for(k=0;REP[k]!='\n';k++,j++)
{
ans[j]=REP[k];
flag=1;
}
c=m;
i=0;
}
}
else
{
ans[j]=STR[c];
j++;
c++;
m=c;
i=0;
}
}

if(flag)
{
ans[j]='\n';
printf("\nThe resultant string: %s\n",ans);
}
else
{
printf("\nPatern not found");
}
}
