#include <iostream>
#define N 10  
using namespace std;
int hash[N]; 
void Table() {
    for (int i = 0; i <N; i++) {
        hash[i] = -1;
    }
}

int hashFunction(int key) {
    return key % N;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    while (hash[index] != -1) {
    	
        index = (index + 1) % N;
        if (index == originalIndex) 
		{ 
            cout << "Hash table is full! Cannot insert " << key << endl;
            return;
        }
    }
    hash[index] = key;
    cout << "Inserted " << key << " at index " << index << endl;
}


void displayTable() {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Index " << i << ": ";
        if (hash[i] == -1)
            cout << "empty";
        else
            cout << hash[i];
        cout << endl;
    }
}

int main() {
    Table();
    int n, key;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> key;
        insert(key);
    }
    
    displayTable();
    
    return 0;
}
