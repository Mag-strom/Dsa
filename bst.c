#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int num;//declaration of Node
	struct node *left;
	struct node *right;
	struct node *parent;
}Node;
Node* insert( Node *root,int x)
{
	if(root==NULL)
	{
		struct node *new;
		new=(struct node*) malloc(sizeof(struct node));//creating new node using malloc function
		new->num=x;
	        new->left=NULL;
	        new->right=NULL;//if it is the first element
	        new->parent=NULL;
		
		return new;
	}
	else if(x<=root->num)
	{
		Node *temp;//if x is less than root then call insert function again and input root left
		temp=insert(root->left,x);
		temp->parent=root;//link the temp to parent root
		root->left=temp;//link root left to temp
		return root;
	}
	else
	{
		 Node *temp;
		temp=insert(root->right,x);
		temp->parent=root;
		root->right=temp;
		return root;
	}
}
Node* search( Node *root,int x)
{
	if(root==NULL)
	{
		
		return root;//if no elements are present
	}
	else
	{
		if(x==root->num)
		{
			
			return root;//if x = that num then return that num
		}
		else if(x<root->num)
		{
			search(root->left,x);//if x is less than root num then again call search function in left side 
		}
		else
		{
			search(root->right,x);//if x is greater than root num then again call search function in right side 
		}
	}
}
void inorder(Node *root)
{
   Node *ptr;
   ptr=root;
   if(ptr==NULL)
   {
     return ;
   }
   else
   {
      inorder(ptr->left);
      printf("%d\n",ptr->num);
      inorder(ptr->right);
   }
}
void preorder(Node *root)
{
   Node *ptr;
   ptr=root;
   if(ptr==NULL)
   {
     return ;
   }
   else
   {
      printf("%d\n",ptr->num);
      preorder(ptr->left);
      preorder(ptr->right);
   }
}
void postorder(Node *root)
{
   Node *ptr;
   ptr=root;
   if(ptr==NULL)
   {
     return ;
   }
   else
   {
      
      postorder(ptr->left);
      postorder(ptr->right);
      printf("%d\n",ptr->num);
   }
}
void predecessor(Node *p)
{
    Node *current,*pre;
    //if(p==NULL)
    //{
    //  printf("No predecessor\n");
     // return ;
   // }
     if(p->left!=NULL)
    {
       current=p->left;
       while(current->right!=NULL)
       {
          current=current->right;
          
       }
       printf("%d\n",current->num);
       return ;
    }
    else
    {
        current=p;
        pre=current->parent;
      if(pre!=NULL)
      {
        while((pre!=NULL) && (current==pre->left))
        {
           current=pre;
           pre=current->parent;
        }
        if(pre==NULL)
        printf("No predecessor\n");
        else
        printf("%d\n",pre->num);
        return ;
      }
       else
       printf("No predecessor\n");
    }
}
void successor(Node *s)
{
    Node *current,*pre;
   // if(s==NULL)
   // {
    // printf("No successor\n");  
     // return ;
   // }
     if(s->right!=NULL)
    {
       current=s->right;
       while(current->left!=NULL)
       {
          current=current->left;
          
       }
       printf("%d\n",current->num);
       return ;
    }
    else
    {
        current=s;
        pre=current->parent;
      if(pre!=NULL)
      {
        while((pre!=NULL) && (current==pre->right))
        {
           current=pre;
           pre=current->parent;
        }
        if(pre!=NULL)
        printf("%d\n",pre->num);
        else
        printf("No successor\n");
        return ;
      }
       else
       printf("No successor\n");
    }
}
int main()
{
	int a,k;
	Node *root,*new;
	
	root=NULL;
	while(1)
	{
		scanf("%d",&k);
		if(k==1)
		{
		     
			scanf("%d",&a);
			root=insert(root,a);
		}
		if(k==2)
		{
		        
			scanf("%d",&a);
		   new=search(root,a);
			if(new!=NULL)
			{
			    printf("Found\n");
			}
			else
			printf("Not Found\n");
		}
		if(k==3)
		{
                  inorder(root);
                 }
                 if(k==4)
                 {
                   preorder(root);
                 }
                 if(k==5)
                 {
                   postorder(root);
                 }
                 if(k==6)
                 {
                    
                    scanf("%d",&a);
                    new=search(root,a);
                    if(new!=NULL)
                    {
                      predecessor(new);
                     
                    }
                    else
                    printf("Invalid Input\n");
                   
                 }
                 if(k==7)
                 {
                    scanf("%d",&a);
                    new=search(root,a);
                    if(new!=NULL)
                    {
                      successor(new);
                      
                   
                    }
                    else
                    printf("Invalid Input\n");
                 }
                 if(k==8)
                 {
                     break;
                 }
           }
           return 0;
  }