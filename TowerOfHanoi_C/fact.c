#include<stdio.h>
#include<conio.h>
void main()
{
int n;
printf("Enter the value :");
scanf("%d",&n);
n=fact(n);
printf("%d\n",n);
}

int fact(int n)
{
	if(n==1)
		return 1;
	else 
		return (n*fact(n-1));
}	
	