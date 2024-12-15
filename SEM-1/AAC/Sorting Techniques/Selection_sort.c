//Selection Sort

#include<stdio.h>

void selection(int a[],int n)
{
	int i,j;
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		int temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
int main()
{
	int n;
	printf("**Selction Sort**");
	printf("\nEnter the total no of elemenets:");
	scanf("%d",&n);
	
	int a[n];
	printf("\nEnter %d elements in the array:",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection(a,n);
	printf("sorted array using bubble sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
