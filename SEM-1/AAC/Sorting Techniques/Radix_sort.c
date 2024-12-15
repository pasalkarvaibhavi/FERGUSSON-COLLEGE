//Radix Sort

#include<stdio.h>

int maximum(int a[],int n)
{
	int i;
	int max=a[0];
	for(i=1;i<n;i++)
	{   
	if(a[i]>max)
	{
	
		max=a[i];
	}
	}
	return max;
}


void Countingsort(int a[],int n,int temp)
{
	
	int i;
	int output_array[n];
	int c[10]={0};
	
	for(i=0;i<n;i++)
	{
		c[(a[i]/temp)%10]++;
		
	}
	
	for(i=1;i<10;i++)
	{
			c[i]=c[i]+c[i-1];
			
	}
	

	for(i=n-1;i>=0;i--)
	{
		
		output_array[c[(a[i]/temp)%10]-1]=a[i];
		c[(a[i]/temp)%10]--;
	}
	
	for(i=0;i<n;i++)
	{
		a[i]=output_array[i];
	}
	 
}

void radixsort(int a[],int n)
{
	int m=maximum(a,n);
	int temp;
	for(temp=1;m/temp>0;temp*=10)
	{
		Countingsort(a,n,temp);
		
	}

}

int main()
{
	int i,j,n;
	
	printf("**Radix Sort**")
	printf("Enter total number of elements:");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	radixsort(a,n);
	
	printf("Sorted elements using Radix Sort: ");
	for(i=0;i<n;i++)
     {
     	printf(" %d",a[i]);
	 }
	 
	 
}