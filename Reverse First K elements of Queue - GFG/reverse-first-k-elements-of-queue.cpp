//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
       queue<int> modifiedQueue; // New queue to store modified elements
    int size = q.size(); // Size of the original queue
    int j = 0; // Counter for swapping elements
    int arr[size]; // Array to temporarily store elements from the original queue

    // Extract elements from the original queue and store them in the array
    for (int i = 0; i < size; i++) {
        arr[i] = q.front();
        q.pop();
    }

    // Swap elements from index j to index k-1
    while (j < k) {
        int temp = arr[j];
        arr[j] = arr[k - 1];
        arr[k - 1] = temp;
        j++;
        k--;
    }

    // Push the modified elements back to the new queue
    for (int i = 0; i < size; i++) {
        modifiedQueue.push(arr[i]);
    }

    return modifiedQueue; // Return the modified queue
}