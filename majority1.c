#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int f_max=0,k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    for(int i=0;i<n;i++)
    {
        int f=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                f=f+1;
            }
            

        }

        if(f>f_max)
        {
            f_max=f;
            k=arr[i];

        }
    }
    
    int a=n/2;
    if(f_max>a)
    {
        printf("%d",k);
    }
    else
    {
        printf("No Majority");
    }
    return 0;
}