#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

// Function to check if a page exists in the frame

bool isPagelnFrame(int page, vector<int> &frame) {

return find(frame.begin(), frame.end(), page) != frame.end();

}

// Function to print the current state of frames

void printFrame(vector<int> &frame) {

for (int i = 0; i < frame.size(); i++) {

if (frame[i] == -1) cout << "-";

else cout << frame[i] << " ";

}

cout << endl;

}

// FIFO Page Replacement Algorithm

void FIFO(vector<int> pages, int frameSize) {

vector<int> frame (frameSize, -1); // Initialize frame with -1

int index = 0; // Track the oldest page

int pageFaults = 0;

cout << "FIFO Page Replacement:\n";

for (int page: pages) {

if (!isPagelnFrame(page, frame)) {

frame[index] = page;

index = (index + 1) % frameSize; // Circular increment for FIFO

pageFaults++;

cout << "Page " << page << "loaded: ";
} else {

cout << "Page " << page << " already in

frame: ";

}

printFrame(frame);

}

cout << "Total page faults: " << pageFaults <<< endl << endl;

}

// LRU Page Replacement Algorithm

void LRU(vector<int> pages, int frameSize) {

vector<int> frame (frameSize, -1); // Initialize frame with -1

vector<int> lastUsed (frameSize, -1); // Track last usage of each page

int pageFaults = 0;

cout << "LRU Page Replacement:\n";

for (int i = 0; i < pages.size(); i++) {

int page = pages[i];

if (!isPageInFrame(page, frame)) {

int Irulndex = distance(lastUsed.begin(), min_element(lastUsed.begin(), lastUsed.end()));

frame[Irulndex] = page;

pageFaults++;

cout << "Page " << page << "loaded: ";

} else {

cout << "Page " << page << " already in frame: ";

}

// Update last used time

lastUsed [find(frame.begin(), frame.end(), page) - frame.begin()] = i;

printFrame(frame);
}

cout << "Total page faults: " << pageFaults <<<< endl << endl;

}

// Optimal Page Replacement Algorithm

void Optimal(vector<int> pages, int frameSize) {

vector<int> frame (frameSize, -1); // Initialize frame with -1

int pageFaults = 0;

cout << "Optimal Page Replacement:\n";

for (int i = 0; i < pages.size(); i++) {

int page = pages[i];

if (!isPageInFrame(page, frame)) {

if (find(frame.begin(), frame.end(), -1)

!= frame.end()) {

// If there is an empty space, use it

*find(frame.begin(), frame.end(), -1)

= page;

} else {

// Find the page to replace based on future use

vector<int> future(frameSize, pages.size()); // Default future usage to beyond end

for (int j = 0; j < frameSize; j++) {

for (int k = i + 1; k < pages.size();

k++) {

}

if (frame[j] == pages[k]) {

future[j] = k;

break;
}
}

}

// Replace the page that will be used furthest in the future

int replaceIndex = distance(future.begin(), max_element(future.begin(), future.end()));

frame[replaceIndex] = page; }

pageFaults++;

cout << "Page " << page << " loaded: ";

} else {

cout << "Page " << page << " already in frame: "; }

printFrame(frame); }

cout << "Total page faults: " << pageFaults

<<< endl;

}

int main() {

vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2);

int frameSize = 3;

FIFO(pages, frameSize);

LRU(pages, frameSize);

Optimal(pages, frameSize);

return 0;

}