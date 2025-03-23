//Lab 19 : WAP that integrates given function using basic simpson's 1/3 rule

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (exp(x))
int main()
{
	float x0,h,x1,x2,f0,f1,f2,integration;
	printf("Enter lower and upper limits:");
	scanf("%f%f",&x0,&x2);
	h=(x2-x0)/2;
	x1=x0+h;
	f0=F(x0);
	f1=F(x1);
	f2=F(x2);
	integration=h*(f0+4*f1+f2)/3;
	printf("Integration by simpson's 1/3 rule : %f",integration);
	
}