#include<stdio.h>
// the function swap will swap two numbers 
void swap(int *x, int *y)
{
int temp; // variable temp is used for store the number which the x points
temp=*x;
*x=*y; 
*y=temp;
}
int main()
{
	int n,k,r=0;
	scanf("%d",&n); // storing the value of n. Here n is no. of elements in arr
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]); // storing the elements in array arr
	}
	scanf("%d",&k); // storing the value of K
   
   
	for(int i=0;i<n;i++)
	{
		if(arr[k]>arr[i])   

		{
		   r++;   //r is the rank of arr[k]
		}
	}
	swap(&arr[k],&arr[r]); // swaping the arr[k] and arr[r]
	for(int i=0;i<r;)
	{
	    for(int j=r+1;j<n;) 
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
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr[i]); // printing the elements of array arr 
	}
   
	return 0;
}