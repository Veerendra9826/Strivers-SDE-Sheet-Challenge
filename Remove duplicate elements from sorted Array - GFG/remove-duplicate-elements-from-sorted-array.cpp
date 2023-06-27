//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
          // Using the unique method to remove duplicates
    int* end_ptr = unique(a, a + n);

    // Counting the number of distinct elements
    int distinctCount = end_ptr - a;

    // // Printing the modified array with distinct elements
    // for (int i = 0; i < distinctCount; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    return distinctCount;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends