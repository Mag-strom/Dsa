#include<stdio.h>
 struct num{ //decalration of num structure
 int number;
 struct num *next;
 };
int main()
{
   struct num num1,num2,num3,num4,num5,num6;//decalration of num1,num2,num3,num4,num5,num6.Here num6 is x
   struct num *first,*current;//declaration of pointers
       scanf("%d",&num1.number);  //storing the num1 number
       scanf("%d",&num2.number);  //storing the num2 number
       scanf("%d",&num3.number);  //storing the num3 number
       scanf("%d",&num4.number);  //storing the num4 number
       scanf("%d",&num5.number);  //storing the num5 number
       scanf("%d",&num6.number);  //storing the num6 number
       num1.next=&num2; //storing the address of num2 in num1.next
       num2.next=&num3; //storing the address of num3 in num2.next
       num3.next=&num4; //storing the address of num4 in num3.next
       num4.next=&num5; //storing the address of num5 in num4.next
       num5.next=&num6; //storing the address of num6 in num5.next
       num6.next=NULL;  //storing the address of null in num6.next
       first=&num1; //pointing first pointer to num1
       current=first; //pointing current pointer to first
       for(int i=0;i<5;i++)
       {
          printf("%d\n",(*current).number); //here the current location changes to next one.so, num1,num2,num3,num4,num5 prints
          current=(*current).next;
       }
       if(num6.number<num1.number)
       {
          first=&num6; //if the num6<num1 then the pointer first points towards num6 and num6.next pointer points towards num1
          num6.next=&num1;
         
       }
       else
       {
         if(num6.number<num2.number)
         {
             num1.next=&num6;//if the num6<num2 then the pointer num1.next points towards num6 and num6.next pointer points towards num2
             num6.next=&num2;
            
         }
         else
         {
             if(num6.number<num3.number)
             {
                 num2.next=&num6; //if the num6<num3 then the pointer num2.next points towards num6 and num6.next pointer points towards num3
                 num6.next=&num3;
                 
             }
             else
             {
                 if(num6.number<num4.number)
                  {
                     num3.next=&num6;  //if the num6<num4 then the pointer num3.next points towards num6 and num6.next pointer points towards num4
                     num6.next=&num4;
                    
                     
                  }  
                  else
                  {
                     if(num6.number<num5.number)
                     {
                        num4.next=&num6; //if the num6<num5 then the pointer num4.next points towards num6 and num6.next pointer points towards num5
                        num6.next=&num5;
                       
                     }
                 
                    
                  }
             }        
         
         }
        }
        current=first;
        for(int j=0;j<6;j++)
        {
          printf("%d\n",(*current).number);
          current=(*current).next;
        } 
   
   return 0;
}
