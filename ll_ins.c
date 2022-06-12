#include <stdio.h>
struct node
{
   int num;
    struct node  *next;
};


int main()
{
   struct node num1, num2, num3, num4, num5;
   struct node *first, *current,*pre;
   int x = 1;
   scanf("%d", &num1.num);
   scanf("%d", &num2.num);
   scanf("%d", &num3.num);
   scanf("%d", &num4.num);
   scanf("%d", &num5.num);
   first = &num1;
   current = first;
   num1.next=&num2;
   num2.next=&num3;
   num3.next=&num4;
   num4.next=&num5;
   num5.next=NULL;
   for (; x <= 5; x++)
   {
      current=first;
      int p=0;
      if (x == 1)
      {
         printf("%d\n", (*current).num);
         current = (*current).next;
          current = first;
      }
      
      if (x == 2)
      {
         for (int i = 0; i < 2; i++)
         {
            //printf("%d\n",curr->item);
            if ((*current).num > num2.num && p == 0)
            {
               if (i == 0)
               {
                  first = &num2;
                  num2.next = current;
               }
               else
               {
                  (*pre).next = &num2;
                  num2.next = current;
               }
               p++;
            }
            pre = current;
            current = (*current).next;
         }
         current = first;
         for (int i = 0; i < 2; i++)
         {
            printf("%d\n", (*current).num);
            current = (*current).next;
         }
      }
      if(x==3)
      {
          for (int i = 0; i < 3; i++)
         {
            
            //printf("%d\n",curr->item);
            if ((*current).num > num3.num && p == 0)
            {
               if (i == 0)
               {
                  first = &num3;
                  num3.next = current;
               }
               else
               {
                  (*pre).next = &num3;
                  num3.next = current;
               }
               p++;
            }
            pre = current;
            current = current->next;
         }
         current = first;
         for (int i = 0; i < 3; i++)
         {
            printf("%d\n", current->num);
            current = current->next;
         }
         
      }
      if(x==4)
      {
          for (int i = 0; i < 4; i++)
         {
            //printf("%d\n",curr->item);
            if (current->num > num4.num && p == 0)
            {
               if (i == 0)
               {
                  first = &num4;
                  num4.next = current;
               }
               else
               {
                  (*pre).next = &num4;
                  num4.next = current;
               }
               p++;
            }
            pre = current;
            current = current->next;
         }
         current = first;
         for (int i = 0; i < 4; i++)
         {
            printf("%d\n", current->num);
            current = current->next;
         }
      }
      if(x==5)
      {
          for (int i = 0; i < 5; i++)
         {
            //printf("%d\n",curr->item);
            if (current->num > num5.num && p == 0)
            {
               if (i == 0)
               {
                  first = &num5;
                  num5.next = current;
               }
               else
               {
                  (*pre).next = &num5;
                  num5.next = current;
               }
               p++;
            }
            pre = current;
            current = current->next;
         }
         current = first;
         for (int i = 0; i < 5; i++)
         {
            printf("%d\n", current->num);
            current = current->next;
         }
      }
   }
   return 0;
}