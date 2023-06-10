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
void revK(queue<int> &q, int k)
{
    int N = q.size();
    if(k == 0) return;
    
    int temp = q.front();
    q.pop();
    
    revK(q, k-1);
    
    for(int i=0; i<k-1; i++)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
    q.push(temp);
    for(int i=0; i<N-k; i++)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}
queue<int> modifyQueue(queue<int> q, int k) {
    
    revK(q, k);
    
    return q;
}