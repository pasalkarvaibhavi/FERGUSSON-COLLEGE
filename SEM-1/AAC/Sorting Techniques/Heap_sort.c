//Heap Sort

#include<stdio.h>

void heapify(int a[],int n,int i)
{
	int max=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]>a[max])
	{
		max=l;
	}
	
		
	if(r<n && a[r]>a[max])
	{
		max=r;
	}
	
	if(max!=i)
	{
		int temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		heapify(a,n,max);
	}
	
}



void buildHeap(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
}

void sortHeap(int a[],int n)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
	int temp=a[0];
	a[0]=a[i];
	a[i]=temp;
	heapify(a,i,0);
	}
}

void heapsort(int a[],int n)
{
	buildHeap(a,n);
	sortHeap(a,n);
}
int main()
{
	int n,i;
	printf("**Heap Sort**")
	printf("Enter total number of elements in heap sort:\n");
	scanf("%d",&n);
	
	int a[n];
	
	printf("\nenter Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	heapsort(a,n);
	
	printf("\nSorted elements using heap sort:\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}	
	
}