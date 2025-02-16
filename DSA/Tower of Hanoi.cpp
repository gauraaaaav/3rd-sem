#include<iostream>
using namespace std;
int a=1;
void toh(int n,int s,int i,int d)
{
	
	if(n==1)
	{
	cout<<"Step "<<a<<": Move disk from source "<<s<<" to destination "<<d<<endl;
	a++;
    }
    else
	{
	toh(n-1,s,d,i);
	cout<<"Step "<<a<<": Move disk from source "<<s<<" to destination "<<d<<endl;
	a++;
	toh(n-1,i,s,d);
    }
}
int main()
{
	int n;
	cout<<"enter no of disks:";
	cin>>n;
	toh(n,1,2,3);
}
