#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int f=1;
  int a=arr[0];
  for(int i=0;i<n;i++)
  {
     if(a==arr[i+1])
     {
        f=f+1;
        
     }
     else
     {
       f=f-1;
       if(f==0)
       {
         a=arr[i+2];
         f=1;
       }
     }   
     
  }
  int k=0;
  for(int i=0;i<n;i++)
  {
     if(a==arr[i])
     {
        k=k+1;
     }
  }
  
  if(k>(n/2))
  {
     printf("%d",a);
  }
  else
  {
     printf("No Majority");
  }
  return 0;
}