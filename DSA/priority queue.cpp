#include <iostream>
using namespace std;
#define max 100
int a[max],prior[max],front=-1,rear=-1;

void enqueue()
{
	if (rear == max - 1) {
                    cout << "Queue is full.\n";
                } else {
                    int value, priority, i;
                    cout << "Enter value and priority: ";
                    cin >> value >> priority;

                    if (front == -1) {
                        front=rear=0;
                        a[rear] = value;
                        prior[rear] = priority;
                    } else {
                        for (i = rear; i >= front && prior[i] > priority; i--) {
                            a[i + 1] = a[i];
                            prior[i + 1] = prior[i];
                        }
                        a[i + 1] = value;
                        prior[i + 1] = priority;
                        rear++;
                    }
                }
}

void dequeue()
{
	if (front == -1) {
                    cout << "Queue is empty.\n";
                } else {
                    cout<< a[front] << " deleted"<<endl;
                    if (front == rear) {
                        front = -1;
                        rear = -1;
                    } else {
                        front++;
                    }
                }
}

void display()
{
	if (front == -1) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Priority Queue: ";
                    for (int i = front; i <= rear; i++) {
                        cout << "(" << a[i] << ", "<< prior[i] << ") ";
                    }
                    cout << endl;
                }
}
int main() {
	char ch;
	int n;
    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\nEnter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Bye Bye!";
                exit(0);

            default:
                cout << "Invalid choice. Try again.\n";
        }
        
        cout<<"Do you want to choose again?\tY for yes, N for No\n:";
        cin>>ch;
        
    } while (ch=='Y'||ch=='y');

    return 0;
}
