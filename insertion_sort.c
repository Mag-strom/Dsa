#include<stdio.h>
void insertion(int n,int arr[] )
{
   
    int i=n-2;
    int temp =arr[n-1];
    while(i>=0&&arr[i]>temp)
    {
       arr[i+1] = arr[i];
       i=i-1;
    }
    arr[i+1]=temp;

}
void sort(int n,int arr[])
{
  
  if(n==1)
  return;
  else
  {
    sort(n-1,arr);
    insertion(n,arr);
  
  }
  
}
int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  sort(n,arr);
  for(int i=0;i<n;i++)
  {
  printf("%d\n",arr[i]);
  }
  return 0;
}