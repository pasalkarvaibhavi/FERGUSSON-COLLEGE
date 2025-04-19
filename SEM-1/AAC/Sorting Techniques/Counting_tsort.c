//Counting Sort

#include<stdio.h>

void countingsort(int input_array[],int n,int range)
{
	
	int i;
	int output_array[n];
	int c[range];
	
	for(i=0;i<range;i++)
	{
		c[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		++c[input_array[i]];
		//c[a[i]]=c[a[i]]+1;
	}
	
	for(i=1;i<range;i++)
	{
			c[i]=c[i]+c[i-1];
			//c[i]=c[i]+c[i-1];
	}
	
	

	for(i=0;i<n;i++)
	{
		//b[c[a[i]]]=a[i];
		//c[a[i]]=c[a[i]]-1;
		
		output_array[--c[input_array[i]]]=input_array[i];
	}
	
	for(i=0;i<n;i++)
	{
		input_array[i]=output_array[i];
	}
	 
}

int main()
{
	int n=0;
	int i;
	int range=10;
	
	printf("**Counting Sort**")
	printf("Enter size of array:");
	scanf("%d",&n);
	
	int myarray[n];
	
	printf("Enter elements in array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&myarray[i]);
	}
	
	countingsort(myarray,n,range);
	
	printf("Sorted array using Counting Sort:");
	for(i=0;i<n;i++)
	{
		printf(" %d",myarray[i]);
	}
	printf("\n");
}