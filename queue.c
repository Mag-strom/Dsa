#include<stdio.h>
#include<stdlib.h>
typedef struct node // declaration of structure 
{
   int num;
   struct node *next;
}Node;
 Node *first=NULL;
 Node *end,*pre;
void IsEmpty()
{
    if(first==NULL) // if their is no first element prints empty
    {
        printf("Empty\n");

    }
    else // else prints non empty
    {
        printf("Non Empty\n");
    }
}
void Enqueue(int j)//sending a value of j into enqueue function
{
    end=(Node *) malloc(sizeof(Node)); //assignng a memory to end using malloc function
	end->num=j;//storing the value of j in end num
	end->next=NULL;//assigning the end next to null
	if(first==NULL)//if first is null then assign end to first and first to pre 
	{
		first=end; 
		pre=first;
    }
	else if(first!=NULL)
	{
		pre->next=end; 
		pre=end;		
	}
  
}
void Dequeue()
{
    if(first==NULL) //if no elements are present then print Deqeue failure
    {
      
       printf("Dequeue Failure\n");
       
    }
    else
    {
        Node *temp=NULL; // delcare temp pointer
        temp=first;
        first=first->next;
        printf("%d\n",temp->num);//print the value stored in tempnum 
        free(temp);//delete the temp
    }
}
void Peek()
{
    if(first==NULL)//
    {
        printf("Peek Failure\n");
        
    }
    else
    {
         printf("%d\n",first->num);// print the first element 
    }

}
void Display()
{
    if(first==NULL)
    {
         printf("Empty List\n");// if no elements are present then print empty list
     
    }
    else
    {
         Node *temp1;
      temp1=first;
      while(temp1!=NULL)
      {
          printf("%d\n",temp1->num); //else print all the numbers 
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
            IsEmpty();//if i==0 then call Isempty
        }
        else if(i==1)
        {
            int j;
            scanf("%d",&j);
            Enqueue(j);//if i==1 then call  Enqueue
        }
        else if(i==2)
        {
            Dequeue();//if i==2 call Dequeue 
        }
        else if(i==3)
        {
            Peek();
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