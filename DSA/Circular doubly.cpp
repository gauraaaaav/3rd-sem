#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAtFront(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    cout << "Inserted at front: " << value << endl;
}

void insertAtMiddle(Node*& head, int value, int position) {
    if (position <= 0) { cout << "Invalid position." << endl; return; }
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp->next != head && count < position - 1) {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    cout << "Inserted at position " << position << ": " << value << endl;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
    cout << "Inserted at end: " << value << endl;
}

void deleteFromFront(Node*& head) {
    if (!head) { cout << "List is empty." << endl; return; }
    Node* temp = head;
    if (head->next == head) {
        head = nullptr;
    } else {
        Node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete temp;
    cout << "Deleted from front." << endl;
}

void deleteFromMiddle(Node*& head, int position) {
    if (!head || position <= 0) { cout << "Invalid position or empty list." << endl; return; }
    Node* temp = head;
    int count = 1;
    while (temp->next != head && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == head) { cout << "Position out of bounds." << endl; return; }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    toDelete->next->prev = temp;
    delete toDelete;
    cout << "Deleted from position " << position << "." << endl;
}

void deleteFromEnd(Node*& head) {
    if (!head) { cout << "List is empty." << endl; return; }
    Node* tail = head->prev;
    if (head == tail) {
        delete head;
        head = nullptr;
    } else {
        Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }
    cout << "Deleted from end." << endl;
}

void traverse(Node* head) {
    if (!head) { cout << "List is empty." << endl; return; }
    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}

void deleteList(Node*& head) {
    while (head) deleteFromFront(head);
}

int main() {
    Node* head = NULL; 
    int choice, value, position;
    do {
        cout << "\n1. Insert at Front\n2. Insert at Middle\n3. Insert at End\n4. Delete from Front\n5. Delete from Middle\n6. Delete from End\n7. Traverse\n8. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> value; insertAtFront(head, value); break;
            case 2: cout << "Value: "; cin >> value; cout << "Position: "; cin >> position; insertAtMiddle(head, value, position); break;
            case 3: cout << "Value: "; cin >> value; insertAtEnd(head, value); break;
            case 4: deleteFromFront(head); break;
            case 5: cout << "Position: "; cin >> position; deleteFromMiddle(head, position); break;
            case 6: deleteFromEnd(head); break;
            case 7: traverse(head); break;
        }
    } while (choice != 8);
    deleteList(head);
    return 0;
}

