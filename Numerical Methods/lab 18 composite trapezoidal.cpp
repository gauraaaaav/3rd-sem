//lab 18: WAP to integrate a given function using trapezoidal rule
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (exp(-x)) 
void trapezoidal(float x0,float x1)
{
	float f0,f1,i,h;
	h=(x1-x0);
	f0=F(x0);
	f1=F(x1);
	i=(f0+f1)*(h/2);
	printf("Integration:%f\n",i);
}
void composite(float x0,float x1,float n)
{
	float f0,fn,i=0,h,f,xi,sum;
	h=(x1-x0)/n;
	f0=F(x0);
	fn=F(x1);
	for(i=0;i<n;i++)
	{
		xi=x0+i*h;
		f=F(xi);
		sum=sum+2*f;
	}
	i=(f0+sum+fn)*h/2;
	printf("Integration:%f\n",i);
}
int main()
{
	float x0,x1,n;
	printf("Enter value of lower and uper limits and no. of segments:");
	scanf("%f%f%f",&x0,&x1,&n);
	if(n==1)
	trapezoidal(x0,x1);
	else
	composite(x0,x1,n);
}