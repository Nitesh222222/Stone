int BinarySearch(int a[], int n, in key)

int left = 0, right = n-1; while (left <= right)

{ int middle = (left + right) / 2; if (key < a[middle]) else if (key > > a[middle]) else return middle; right = middle - 1; left = middle + 1; } return -1;