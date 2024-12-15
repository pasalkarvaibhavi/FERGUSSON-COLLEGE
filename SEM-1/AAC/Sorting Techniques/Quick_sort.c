//Quick Sort

#include<stdio.h>

void quicksort(int a[],int low,int high)
{
	int v;
	int i,j,temp;
	if(low<high)
	{
		v=a[low];
		i=low+1;
		j=high;
		while(1)
		{
			while(a[i]<v && i<=high)
			{
				i++;
			}
			while(a[j]>v && j>=low)
			{
				j--;
			}
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else{
				break;
			}
			
		}
		a[low]=a[j];
		a[j]=v;
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
	}
}
int main()
{
	printf("**Quick Sort**");
	int i,j,n,low,high;
	printf("\nEnter total number of elements:");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter Elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	low=0;
	high=n-1;
	quicksort(a,low,high);
	
	printf("Sorted Array using Quick Sort:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	
}