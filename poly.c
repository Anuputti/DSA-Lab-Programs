#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(x,y) ((x==y)?0:(x>y)?1:-1)
struct node
{
int coef;
int xexp,yexp,zexp;
struct node *link;
};
typedef struct node *NODE;

NODE getnode();
NODE read_poly(NODE);
NODE attach(int,int,int,int,NODE);
int poly_evaluate(NODE);
NODE poly_sum(NODE,NODE,NODE);
void display(NODE);

int main()
{
int ch,res;
NODE head,head1,head2,head3;
head=getnode();
head1=getnode();
head2=getnode();
head3=getnode();
head->link=head;
head1->link=head1;
head2->link=head2;
head3->link=head3;
printf("1.Represent and evaluate poly\n2.Find sum of two poly\n3.exit\n");
while(1)
{
printf("\nEnter ur choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
head=read_poly(head);
printf("\nRepresentation of poly\n");
display(head);
res=poly_evaluate(head);
printf("\nThe result is: %d\n",res);

break;

case 2:
printf("\nRead POLY1\n");
head1=read_poly(head1);
display(head1);
printf("\nRead POLY2\n");
head2=read_poly(head2);
display(head2);
printf("\nSum of two poly\n");
head3=poly_sum(head1,head2,head3);
display(head3);
break;

case 3:exit(0);
}
}
return 0;
}

NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("No memory\n");
exit(1);
}
return x;
}

NODE read_poly(NODE head)
{
int i,n,coef,xexp,yexp,zexp;
printf("Enter no. of terms:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter %d term:",i+1);
printf("\n\tCoef:");
scanf("%d",&coef);
printf("\nEnter pow(x), pow(y), pow(z):");
scanf("%d %d %d",&xexp,&yexp,&zexp);
head=attach(coef,xexp,yexp,zexp,head);
}
return head;
}

NODE attach(int coef,int xexp,int yexp,int zexp,NODE head)
{
NODE cur,temp;
temp=getnode();
temp->coef=coef;
temp->xexp=xexp;
temp->yexp=yexp;
temp->zexp=zexp;
cur=head->link;
while(cur->link!=head)
{
cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}

void display(NODE head)
{
if(head->link==NULL)
{
printf("SCLL is empty\n");
return;
}
NODE cur;
cur=head->link;
while(cur!=head)
{
printf("%dx^%dy^%dz^%d",cur->coef,cur->xexp,cur->yexp,cur->zexp);
cur=cur->link;
if(cur!=head)
{
printf(" + ");
}
}
}

int poly_evaluate(NODE head)
{
int x,y,z,sum=0;
NODE poly;
printf("\nEnter values of x,y,z\n");
scanf("%d %d %d",&x,&y,&z);
poly=head->link;
while(poly!=head)
{
sum+=poly->coef*pow(x,poly->xexp)*pow(y,poly->yexp)*pow(z,poly->zexp);
poly=poly->link;
}
return sum;
}


NODE poly_sum(NODE head1, NODE head2, NODE head3)
{
    NODE a, b;
    int coef;
    a = head1->link;
    b = head2->link;

    while(a!=head1 && b!=head2)
    {
            while(1)
            {
                        if(a->xexp == b->xexp && a->yexp == b->yexp && a->zexp == b->zexp)
                        {
                                    coef = a->coef + b->coef;
                                    head3 = attach(coef, a->xexp, a->yexp, a->zexp, head3);
                                    a = a->link;
                                    b = b->link;
                                    break;
                        } //if ends here
                        if(a->xexp!=0 || b->xexp!=0)
                        {
                                    switch(COMPARE(a->xexp, b->xexp))
                                    {
                                     case -1 :  head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                                                    b = b->link;
                                                    break;

                                    case 0 :    if(a->yexp > b->yexp)
                                                    {
                                                            head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                                                            a = a->link;
                                                            break;
                                                     }
                                                     else if(a->yexp < b->yexp)
                                                     {
                                                             head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                                                             b = b->link;
                                                             break;
                                                     }
                                                    else if(a->zexp > b->zexp)
                                                    {
                                                            head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                                                            a = a->link;
                                                            break;
                                                    }
                                                    else if(a->zexp < b->zexp)
                                                   {
                                                            head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                                                            b = b->link;
                                                            break;
                                                   }
                                    case 1 :    head3 = attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
                                                    a = a->link;
                                                    break;
                                    }  //switch ends here
                                    break;
                        } //if ends here
                        if(a->yexp!=0 || b->yexp!=0)
                        {
                                    switch(COMPARE(a->yexp, b->yexp))
                                    {
                                          case -1 :   head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                                                          b = b->link;
                                                          break;
                                           case 0 :   if(a->zexp > b->zexp)
                                                          {
                                                                 head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                                                                 a = a->link;
                                                                 break;
                                                            }
                                                            else if(a->zexp < b->zexp)
                                                            {
                                                                 head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                                                                 b = b->link;
                                                                 break;
                                                            }
                                            case 1 :    head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                                                            a = a->link;
                                                            break;
                                    }
                                    break;
                        }
                        if(a->zexp!=0 || b->zexp!=0)
                        {
                                    switch(COMPARE(a->zexp,b->zexp))
                                    {
                                                case -1 :   head3 = attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
                                                                b = b->link;
                                                                break;
                                                case 1 :    head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                                                                a = a->link;
                                                                break;
                                    }
                                    break;
                        }
            }
    }


while(a!=head1)
{
head3= attach(a->coef,a->xexp,a->yexp,a->zexp,head3);
a=a->link;
}
while(b!=head2)
{
head3=attach(b->coef,b->xexp,b->yexp,b->zexp,head3);
b=b->link;
}
return head3;
}

