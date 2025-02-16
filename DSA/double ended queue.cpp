#include <iostream>
#define max 100
using namespace std;
int a[max],front=-1,rear=-1;

void insertfront()
{
	int value;
	if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
                    cout << "Queue Overflow\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    if (front == -1) {
                        front = rear = 0;
                    } else if (front == 0) {
                        front = max - 1;
                    } else {
                        front--;
                    }
                    a[front] = value;
                    cout<<value<< " inserted\t";
                }
}

void insertrear()
{
	int value;
	 if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
                    cout << "Queue Overflow\n";
                } else {
                    cout << "Enter value: ";
                    cin >> value;
                    if (front == -1) {
                        front = rear = 0;
                    } else if (rear == max - 1) {
                        rear = 0;
                    } else {
                        rear++;
                    }
                    a[rear] = value;
                     cout<<value<< " inserted\n";
                }
}

void deletefront()
{
	if (front == -1) {
                    cout << "Queue Underflow\n";
                } else {
                    cout << a[front] << " deleted "<<endl;
                    if (front == rear) {
                        front = rear = -1;
                    } else if (front == max - 1) {
                        front = 0;
                    } else {
                        front++;
                    }
                }
}

void deleterear()
{
	if (front == -1) {
                    cout << "Queue Underflow\n";
                } else {
                    cout<<a[rear]<<" deleted" << endl;
                    if (front == rear) {
                        front = rear = -1;
                    } else if (rear == 0) {
                        rear = max - 1;
                    } else {
                        rear--;
                    }
                }
}

void display()
{
	if (front == -1) {
                    cout << "Queue is empty.\n";
                } else {
                	
                
                   
                    int i = front;
                    while (true) {
                        cout << a[i] << " ";
                        if (i == rear) break;
                        i = (i + 1) % max;
                    }
                    cout << endl;
                }
}


int main() {
	int n;
	char ch;
    do {
        cout << "\nMenu:\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter choice: ";
        cin >> n;

        switch (n) {
            case 1:
                insertfront();
                break;

            case 2:
               insertrear();
                break;

            case 3:
                deletefront();
                break;

            case 4:
                deleterear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
        
        cout<<"\nDo you want to choose again?  Yfor yes N for no\n:";
        cin>>ch;
      
    } while (ch=='Y'||ch=='y');

    return 0;
}
