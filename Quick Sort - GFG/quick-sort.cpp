//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
// Function to sort an array using the quicksort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // Base case: If the partition size is 0 or 1, the array is already sorted.
        if (low >= high)
            return;

        // Partition the array and get the pivot index.
        int p = partition(arr, low, high);

        // Recursively sort the left and right subarrays.
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }

public:
    // Function to partition the array and return the pivot index.
    int partition(int arr[], int low, int high)
    {
        // Choose the first element as the pivot.
        int pivot = arr[low];
        int cnt = 0;

        // Count the number of elements smaller or equal to the pivot.
        for (int i = low + 1; i <= high; i++)
        {
            if (arr[i] <= pivot)
            {
                cnt++;
            }
        }

        // Calculate the index where the pivot should be placed.
        int pivotindex = low + cnt;

        // Swap the pivot with the element at the pivot index.
        swap(arr[pivotindex], arr[low]);

        // Initialize two pointers, i and j.
        int i = low, j = high;

        // Move i to the right and j to the left, swapping elements as necessary.
        while (i < pivotindex && j > pivotindex)
        {
            // Move i to the right until an element greater than the pivot is found.
            while (arr[i] <= pivot)
            {
                i++;
            }

            // Move j to the left until an element smaller or equal to the pivot is found.
            while (arr[j] > pivot)
            {
                j--;
            }

            // If i and j have not crossed each other, swap the elements at i and j.
            if (i < pivotindex && j > pivotindex)
            {
                swap(arr[i++], arr[j--]);
            }
        }

        // Return the pivot index.
        return pivotindex;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends