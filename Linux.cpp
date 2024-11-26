#include<iostream>

#include<fstream>

#include<string>

using namespace std;

// Function to simulate the UNIX 'cp' command: copy file content from source to destination

void cp(const string& sourceFile, const string& destinationFile) {

ifstream src(sourceFile, ios::binary);

ofstream dest(destinationFile, ios::binary);



if (!src) {

cout << "Error: Source file '" << sourceFile <<< "' cannot be opened.\n";

return;

}

if (!dest) {

cout << "Error: Destination file '" << destinationFile <<< "' cannot be opened.\n";

return;

}

dest << src.rdbuf(); // Copy the entire content of source file to destination file

cout << "File" << sourceFile << "' copied to " << destinationFile << "'.\n";

src.close();
dest.close();

}

// Function to simulate the UNIX 'cat' command: display the contents of a file

void cat(const string& filename) {

ifstream file(filename);

if (!file) {

cout << "Error: File " << filename << "" cannot be opened.\n";

return;

}

cout << "Displaying content of file: " <<< filename << "\n"; .

string line;

while (getline(file, line)) {

cout << line << endl;

}

file.close();

}

int main() {

string sourceFile, destinationFile, catFile;

// Simulate the 'cp' command

cout << "Enter the source file name for 'cp': ";

cin >> sourceFile;

cout << "Enter the destination file name for 'cp': ";

cin >> destinationFile;

cp(sourceFile, destinationFile);

// Simulate the 'cat' command

cout << "\nEnter the file name for 'cat': ";

cin >> catFile;

cat(catFile);

return 0;

}
