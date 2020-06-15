#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[8]={1,2,-5,9,-7,8,100,90};
    int i,evencount=0,oddcount=0,positivecount=0,negativecount=0;
    printf("The given array :");
    for(i=0;i<8;i++)
    {
        printf(" %d\t",a[i]);
         if(a[i]%2==0)
            evencount++;
         if(a[i]%2!=0)
            oddcount++;
         if(a[i]>0)
            positivecount++;
         if(a[i]<0)
            negativecount++;
    }
    printf("\nThe total number of even elements = %d \n",evencount);
     for(i=0;i<8;i++)
    {
         if(a[i]%2==0)
         {
            printf("%d\t",a[i]);
         }
    }
    printf("\nThe total number of odd elements = %d \n",oddcount);
    for(i=0;i<8;i++)
    {
         if(a[i]%2!=0)
         {
            printf("%d\t",a[i]);
         }
    }
    printf("\nThe total number of positive elements = %d \n",positivecount);
    for(i=0;i<8;i++)
    {
         if(a[i]>0)
         {
            printf("%d\t",a[i]);
         }
    }
    printf("\nThe total number of negative elements = %d \n",negativecount);
     for(i=0;i<8;i++)
    {
         if(a[i]<0)
         {
            printf("%d\t",a[i]);
         }
    }

    return 0;
}
