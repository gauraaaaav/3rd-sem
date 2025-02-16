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


void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* current = head;
    int count = 1;
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position is out of range." << endl;
        return;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != nullptr) {
        current->prev->next = newNode;
    }
    current->prev = newNode;
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
    int value, position;
    char choice;

    do {
        cout << "Enter the value and position to insert at: ";
        cin >> value >> position;
        insertAtPosition(head, value, position);

        cout << "List after insertion: ";
        displayList(head);

        cout << "Do you want to insert another node at a specific position? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
