#include<iostream>
using namespace std;
int fib(int n)
{
	if(n<=1)
	return 1;
	else
	return fib(n-1)+fib(n-2);
}

int main()
{
	int i,n;
	cout<<"Enter the nth term:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<fib(i)<<"\t";
	}
}
