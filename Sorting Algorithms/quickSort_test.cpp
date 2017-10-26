#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& A, int low, int high) {
    int i = low, j = high;
    int temp;
    // The pivot chosen here will just be the mid element
    int pivot = A[(low + high) / 2];

    // This is the partitioning
    while (i <= j) {
        // if A[i] is less than the pivot then don't swap
        while (A[i] < pivot) {
            i++;
        }
        // if A[j] is greater than the pivot then don't swap
        while (A[j] > pivot) {
            j--;
        }

        // At this point, provided i < j, then we need to swap
        if (i <= j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }

    // so long as j is greater than the low index, recursively call
    if (low < j) {
        quickSort(A, low, j);
    }
    // Same here provided i < high
    if (i < high) {
        quickSort(A, i, high);
    }
}

// Driver program
int main() {
    vector<int> toSort{10,9,2,1,5,3,2,6,9,2,11,7};

    for (int i = 0; i < toSort.size(); i++) {
        cout << toSort[i] << " ";
    }
    cout << endl;

    quickSort(toSort, 0, toSort.size());

    for (int i = 0; i < toSort.size(); i++) {
        cout << toSort[i] << " ";
    }
    cout << endl;
}