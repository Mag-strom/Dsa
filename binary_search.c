#include<stdio.h>
int search(int *x, int left, int right, int num, int c)
{
   int middle;
   if(left==right) // it is basic condition 
   {
      if(x[left] == num) // if num is equal to arr[left] then return left 
      {
         printf("%d\n",c); // here c is no. of times the function is called 
         return left;
         
      }
      else
      {
            printf("%d\n",c);
         return -1; // if the nu is not present in the arr then the function will return -1
       }
   }
   else
   {
      middle = (left+right)/2; 
      if( x[middle] == num)  // if the x[middle] is num then the function will return middle 
      {
         printf("%d\n",c);
         return middle;
         
      }
      else if( x[middle]>num && (left<middle))
      {
          c=c+1;
          return (search(x, left, middle-1, num, c)); // calling the search function 
          
      }
      else if( x[middle]<num && (right>middle))
      {
          c=c+1;
          return (search(x, middle+1, right, num, c)); // calling the search function
         
      }
      else 
      {
        printf("%d\n",c);
        return -1;
       }
     
   }

}

int main()
{
    int n,location,c=1; // c=1 because the function is  called atleast once 
    scanf("%d",&n);
    int arr[n],num;
    for(int i=0;i<n;i++)
    {
       scanf("%d",&arr[i]); // storing the elements of arr 
    
    }
    scanf("%d",&num);
    
    
    location = search( arr, 0, n-1, num, c); // calling the function search
    if(location == -1)
    {
       printf("-1");
    }
    else
    {
        printf("%d",location);
    }
    return 0;

}