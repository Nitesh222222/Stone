#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;
    int maxSize;
    int currentSize;

public:
    // Constructor to initialize stack
    Stack(int size) {
        top = nullptr;
        maxSize = size;
        currentSize = 0;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Check if the stack is full
    bool isFull() {
        return currentSize == maxSize;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        currentSize++;
        cout << "Pushed: " << value << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
        currentSize--;
    }

    // Get the element at the top of the stack
    void topElement() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    int size, choice, value;

    cout << "Enter the maximum size of the stack: ";
    cin >> size;

    Stack stack(size);

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Stack is Empty" << endl;
        cout << "4. Check if Stack is Full" << endl;
        cout << "5. Display Top Element" << endl;
        cout << "6. Display Stack" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            if (stack.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;

        case 4:
            if (stack.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;

        case 5:
            stack.topElement();
            break;

        case 6:
            stack.display();
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}