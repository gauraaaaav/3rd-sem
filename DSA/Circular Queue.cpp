#include<iostream>
using namespace std;
#define max 3
int front=-1,rear=-1;
int a[max];
void enqueue()
		{
			int item;
			if((front==0 && rear==max-1) ||(front==rear+1))
				cout<<endl<<"Queue overflow"<<endl;
			else
			{
				cout<<endl<<"Enter item to be enqueued: ";
				cin>>item;
				if(front==-1 && rear==-1)
					rear=front=0;
				else
					rear=(rear+1)%max;
				a[rear]=item;
			}
		}

void dequeue()
		{
			if( (front==-1 && rear==-1))
				cout<<endl<<"Queue underflow"<<endl;
			else
			{
				cout<<endl<<"Dequeued item  = "<<a[front]<<endl;
				if(rear==front)
					rear=front=-1;
				else
					front=(front+1)%max;
			}
				
		}

void traverse()
{
    if (front==-1 && rear==-1)
				cout<<endl<<"Queue underflow"<<endl;
				
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
