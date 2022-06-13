#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int num;
   struct node *next;
}Node;
 Node *first=NULL;
void IsEmpty()
{
    if(first==NULL)
    {
        printf("Empty\n");

    }
    else 
    {
        printf("Non Empty\n");
    }
}
void push(int j)
{
    Node *new = NULL;
    new = (struct node*)malloc(sizeof(Node));
    (*new).num=j;
    new->next=first;
    first=new;
    if(first->num!=j)
    {
        printf("Push Failure\n");
    }
}
void pop()
{
    if(first==NULL)
    {
      
       printf("Pop Failure\n");
       
    }
    else
    {
          Node *temp=NULL;
        temp=first;
        first=first->next;
        printf("%d\n",(*temp).num);
        free(temp);
    }
}
void top()
{
    if(first==NULL)
    {
        printf("Top Failure\n");
        
    }
    else
    {
         printf("%d\n",(*first).num);
    }

}
void Display()
{
    if(first==NULL)
    {
         printf("Empty List\n");
     
    }
    else
    {
         Node *temp1;
      temp1=first;
      while(temp1!=NULL)
      {
          printf("%d\n",temp1->num);
          temp1=temp1->next;
      }
    }
}

int main()
{
    int i;
    while(2)
    {
        
        scanf("%d",&i);
        if(i==0)
        {
            IsEmpty();
        }
        else if(i==1)
        {
            int j;
            scanf("%d",&j);
            push(j);
        }
        else if(i==2)
        {
            pop();
        }
        else if(i==3)
        {
            top();
        }
        else if(i==4)
        {
            Display();
        }
        else if(i==5)
        {
            break;
        }
    } 
    return 0;
}