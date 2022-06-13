#include <stdio.h>
#include <stdlib.h>
int clock;

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
    Node *new;
        new = (Node*)malloc(sizeof(Node));//create new node and allocate memory to it
        new->num=j;//make new num equal to j
        new->next=NULL;//make new next to NULL
        pre->next=new;//link previous node pre to new node
        
    
}
void dfs_explroler(int v,Node current[],int visit[],int entry[],int ext[],int pred[])
{
    int u;
    Node *temp;
    visit[v]=1; //when we visit the vth vertex then mark the v index of visit array to 1
    entry[v]=clock; //store the clock value in the vth index of entry array
    clock=clock+1;//increment the clock
    head=&current[v];
    temp=head->next;//point the head to current[v]
    while(temp!=NULL)
    {
        //head=head->next;
        u=temp->num;//store the head num in u
        if(visit[u]==0)
        {
            pred[u]=v; //if visit[u] is 0 then call the dfs_explrolr
            dfs_explroler(u,current,visit,entry,ext,pred);
        }
        temp=temp->next;
        
    }
    ext[v]=clock;//store the clock value when it exits the vertex
    clock=clock+1;//increment the clock

}
int main()
{
    int  a, b, m,v,n;
    clock=0;
    scanf("%d", &n);
    int visit[n],ext[n],pred[n],entry[n];
    
    Node current[n];//declaration a cuurent array 
    
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        current[i].next = NULL;
        current[i].num = i;//storing the i values in current array and making current next to NULL
    }
    
    for (int j = 0; j < m; j++)
    {
        scanf("%d %d", &a, &b);
        head = &current[a];//point the head to current[a] of the array
        push(b);//calling the push function to insert and link the vertices a and b
        head = &current[b];//point the head to current[a] of the array
        push(a);//calling the push function to insert and link the vertices a and b
    }
    for(int i=0;i<n;i++)
    {
        visit[i]=0;//Initializing the all the elements in visit array to 0
        //ext[i]=-1;
        //entry[i]=-1;
    }
    scanf("%d",&v);// input the given start vertex
    dfs_explroler(v,current,visit,entry,ext,pred);//calling dfs_explorer
    for(int k=0;k<n;k++)
    {
        if(visit[k]==0)
        {
            dfs_explroler(k,current,visit,entry,ext,pred);// check any visit is 0 then all dfs explorer again
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",entry[i],ext[i]);
    }
    
        return 0;
}