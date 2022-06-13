#include <stdio.h>
#include <stdlib.h>
typedef struct node //declaration of Node
{
	int num;
	struct node *left;
	struct node *right;
	struct node *parent;
}Node;
Node* insert( Node *root,int x)
{
	if(root==NULL)
	{
		 Node *new;
		new=( Node*) malloc(sizeof(Node)); //creating new node using malloc function
		new->num=x;
	        new->left=NULL;
	        new->right=NULL;
	        new->parent=NULL; //if it is the first element
		
		return new;
	}
	else if(x<=root->num)
	{
		Node *temp; //if x is less than root then call insert function again and input root left
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
		
		return root; //if no elements are present
	}
	else
	{
		if(x==root->num)
		{
			
			return root; //if x = that num then return that num
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
Node *predecessor(Node *p)
{
    Node *current,*pre;
   // if(p==NULL)
   // {
     // printf("No predecessor\n");
     // return NULL;
   // }
    if(p->left!=NULL)
    {
       current=p->left;
       while(current->right!=NULL)//if the p left not equal to null then go step left and then to right till end 
       {
          current=current->right;
          
       }
       printf("%d\n",current->num);
       return current;
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
        +printf("No predecessor\n");
        else
        printf("%d\n",pre->num);
        return pre;
      }
       else
       printf("No predecessor\n");
       return NULL;
    }
}
Node *successor(Node *s)
{
    Node *current,*pre;
    if(s==NULL)
    {
    // printf("No successor\n");  
      return NULL;
    }
    else if(s->right!=NULL)
    {
       current=s->right;
       while(current->left!=NULL)
       {
          current=current->left;
          
       }
      // printf("%d\n",current->num);
       return current;
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
          return pre;
      }
       else
       return NULL;
    }
}
Node *deletion(Node *p,Node *root)
{
   
   if(p->parent!=NULL)
   {
      if(p->left==NULL && p->right==NULL)
      {
        
       
           if((p->num)>(p->parent->num))
          {
             p->parent->right=NULL;
             free(p);
             return root;
          }
          else
          {
             p->parent->left=NULL;
             free(p);
             return root;
          }
        
      }
      else if(p->left==NULL && p->right!=NULL)
      {
         if((p->num)>(p->parent->num))
         {
             p->parent->right=p->right;
             p->right->parent=p->parent;
             free(p);
             return root;
             
         }  
         else
         {
             p->parent->left=p->right;
             p->right->parent=p->parent;
             free(p);
             return root;
             
         } 
         
      }
       else if(p->right==NULL && p->left!=NULL)
      {
         if((p->num)>(p->parent->num))
         {
             p->parent->right=p->left;
             p->left->parent=p->parent;
             free(p);
             return root;
             
         }  
         else
         {
             p->parent->left=p->left;
             p->left->parent=p->parent;
             free(p);
             return root;
         } 
         
      }
      else
      {
        Node *ptr;
        ptr=successor(p);
        p->num=ptr->num;
        deletion(ptr,root);
        return root;
      }
     }
     else
     {
        if(p->left==NULL && p->right==NULL)
        {
           free(p);
           return NULL;
        }
        else if(p->left==NULL && p->right!=NULL)
        {
          p->right->parent=NULL;
          root=p->right;
          free(p);
          return root;
         
        }
        else if(p->right==NULL && p->left!=NULL)
        {
           p->left->parent=NULL;
           root=p->left;
           free(p);
           return root;
           
        }
        else
      {
        Node *ptr;
        ptr=successor(p);
        p->num=ptr->num;
        deletion(ptr,root);
        return root;
      }
    }   
   
   
}
int main()
{
	int a,k;
	Node *root,*new,*temp;
	
	root=NULL;
	while(1)
	{
		scanf("%d",&k);
		if(k==1)
		{
		     
			scanf("%d",&a);
			root=insert(root,a);//insertion a in bst
		}
		if(k==2)
		{
		        
			scanf("%d",&a);
		   new=search(root,a);
			if(new!=NULL)
			{
			    printf("Found\n"); //searching the given num in bst if it is found then print found else Not found 
			}
			else
			printf("Not Found\n");
		}
		if(k==3)
		{
                  inorder(root); // printing the bst in inorder transversal
                 }
                 if(k==4)
                 {
                   preorder(root); //printing the bst in preorder transversal
                 }
                 if(k==5)
                 {
                   postorder(root);//printing the bst in postorder 
                 }
                 if(k==6)
                 {
                    
                    scanf("%d",&a);
                    new=search(root,a);
                    if(new!=NULL)
                    {
                      predecessor(new); //if the given element is in bst then print the predecessor of that num else print Invalid input
                     
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
                     temp= successor(new);
                      if(temp==NULL)
                      {
                          printf("No successor\n"); //if the given element is in bst then print the successor of that num else print Invalid input
                      }
                      else
                       printf("%d\n",temp->num);
                      
                      
                   
                    }
                    else
                    printf("Invalid Input\n");
                 }
                 if(k==8)
                 {
                    scanf("%d",&a);
                    new=search(root,a);
                    if(new!=NULL)
                   { 
                     root=deletion(new,root);//if the given elecment is in bst then delete the num else print Deletion Fail
                   }
                   else
                   printf("Deletion Fail\n");
                 }
                 if(k==9)
                 {
                     break;
                 }
           }
           return 0;
  }