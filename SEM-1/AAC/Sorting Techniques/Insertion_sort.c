//Insertion Sort.

#include<stdio.h>

void insertion(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int item=a[i];
		int j=i-1;
		while(a[j]>item && (a[j]>0))
		{
			a[j+1]=a[j];
			j=j-1;
			
		}
		a[j+1]=item;
	}
}
int main()
{
	int n;
	printf("**Insertion Sort**");
	printf("\nEnter the total no of elemenets:");
	scanf("%d",&n);
	
	int a[n];
	printf("\nEnter %d elements in the array:",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion(a,n);
	printf("sorted array using insertion sort:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}