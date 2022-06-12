#include<stdio.h>
void swap(int *x, int *y)
{
int temp; // variable temp is used for store the number which the x points
temp=*x;
*x=*y; 
*y=temp;
}
int function(int pivot,int arr[],int first, int last)
{
    int r=first;
  for(int i=first;i<=last;i++)
	{
	    if(pivot>arr[i])   

	     {
		   r++;   //r is the rank of arr[k]
	     }
	}
	swap(&arr[first],&arr[r]); 
	int i=first;
	int j=r+1;
  	for(;i<r&&j<=last;)
	{
	    
	     
		if(arr[i]<arr[r]) //if the arr[i] (where i<r) is less than arr[r] then check the next element in array
		{
			i++; // max no. of comparisions is r-1
		}
		else if(arr[j]>=arr[r]) // if the arr[j] (where j=r+1 and j<n) is greater than arr[r] then check the next element
		{
			j++; // max no. of comparisions are n-r+1
		}
		else // if arr[i]>arr[r] and  arr[j]<arr[r] then swap these two numbers
		{
			swap(&arr[i],&arr[j]);
			i++;
			j++;
		}
	    
	}
	return r;
}
void sort(int arr[],int first,int last)
{
  while(first<=last)
   {
   if(first == last)
   return;
   else
   {
      int rank,pivot;
      pivot=arr[first];
       
     rank= function( pivot,arr,first,last);
      if(rank>first)
      sort(arr,first,rank-1);
      if(rank<last)
       first=rank+1;
    }
   
   
   }
   return;

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
  sort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
     printf("%d\n",arr[i]);
  }
  return 0;
}