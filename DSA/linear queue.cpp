#include<iostream>
using namespace std;
#define max 100
int front=-1,rear=-1;
int a[max];
void enqueue()
{
	int value;
	if(rear==max-1)
	{
		cout<<"Queue overload!";
	}
	else
	{
		cout<<"Enter value to be enqueued:";
		cin>>value;
		if(front==-1&&rear==-1)
		{
			front=rear=0;
		}
		else
		rear++;
		
		a[rear]=value;
		cout<<value<<" inserted"<<endl;
		
	}
}

void dequeue()
{
	if(front==-1)
	{
		cout<<"Queue underflow!";
	}
	else
	{
		cout<<a[front]<<" removed\n";
		if(front==0&&rear==0)
		front=rear=-1;
		else
		front++;
	}
}

void traverse()
{
	if(front==-1)
	{
		cout<<"Queue underflow!";
	}
	cout<<"Elements in queue are:\n";
	for(int i=front;i<=rear;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
int main()
{
	int n;
	char ch;
	do{
	cout<<"Enter a choice:\n1.Enquque\n2.Dequeue\n3.Traverse\n4.Exit\n:";
	cin>>n;
	switch(n)
	{
		case 1:
			
				enqueue();
				break;
			
		case 2:
			{
				dequeue();
				break;
			}
		case 3:
			{
				traverse();
				break;
				
			}
		case 4:
			{
				cout<<"Bye Bye!";
				exit(0);
			}
		default:
			{
				cout<<"Wrong choice!";
				break;
				
			}
	}
	cout<<"Do you want to chooose again?\nY for Yes and N for No\n:";
	cin>>ch;
	system("cls");
	
}while(ch=='Y'||ch=='y');
}
