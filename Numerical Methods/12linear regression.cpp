//lab 12: WAP to implement linear regression
#include<stdio.h>
#include<conio.h>

int main()

{
	int i,j,k,n;
	float a=0,b=0,x[10],y[10],sx=0,sy=0,sxy=0,sx2=0;
	printf("Enter no. of points:");
	scanf("%d",&n);
	printf("Enter value of x and fx\n");
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&x[i],&y[i]);
	}
	for(i=0;i<n;i++)
	{
		sx=sx+x[i];
		sy=sy+y[i];
		sxy=sxy+x[i]*y[i];
		sx2=sx2+x[i]*x[i];
	}
	
	b=((n*sxy)-(sx*sy))/((n*sx2)-(sx*sx));
	a=(sy/n)-(b*sx/n);
	printf("Fitted line is %.2f+%.2fx",a,b);
	getch();
}