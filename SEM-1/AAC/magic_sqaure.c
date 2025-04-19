//Magic_square 
#include<stdio.h>

#define SIZE 20

void Gmagic(int order,int magic[SIZE][SIZE])
{
	int i,j,k,p,q;
	int mid=order/2;
	j=0;
	k=mid;
	
	for(i=1;i<=order*order;i++)
	{
		magic[j][k]=i;
		p=j--;
		q=k++;
		
		if(j<0)
			j=order-1;
		if(k>order-1)
			k=0;
		
		if(magic[j][k]!=0)
		{
			k=q;
			j=p+1;
		}
	}
}

int main()
{
	int order,i,j,magic[SIZE][SIZE]={0};
	printf("Magic_square !! ")
	printf("Enter Number:");
	scanf("%d",&order);
	
	if(order%2==0)
	{
		printf("Oder can be only odd.");
	}
	Gmagic(order,magic);
	
	printf("\nMagic Square:\n");
	for(j=0;j<order;j++)
	{
		for(i=0;i<order;i++)
		{
			printf("%4d ",magic[j][i]);
		}
		
		printf("\n");
		
	}
	return 0;
}