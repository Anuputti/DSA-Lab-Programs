#include<stdio.h>
void towers(int,char,char,char);

int main()
{
int n;
printf("Enter no. of disks:");
scanf("%d",&n);
printf("The sequence of moves performed are:\n");
towers(n,'A','C','B');
return 0;
}

void towers(int num,char frompeg, char topeg, char auxpeg)
{
if(num==1)
{
printf("Move disk 1 from peg %c to peg %c\n",frompeg,topeg);
return;
}
towers(num-1,frompeg,auxpeg,topeg);
printf("Move disk %d from %c to peg %c\n",num,frompeg,topeg);
towers(num-1,auxpeg,topeg,frompeg);
}
