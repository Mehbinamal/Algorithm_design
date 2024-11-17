#include <iostream>
using namespace std;

int Partition(int A[], int LB, int UB) {
    int pivot = A[UB]; // Choosing the last element as pivot
    int j = LB - 1; // Pointer for the smaller element
    for (int i = LB; i < UB; i++) { // Loop through the array
        if (A[i] < pivot) { // Change to < for ascending order
            j++;
            // Swap A[i] and A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // Swap the pivot element with the element at j + 1
    int temp = A[UB];
    A[UB] = A[j + 1];
    A[j + 1] = temp;
    return j + 1; // Return the partitioning index
}

void Quick_sort(int A[], int LB, int UB) {
    if (LB < UB) { // Correct base case
        int pivot = Partition(A, LB, UB);
        Quick_sort(A, LB, pivot - 1); // Sort the left subarray
        Quick_sort(A, pivot + 1, UB); // Sort the right subarray
    }
}

int main() {
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;
    int A[n];
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    Quick_sort(A, 0, n - 1); // Correct upper bound
    cout << "Sorted Elements: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
