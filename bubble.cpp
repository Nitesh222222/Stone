#include <iostream>
using namespace std;

// Function to input elements into the array
void inputElements(int arr[], int& size) {
    cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Current Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted successfully!" << endl;
}

// Function to perform Linear Search
void linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at position " << i + 1 << "." << endl;
            return;
        }
    }
    cout << "Element " << key << " not found." << endl;
}

// Main function
int main() {
    int arr[100], size = 0, choice, key;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Input elements into the array" << endl;
        cout << "2. Display the array" << endl;
        cout << "3. Bubble Sort the array" << endl;
        cout << "4. Search for an element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputElements(arr, size);
            break;

        case 2:
            displayArray(arr, size);
            break;

        case 3:
            bubbleSort(arr, size);
            break;

        case 4:
            cout << "Enter the element to search for: ";
            cin >> key;
            linearSearch(arr, size, key);
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