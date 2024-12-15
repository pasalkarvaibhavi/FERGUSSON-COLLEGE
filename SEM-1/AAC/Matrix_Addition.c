//Matrix Addition

#include<stdio.h>

int main()
{
	int r,c,i,j,a[100][100],b[100][100],add[100][100];
	
	printf("\n*****Matrix Addition.****");
	
	printf("\nEnter total number of rows:");
	scanf("%d",&r);
	
	printf("\nEnter total number of columns:");
	scanf("%d",&c);
	
	printf("\nEnter Element of matrix A:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\n Enter elements of A%d%d:",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\nEnter Element of matrix B:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter elements of B%d%d:",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	
		
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			add[i][j]=a[i][j]+b[i][j];
		}
	}
		printf("\n matrix a:\n");
	 for(i=0;i<r;i++)
	 {
	 	for(j=0;j<c;j++)
	 	{
	 		printf("%d ",a[i][j]);
	 		if(j==c-1)
	 		{printf("\n\n");
			 }
		 }
	 }
		printf("\n matrix b:\n");
	 for(i=0;i<r;i++)
	 {
	 	for(j=0;j<c;j++)
	 	{
	 		printf("%d ",b[i][j]);
	 		if(j==c-1)
	 		{printf("\n\n");
			 }
		 }
	 }
	printf("\nAddition of matrix a and b:\n");
	 for(i=0;i<r;i++)
	 {
	 	for(j=0;j<c;j++)
	 	{
	 		printf("%d ",add[i][j]);
	 		if(j==c-1)
	 		{printf("\n\n");
			 }
		 }
	 }
}