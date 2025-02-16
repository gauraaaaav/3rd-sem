#include <iostream>
using namespace std;

// Node structure
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

// Function to delete at the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Function to display list
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
        cout << "Enter a value to insert at the beginning: ";
        cin >> value;
        insertAtBeginning(head, value);

        cout << "List after insertion: ";
        displayList(head);

        cout << "Do you want to insert another node at the beginning? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Do you want to delete the node at the beginning? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        deleteAtBeginning(head);
        cout << "List after deletion at the beginning: ";
        displayList(head);
    }

    return 0;
}
