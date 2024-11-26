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
