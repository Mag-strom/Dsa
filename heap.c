#include <stdio.h>
void swap(int *x, int *y)
{
   int temp;
   temp = *y;
   *y = *x;
   *x = temp;
   return;
}
void siftup(int arr[], int i)
{
   while ((i > 0) && arr[i] <= arr[(i - 1) / 2])
   {
      swap(&arr[i], &arr[(i - 1) / 2]);
      i = (i - 1) / 2;
   }
   return;
}
void minheapify(int arr[], int n, int i)
{
   int small;
   if (i >= n / 2)
   {
      return;
   }
   if (arr[2 * i + 1] < arr[i])
   {
      small = 2 * i + 1;
   }
   else
   {
      small = i;
   }
   if (((2 * i + 2) <= n - 1) && (arr[2 * i + 2] < arr[small]))
   {
      small = 2 * i + 2;
   }
   if (small == i)
   {
      return;
   }
   else
   {
      swap(&arr[i], &arr[small]);
      minheapify(arr, n, small);
   }
}
void build(int arr[], int n)
{
   int index;
   index = (n - 1) / 2;
   while (index >= 0)
   {
      minheapify(arr, n, index);
      index = index - 1;
   }
}
void extractmin(int arr[], int n)
{
   printf("%d\n",arr[0]);
   arr[0] = arr[n - 1];
   //n = n - 1;
   minheapify(arr, n-1, 0);
}
void decreasekey(int arr[], int a, int i)
{
   if (arr[i] <= a)
   {
      printf("Operation Fail\n");
   }
   else
   {
      arr[i] = a;
      siftup(arr, i);
   }
}
void findmin(int arr[])
{
   printf("%d\n", arr[0]);
}
int delete (int arr[], int n)
{
   int x;
   scanf("%d", &x);
   if (x > n-1)
   {
      printf("Operation Fail\n");
      return n;
   }
   else
   {
      arr[x] = arr[n-1];
      //n = n-1;
      minheapify(arr,n-1,x);
      return n-1;
   }
}
void insert(int arr[], int n, int a)
{
   arr[n - 1] = a;
   siftup(arr, n - 1);
   return;
}
int main()
{
   int k, n = 0, a, i;
   scanf("%d", &n);
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }
   build(arr, n);
   while (1)
   {
      scanf("%d", &k);
      if (k == 1)
      {
         scanf("%d", &a);
         n = n + 1;
         insert(arr, n, a);
      }

      else if (k == 2)
      {
         n=delete (arr, n);
         
      }
      else if (k == 3)
      {
         extractmin(arr, n);
         n=n-1;
        
      }
      else if (k == 4)
      {
         for (int j = 0; j < n; j++)
         {
            printf("%d\n", arr[j]);
         }
      }
      else if (k == 5)
      {
         scanf("%d", &i);
         scanf("%d", &a);
         if (i > n)
         {
            printf("Operation Fail\n");
         }
         else
         {
            decreasekey(arr, a, i);
         }
      }
      else if (k == 6)
      {
         findmin(arr);
      }
      else if (k == 7)
      {
         break;
      }
   }

   return 0;
}