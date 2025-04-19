//Menu driven program for Factorial ,Fibonacci, Palindrome and Perfect number.

#include<stdio.h>

int fact(int n);

int fib(int n);

int isPallindrome(int n);

int isPerfect(int n);

int main()
{
	printf("***Menu driven program for Factorial ,Fibonacci, Palindrome and Perfect number.***");
	
	int ch,n;
	
	while(1)
	{
		printf("\n");
		printf("\nChoose your option:");
		printf("\n1.Factorial\n2.Fibonacci.\n3.Palindrome.\n4.Perfect Number\n5.Exit");
		
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("\n**calculating factorial of given Number**");
				   printf("\nEnter Number:\n");
				   scanf("%d",&n);
				   printf("\nFactorial of %d is %d.",n,fact(n));
				   break;	
				   
			case 2:printf("\n**Fibonacci  Series Generation**");
				   printf("\nEnter Number:");
				   scanf("%d",&n);
				   printf("\nFibonacci Series:\n");
				   int i;
				   for(i=0;i<n;i++)
				   {
				   	printf(" %d",fib(i));
				   }
				   break;
			
			case 3:printf("**\nChecking number is Pallindrome or not**");
				   printf("\nEnter number:\n");
				   scanf("%d",&n);
				   isPallindrome(n);
				   
			case 4:printf("**Checking number is perfect or not.**");
					printf("\nEnter number:\n");
				   	scanf("%d",&n);
				    isPerfect(n);
			case 5:exit(0);
			      
				    
					
				   
		}
		
	}
	
	
}

int isPallindrome(int n)
{
	int reversed=0;
	while(n!=0)
	{
		reversed=reversed*10+n%10;
		n=n/10;
	}
	printf("\nReversed Number  :%d",reversed);
	
	if(n==reversed)
	{
		printf("\nNumber is pallindrome");
	}
	else
	{
		printf("\nNumber is not pallindrome");
	}

}
int isPerfect(int n)
{
	int i,sum=0,rem;
	for(i=1;i<n;i++)
	{
		rem=n%i;
		if(rem==0)
		{
			sum +=i;
		}
    }
    if(sum==n)
    {
    	printf("Number is perfect.");
	}
	else
	{
		printf("Not Perfect.");
	}
		
	}


int fact(int n)
{
	if(n<=1)
	{
		return 1;
	}
	else
		return n*fact(n-1);
}
int fib(int n)
{
	if(n==0)
			return 0;
	else if(n==1)
		return 1;
	else
		return (fib(n-1)+fib(n-2));
}