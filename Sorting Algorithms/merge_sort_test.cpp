#include <iostream>
#include <vector>

using namespace std;

// Now, merge halves back together and sort while merging
void merge(vector<int>& A, int low, int high, int mid) {
    // Index variables and temp array for storing sorted elements
    int i = low;
    int k = 0;
    int j = mid + 1;
    int temp[high-low+1];

    // Move through the two halves and add elements in sorted
    // Order to temporary array
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            temp[k] = A[i];
            k++;
            i++;
        } else {
            temp[k] = A[j];
            k++;
            j++;
        }
    }

    // When the above loop breaks, add remaining elements to temp
    while (i <= mid) {
        temp[k] = A[i];
        k++;
        i++;
    }

    while (j <= high) {
        temp[k] = A[j];
        k++;
        j++;
    }

    // Move temp back into A in the correct position (according to
    // low)
    for (i = low; i <= high; i++) {
        A[i] = temp[i-low];
    }
}

// Facilitates splitting and merging
void mergeSort(vector<int>& A, int low, int high) {

    int mid;
    // Keep splitting until low >= high
    if (low < high) {
        mid = (low + high) / 2;
        // Recursively split left and right
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        // Merge all halves and sort together
        merge(A, low, high, mid);
    }

}

// Driver program
int main() {
    vector<int> toSort{10,9,2,1,5,3,2,6,9,2,11,7};

    for (int i = 0; i < toSort.size(); i++) {
        cout << toSort[i] << " ";
    }
    cout << endl;

    mergeSort(toSort, 0, toSort.size());

    for (int i = 0; i < toSort.size(); i++) {
        cout << toSort[i] << " ";
    }
    cout << endl;
}