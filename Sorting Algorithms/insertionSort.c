#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void insertionSort(int arr[],int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key = arr[i];
		j=i-1;
		/*Move elements of arr[0..i-1], that are greater than key,to one position ahead of their current position*/
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}
void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",arr[i] );
	printf("\n");
}
int main()
{
	int arr[]={44,90,7,56,73,80};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Before Sorting : \n");
	printArray(arr,n);
	insertionSort(arr,n);
    printf("After Sorting\n");
    printArray(arr,n);
	return 0;
}