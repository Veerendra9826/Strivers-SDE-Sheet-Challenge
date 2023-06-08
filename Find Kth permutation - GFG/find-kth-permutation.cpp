//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> v;
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        int count = 1;
        while(count != k){
            next_permutation(v.begin(), v.end());
            count++;
        }
        string s="";
        for(int i=0; i<v.size(); i++){
            s = s + to_string(v[i]);
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends