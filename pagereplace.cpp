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