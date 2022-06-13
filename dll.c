#include <stdio.h>
#include <stdlib.h> 
typedef struct node // declaration of Node structure
{
	struct node *previous;
	int num;
	struct node *next;
}Node;
int main()
{
	Node *first=NULL,*current,*p,*temp;//declaration of first current p temp pointers
	int n;
	scanf("%d",&n);// enter no of integers
	for(int i=0;i<n;i++)
	{
		 
		current=(Node *) malloc(sizeof(Node));// alloting memory to current using malloc
		
			scanf("%d",&current->num);// storing the value of intger in current->num
			current->next=NULL;//equating current->next to null
			if(first==NULL)
			{//if first == Null then point first to adress stored in current
				first=current;
				current->previous=NULL;//assign current->previous to NULL
				p=current;//ppoint p to adress of current
			}
			else
			{
				current->previous=p;
				p->next=current;
				p=current;
			}
		
		
	}
	current=first;//point the current pointer towards first 
	while(current!=NULL)
	{
		printf("%d\n",current->num);// priting the numbers in given order
		current=current->next;
	}
	current=p;// pointing the current towards the adress stored in p so that now current points towards the last element 
	temp=current;//pointing temp towards adress stored in current

	while(current!=NULL)
	{
		printf("%d\n",current->num);// printing the numbers in reverse order
		current=current->previous;
    }
    current=first;
	first=current->next;
	first->previous=NULL;
	free(current);// deleting first element
	current=temp;
	current=current->previous;
	p=current;
	current->next=NULL;
	free(temp);//deleting last element
	current=first;
	while(current!=NULL)
	{
		printf("%d\n",current->num);
		current=current->next;
	}
	current=p;
	while(current!=NULL)
	{
		printf("%d\n",current->num);
		current=current->previous;
	}
	return 0;
}