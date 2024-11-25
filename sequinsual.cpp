#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to add a student
void addStudent() {
    ofstream file("students.txt", ios::app); // Open file in append mode
    if (!file) {
        cout << "Error: Could not open file.\n";
        return;
    }

    int id, age;
    string name;
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Student Age: ";
    cin >> age;

    file << id << " " << name << " " << age << "\n"; // Write data to file
    file.close();

    cout << "Student added successfully!\n";
}

// Function to search for a student by ID
void searchStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error: Could not open file.\n";
        return;
    }

    int id, searchID, age;
    string name;
    bool found = false;

    cout << "Enter Student ID to search: ";
    cin >> searchID;

    while (file >> id) {
        file.ignore(); // Ignore space
        getline(file, name, ' ');
        file >> age;

        if (id == searchID) {
            cout << "Student Found:\n";
            cout << "ID: " << id << "\n";
            cout << "Name: " << name << "\n";
            cout << "Age: " << age << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchID << " not found.\n";
    }

    file.close();
}

// Function to update a student by ID
void updateStudent() {
    ifstream file("students.txt");
    ofstream tempFile("temp.txt");
    if (!file || !tempFile) {
        cout << "Error: Could not open file.\n";
        return;
    }

    int id, searchID, age;
    string name;
    bool found = false;

    cout << "Enter Student ID to update: ";
    cin >> searchID;

    while (file >> id) {
        file.ignore();
        getline(file, name, ' ');
        file >> age;

        if (id == searchID) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new Age: ";
            cin >> age;
            found = true;
        }

        tempFile << id << " " << name << " " << age << "\n"; // Write updated data
    }

    if (!found) {
        cout << "Student with ID " << searchID << " not found.\n";
    } else {
        cout << "Student updated successfully!\n";
    }

    file.close();
    tempFile.close();

    remove("students.txt");           // Remove old file
    rename("temp.txt", "students.txt"); // Rename temp file
}

// Function to delete a student by ID
void deleteStudent() {
    ifstream file("students.txt");
    ofstream tempFile("temp.txt");
    if (!file || !tempFile) {
        cout << "Error: Could not open file.\n";
        return;
    }

    int id, deleteID, age;
    string name;
    bool found = false;

    cout << "Enter Student ID to delete: ";
    cin >> deleteID;

    while (file >> id) {
        file.ignore();
        getline(file, name, ' ');
        file >> age;

        if (id == deleteID) {
            found = true; // Skip writing this record to temp file
        } else {
            tempFile << id << " " << name << " " << age << "\n"; // Write others
        }
    }

    if (!found) {
        cout << "Student with ID " << deleteID << " not found.\n";
    } else {
        cout << "Student deleted successfully!\n";
    }

    file.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");
}

// Function to display all student records
void displayStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error: Could not open file.\n";
        return;
    }

    int id, age;
    string name;

    cout << "\nAll Student Records:\n";
    cout << "-----------------------\n";
    while (file >> id) {
        file.ignore();
        getline(file, name, ' ');
        file >> age;
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << "\n";
    }
    file.close();
}

// Main function with a simple menu
int main() {
    int choice;

    do {
        cout << "\nStudent Information System\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                displayStudents();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}