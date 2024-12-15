//Matrix Multiplicatoion

#include<stdio.h>
int main()
{
	int i,j,k,r,c,a[100][100],b[100][100],mult[100][100]={0};
	
	printf("**Matrix Multiplicatoion**\n");
	
	printf("\nEnter total number of rows:");
	scanf("%d",&r);
	
	printf("\nEnter total number of coloums:");
	scanf("%d",&c);
	
	printf("\nEnter element of A:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter elements of a%d%d:",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	
		
	printf("\nEnter element Of B:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter elements of b%d%d:",i+1,j+1);
			scanf("%d",&b[i][j]);
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
	
	
	
	printf("\nMatrix B:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",b[i][j]);
			if(j==c-1)
			{
				printf("\n\n");
			}
		}
	}
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				mult[i][j]+=a[i][k]*b[k][j];
				
			}
		}
	}
	
	printf("\nMatrix A*B:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			
			printf("%d ",mult[i][j]);
			if(j==c-1)
			{
				printf("\n\n");
			}
		}
	}
}