#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;       // To store data
    Node* next;     // Pointer to the next node

    Node(int val) { // Constructor to initialize a new node
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head; // Pointer to the first node of the list

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val); // Create a new node
        newNode->next = head;         // Link new node to the current head
        head = newNode;               // Update head to the new node
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val); // Create a new node
        if (head == nullptr) {        // If the list is empty
            head = newNode;           // Set head to the new node
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;        // Traverse to the last node
        }
        temp->next = newNode;         // Link the last node to the new node
    }

    // Delete a node with a specific value
    void deleteNode(int val) {
        if (head == nullptr) { // If the list is empty
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        // If the head node holds the value
        if (head->data == val) {
            Node* temp = head;
            head = head->next; // Update head to the next node
            delete temp;       // Free the old head node
            cout << "Node with value " << val << " deleted." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Find the node with the value
        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) { // Value not found
            cout << "Value not found in the list." << endl;
            return;
        }

        prev->next = temp->next; // Bypass the node to delete
        delete temp;             // Free the memory
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

// Main function with menu-driven program
int main() {
    SinglyLinkedList list;
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