//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
 ll MOD = 1e9+7;
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        if(n==1)return {1};
        if(n==2)return {1,1};
        vector<vector<ll>> pas(n+1, vector<ll> (n+1, 1));
        
        for(ll i=2;i<=n;i++){
            for(ll j = 1;j<i-1;j++){
                pas[i][j] = (pas[i-1][j] + pas[i-1][j-1])%MOD;
            }
        }
        vector<ll> ans;
        for(int i=0;i<n;i++){
            ans.push_back(pas[n][i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends