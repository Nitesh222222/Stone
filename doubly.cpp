#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       
    Node* prev;      
    Node* next;     

    Node(int val) { // Constructor to initialize a new node
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head; // Points to the first node in the list

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert a new node at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete a node with a specific value
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;

        delete temp;
        cout << "Node with value " << val << " deleted." << endl;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Current List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function with options
int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Display the list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}