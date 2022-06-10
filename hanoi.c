#include<stdio.h>
void tower(int n, int t1,int t3,int t2) // t1 is source , t3 is traget , t2 is intermidiate
{
   if(n<1)
   return;
   if(n==1)
   {
      printf("Move Disk %d from Pole %d to Pole %d\n",n,t1,t3);  //n=1 is basic condition 
   }
   else
   {
      tower(n-1,t1,t2,t3);
      printf("Move Disk %d from Pole %d to Pole %d\n",n,t1,t3);
      tower(n-1,t2,t3,t1);
      return;
   
   }
}
int main()
{
   int n;
   //printf("enter the value of n")
   scanf("%d",&n); 
   tower(n,0,2,1); // calling tower function. Here 0 is the source tower, 2 is the target tower, 1 is the intermidiate tower
   return 0;
   
}