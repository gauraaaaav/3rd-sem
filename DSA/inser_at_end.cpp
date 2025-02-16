#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int value;
    char choice;

    do {
        cout << "Enter a value to insert at the end: ";
        cin >> value;
        insertAtEnd(head, value);

        cout << "List after insertion: ";
        displayList(head);

        cout << "Do you want to insert another node at the end? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
