#include<stdio.h>
#include <conio.h>

int swap(int*xp,int*yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/*low-->Starting index,high--> ending index*/
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i= (low-1);
	int j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}


void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
	  /*pi is partitioning index,arr[pi] is now at right place*/
	  int pi=partition(arr,low,high);
	  quicksort(arr,low,pi-1);//Before pi
	  quicksort(arr,pi+1,high);//After pi
    }
}

void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d  ",arr[i] );
	printf("\n");
}
void main()
{
	int arr[]= {64,34,25,12,22,11,90};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("Given Array:\n");
	printArray(arr,n);
	quicksort(arr,0,n-1);
	printf("\nAfter Sorting: \n");
	printArray(arr,n);
    getch();
}