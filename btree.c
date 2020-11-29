
#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
     struct tree *left;
     struct tree *right;
};

struct tree *root=NULL;

struct tree* createnode()
{
    struct tree *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(struct tree*)malloc(sizeof(struct tree));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=createnode();
 
	printf("Enter right child of %d:\n",x);
	p->right=createnode();
	
	return p;
}
struct tree* firstnode()
{
    struct tree *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(struct tree*)malloc(sizeof(struct tree));
	p->data=x;
	printf("Enter left child of %d:\n",x);
	p->left=createnode();
 
	printf("Enter right child of %d:\n",x);
	p->right=createnode();
	root=p;
	return p;
}
void inordertraversal(struct tree *tem)
{
    if(tem==NULL)
    {
        return;
    }
    inordertraversal(tem->left);
    printf("%d -> ",tem->data);
    inordertraversal(tem->right);
}

void preordertraversal(struct tree *tem)
{
   if(tem==NULL)
    {
        return;
    }
    printf("%d -> ",tem->data);
    preordertraversal(tem->left);
    preordertraversal(tem->right); 
}

void postordertraversal(struct tree *tem)
{
    if(tem==NULL)
    {
        return;
    }
    postordertraversal(tem->left);
    postordertraversal(tem->right);
    printf("%d -> ",tem->data);
}



struct tree* search(struct tree *temp,int x)
{
    struct tree* p;
if(temp==NULL)
    {
        return NULL;
    }
    if(temp->left!=NULL)
    if(temp->left->data==x)
      return temp;
    if(temp->right!=NULL)
    if(temp->right->data==x)
      return temp;  
    if(temp->data==x)
    return temp;  
    p =search(temp->left,x);
    if(p!=NULL)
    return p;
    p=search(temp->right,x);
    if(p!=NULL)
    return p;
 return NULL;   
} 

void delete_tree(struct tree *temp,int x)
{
    printf("Deleted %d from the tree...",temp->data);
    if(temp==NULL)
    return;
    if(root->data==x)
 {   root=NULL;
    return;
}
    else if(temp->left->data==x)
    {temp->left=NULL;}
    else if(temp->right->data==x)
    temp->right=NULL;
   
}

int delete()
{
    int d,depth;
    struct tree *temp;
    printf("Enter the node to delete: \n");
    scanf("%d",&d);
    temp=search(root,d);
    if(temp==NULL)
 {   printf("No Element found to delete!");
    return;
}
    delete_tree(temp,d);
}
void main()
{
 int n;
 while(1)
 {
     printf("\nBINARY TREE \n");
     printf("\n");
     printf("1. Create Tree \n");
     printf("2. Inorder Traversal \n");
     printf("3. Postorder Traversal \n");
     printf("4. Preorder Traversal \n");
     printf("5. Delete a node \n");
     printf("6. Exit \n");
     printf("Enter the option...\n");
     scanf("%d",&n);
     switch (n)
     {
     case 1:
         firstnode();
         break;
     case 2:
         printf("Inorder traversal \n");
         inordertraversal(root);
         break;
     case 3:
         printf("\nPostorder traversal \n");
         postordertraversal(root);
         break;
     case 4:
         printf("\nPreorder traversal \n");
         preordertraversal(root);
         break;
     case 5:
        printf("\nDelete a Node \n");
        delete();
         break;
     case 6:
         exit(0);
         break;                
     default:
        printf("Invalid option \n");
         break;
     }
 }
}