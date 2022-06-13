#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *next;
} Node;
Node *head;
void push(int j)
{
    Node *pre;
    pre=head;//make pre equal to head
    while(pre->next!=NULL)
    {
        pre=pre->next;//to go the last node 
    }
    Node *new;//create new node and allocate memory to it
        new = (Node*)malloc(sizeof(Node));
        new->num=j; //make new num equal to j
        new->next=NULL;//make new next to NULL
        pre->next=new;//link previous node pre to new node
    
}

int main()
{
    int n, a, b, m;
    Node current[n];//declaration a cuurent array 
    scanf("%d", &n);//no. of vertices
    scanf("%d", &m);//input the no. of edges
    for (int i = 0; i < n; i++)
    {
        current[i].next = NULL;
        current[i].num = i;//storing the i values in current array and making current next to NULL
    }
    for (int j = 0; j < m; j++)
    {
        scanf("%d %d", &a, &b);
        head = &current[a];//point the head to current[a] of the array
        push(b); //calling the push function to insert and link the vertices a and b
        head = &current[b];//point the head to current[a] of the array
        push(a);//calling the push function to insert and link the vertices a and b
    }
    for (int k = 0; k < n; k++)
    {
        head = &current[k];
        if (head->next == NULL)
        {
            printf("Nil\n"); //if degree of the current[a] is 0 then print nil
        }
        else
        {
            while (head->next != NULL)
            {
                head= head->next;
                printf("%d", head->num); // else print the neighbour vertices of current[a]
                if (head->next != NULL)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
        return 0;
}