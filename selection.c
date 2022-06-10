#include<stdio.h>
void swap(  long  int *x, long  int *y) //swaping two numbers
{
   long int temp; // in variable temp the value stored in *x is stored
  temp=*x;
  *x=*y; 
  *y=temp;
}
void sort( long int n, long  int arr[])
{
    long int a=0,b=0;
   if(n==1) // basic condition 
   return;
   else
   {
   for(long int i=0;i<n;i++) 
   {
      if(a<arr[i]) // checking the maximum number and storing it in a
      {
         a=arr[i];
         b=i;	// index of that element is stored in b 
      }
   }
   swap(&arr[b],&arr[n-1]); // swaping the positions of maximum element to last position
   sort(n-1,arr); //calling the sort function 
   }
   
}
int main()
{
   long int n;
   scanf("%ld",&n);
   long int arr[n];
   for(long int i=0;i<n;i++)
   {
     scanf("%ld",&arr[i]); // storing the elements in array
     
   }
   
   
   sort(n,arr);
   for(long int i=0;i<n;i++)
   {
      printf("%ld\n",arr[i]); // printing the sorted array
   }
   
   return 0;
}