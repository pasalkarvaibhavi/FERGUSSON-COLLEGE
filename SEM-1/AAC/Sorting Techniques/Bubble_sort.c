//Bubble Sort 

#include<stdio.h>

void bubble(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n;
	printf("**Bubble Sort**");
	printf("\nEnter the total no of elemenets:");
	scanf("%d",&n);
	
	int a[n];
	printf("\nEnter %d elements in the array:",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble(a,n);
	printf("sorted array using bubble sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}