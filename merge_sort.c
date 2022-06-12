#include <stdio.h>
void merge_sort(int *A, int first, int last) // sending the array A starting location
{
    if(first==last)
    {
        return; //if first is equal to last then stop the function 
    }
    else
    {
        int mid;
        mid = (first + last)/2; 
        merge_sort(A, first, mid); // breaking the array into two array nearly same size
        merge_sort(A, mid + 1, last); // breaking the array into two array nearly same size
        int B[last-first+1];//merging the sorted array A
        int i,j,k=0;
    i = first; // let i be the first element 
    j = mid + 1;
    while (i <= mid&&j <= last) //i should not exceed mid and j should not exceed last element , we taking it as two arrays A
    {
        if (A[i]<=A[j])
        {
            B[k] = A[i]; // storing the small numbers in B array
            k++;
            i++;
        }
        else if(A[j]<A[i])
        {
            B[k] = A[j];// storing the small numbers in B array
            k++;
            j++;
        }
    }
    for (; i <= mid; i++)
    {
        B[k] = A[i]; // storing the remaining elements in B 
        k++;
    }
    for (; j <= last; j++)
    {
        B[k] = A[j]; // storing the remaining elements in B 
        k++;
    }
     for (int k=0;k <last-first+1; k++)
        {
            A[first + k] = B[k]; // storing the sorted array back to A
        }
        
    }
}
int main()
{
    int n;
    scanf("%d", &n); //store the value of n

    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]); //storing the elements in arr A
    }
    merge_sort(A, 0, n-1); //calling the merge_sort function
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }
    return 0;
}