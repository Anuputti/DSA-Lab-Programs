#include<stdio.h>
#include<stdlib.h>
struct BST
{
int data;
struct BST *lchild;
struct BST *rchild;
};
typedef struct BST *NODE;

NODE create();
void insert(NODE,NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
void search(NODE);

void main()
{
NODE root=NULL,newnode;
int i,ch,n;
printf("1.Create BST\n2.Traversel\n3.search\n4.exit\n");
while(1)
{
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nEnter no. of elements:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
newnode=create();
if(root==NULL)
   root=newnode;
else
   insert(root,newnode);
}
break;

case 2: if(root==NULL)
 {
printf("\nTree is empty");
return;
}
else
{
printf("\nthe preorder:\t");
preorder(root);
printf("\nInorder:\t");
inorder(root);
printf("\npostorder:\t");
postorder(root);
}
break;

case 3: search(root); break;
case 4:exit(0);
}
}
}

NODE create()
{
NODE temp;
temp=(NODE)malloc(sizeof(struct BST));
if(temp==NULL)
{
printf("Memory not available\n");
return NULL;
}
printf("\nEnter data:");
scanf("%d",&temp->data);
temp->lchild=NULL;
temp->rchild=NULL;
return temp;
}

void insert(NODE root, NODE newnode)
{
if(newnode->data < root->data)
{
if(root->lchild==NULL){
  root->lchild=newnode;}
else
{
insert(root->lchild,newnode);
}
}
if(newnode->data > root->data)
{
if(root->rchild==NULL){
root->rchild=newnode;}
else{ insert(root->rchild,newnode);}
}
}

void search(NODE root)
{
if(root==NULL)
{printf("Tree is empty"); return;}
NODE cur; int key;
printf("\nEnter key to search:");
scanf("%d",&key);
cur=root;
while(cur!=NULL)
{
if(cur->data==key)
{
printf("\nElement founf in bst");
return;
}
if(key<cur->data)
{  cur=cur->lchild;}
else
{  cur=cur->rchild;}
}
printf("key nit found");
}

void inorder(NODE root)
{
if(root!=NULL)
{
inorder(root->lchild);
printf("%d",root->data);
inorder(root->rchild);
}
}

void preorder(NODE root)
{
if(root!=NULL)
{
printf("%d",root->data);
preorder(root->lchild);
preorder(root->rchild);
}
}
void postorder(NODE root)
{
if(root!=NULL)
{
postorder(root->lchild);
postorder(root->rchild);
printf("%d",root->data);
}
}
