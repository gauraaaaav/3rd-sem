//Lab 22 : WAP that integrates given function using composite simpson's 3/8 rule

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (exp(x))
int main()
{
	float x,x0,xn,h,f,f0,fn,integration=0;
	int n;
	printf("Enter lower and upper limits:");
	scanf("%f%f",&x0,&xn);
	printf("enter no. of segments:");
	scanf("%d",&n);
	h=(xn-x0)/n;
	f0=F(x0);
	fn=F(xn);
	x=x0;
	for(int i=1;i<n;i++)
	{
		x=x+h;
		f=F(x);
		if(i%3!=0)
		integration+=3*f;
		else
		integration+=2*f;
	}
	integration=3*h*(integration+f0+fn)/8;
	printf("Integration by composite simpson's 3/8 rule : %f",integration);
	
}
