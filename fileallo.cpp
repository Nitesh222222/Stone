#include<iostream>

#include<vector>

using namespace std;

// Display blocks for a file

void displayFileBlocks(const string& filename, const vector<int>& blocks) {

cout << "File" << filename << " occupies blocks: ";

for (int block: blocks) {

cout << block << " "; }

cout << endl;
}

// Continuous Allocation

void continuousAllocation (const string& filename, vector<int>& disk, int startBlock, int length) {

cout << "Continuous Allocation for file " << filename << ":\n";

vector<int> fileBlocks;

bool allocated = true;

for (int i = startBlock; i < startBlock + length;

i ++) {

}

if (i >= disk.size() || disk[i] != -1) {

allocated = false;

break;
if (allocated) {

for (int i = startBlock; i < startBlock + length; i++) {

disk[i] = 1;

fileBlocks.push_back(i);

}

displayFileBlocks (filename, fileBlocks);

} else {

cout << "File" << filename << " could not be allocated contiguously.\n";

}

}

// Linked Allocation

struct LinkedBlock {

int blockNumber;

LinkedBlock next;

};

void linkedAllocation(const string& filename, vector<int>& disk, const vector<int>& blocks) {

cout << "Linked Allocation for file " << filename << ":\n";

LinkedBlock* head = nullptr;

LinkedBlock* current = nullptr;

for (int block: blocks) {

if (block >= disk.size() || disk [block] != -1)

{

cout << "Block" << block << " is unavailable.\n";

return;
}

}

for (int block: blocks) {

disk[block] = 1;

LinkedBlock newBlock = new LinkedBlock{block, nullptr);

if (!head) {

head = newBlock;

current = head;

} else {

current->next = newBlock;

current = newBlock;

}

}

current = head;

cout << "File" << filename << " occupies

blocks (linked): ";

while (current) {

cout << current->blockNumber << " ";

current = current->next; }

cout << endl;

// Free memory for the linked list

while (head) {

LinkedBlock temp = head;

head = head->next;

delete temp;

}
}

// Indexed Allocation

void indexedAllocation(const string& filename, vector<int>& disk, int indexBlock, const vector<int>& blocks) (

cout << "Indexed Allocation for file " << filename << ":\n";

if (indexBlock >= disk.size() || disk[indexBlock] != -1) {

cout << "Index block" << indexBlock << " is unavailable.\n";

return;

}

for (int block: blocks) {

if (block >= 'disk.size() || disk(block] != -1)

{

cout << "Block" << block << " is unavailable.\n";

return;

}

}

disk[indexBlock] = 1;

vector<int> fileBlocks;

for (int block: blocks) {

disk[block] = 1;

fileBlocks.push_back(block);

}

cout << "Index block: " << indexBlock <<< " points to blocks: ";

displayFileBlocks (filename, fileBlocks);
}

int main() {

vector<int> disk(100, -1); // -1 indicates free block

// Continuous Allocation

continuousAllocation("File1", disk, 5, 10); // Allocate from block 5, length 10

// Linked Allocation

vector<int> linkedBlocks = {20, 21, 22, 30};

linkedAllocation("File2", disk, linkedBlocks); // Allocate blocks 20, 21, 22, 30

// Indexed Allocation

vector<int> indexedBlocks = {40, 42, 43);

indexedAllocation("File3", disk, 35, indexedBlocks); // Index block 35 points to blocks 40, 42, 43

return 0;

}