/*
WAP to implementthe clipping using cohen sutherland algorithm.
a. Enter the clip window coordinate:200,200,400,400. Enter the endpoint-150,150,350,350
b. Enter te clip window coordinate:100,100,400,400. Enter endpoint: 50 50 250 350 
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;
typedef unsigned int outcode;
enum{
	top=0x1,bottom=0x2, rt=0x4,lt=0x8
};

outcode compoutcode(double x,double y,double xmin,double xmax,double ymin,double ymax)
{
	outcode code=0;
	if(y>ymax) code|=top;
	if(y<ymin) code|=bottom;
	if(x>xmax) code|=rt;
	if(x<xmin) code|=lt;
	return code;
}

void cslcad(double x0,double y0,double x1,double y1,double xmin,double xmax,double ymin,double ymax )
{
	outcode outcode0,outcode1,outcodeout;
	bool accept=false,done=false;
	
	outcode0=compoutcode(x0,y0,xmin,xmax,ymin,ymax);
	outcode1=compoutcode(x1,y1,xmin,xmax,ymin,ymax);
	
	cout<<"outcode0="<<outcode0<<endl;
	cout<<"outcode1="<<outcode1<<endl;
	
	while(!done)
	{
		if(outcode0==0&&outcode1==0)
		{
			accept=true;
			done=true;
		}
		else if(outcode0&outcode1)
		{
			done=true;
		}
		
		else{
			double x,y;
			int ocd=(outcode0!=0) ? outcode0 : outcode1;
			
			if(ocd&top)
			{
				x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
				y=ymax;
			}
			else if(ocd&bottom)
			{
				x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
				y=ymin;
			}
			else if(ocd&lt)
			{
				y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
				x=xmin;
			}
			else
			{
				y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
				x=xmax;
			}
             
			 if(ocd==outcode0)
			 {
			 	x0=x;
			 	y0=y;
			 	outcode0=compoutcode(x0,y0,xmin,xmax,ymin,ymax);
			}
			else{
				x1=x;
				y1=y;
				outcode1=compoutcode(x1,y1,xmin,xmax,ymin,ymax);
			}			
		}
	}
	
	if(accept)
	{
		line(x0,y0,x1,y1);
	}
}

int main()
{
	double xmin,xmax,ymin,ymax,x0,y0,x1,y1;
	
	initwindow(500,600);
	
	cout<<"Enter the bottom,left,right and top coordinate:";
	cin>>ymin>>xmin>>xmax>>ymax;
	
	rectangle(xmin,ymin,xmax,ymax);
	
	cout<<"Enter terminal points of line(x0,y0),(x1,y1):";
	cin>>x0>>y0>>x1>>y1;
	
	line(x0,y0,x1,y1);
	delay(5000);
	cleardevice();
	
	cslcad(x0,y0,x1,y1,xmin,xmax,ymin,ymax);
	
	rectangle(xmin,ymin,xmax,ymax);
	delay(5000);
	
	closegraph();
}
