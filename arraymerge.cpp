#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int size1 = mid - left + 1;  // size of left half
    int size2 = right - mid;     // size of right half

    int leftArr[size1];             // temp left array
    int rightArr[size2];    // temp right array

    for (int i = 0; i < size1; i++)
        leftArr[i] = arr[left + i];  // copy into left temp

    for (int i = 0; i < size2; i++)
        rightArr[i] = arr[mid + 1 + i];  // copy into right temp

    int i = 0;              // index for leftArr
    int j = 0;   // index for rightArr
    int k = left;       // index for main arr

    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k] = leftArr[i++];              // left val is smaller, use it
        else
            arr[k] = rightArr[j++]; // right val is smaller, use it
        k++;
    }

    while (i < size1)
        arr[k++] = leftArr[i++];        // copy remaining left elements

    while (j < size2)
        arr[k++] = rightArr[j++]; // copy remaining right elements
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;           // find middle index

        mergeSort(arr, left, mid);                  // sort left half
        mergeSort(arr, mid + 1, right);     // sort right half
        merge(arr, left, mid, right);               // merge both halves together
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    return 0;
}
