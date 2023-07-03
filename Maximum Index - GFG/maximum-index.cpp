//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
          int i,j;
        int ans=0;
        
        vector<int>v1(n),v2(n);
        v1[0]=arr[0];
        v2[n-1]=arr[n-1];
        for(i=1;i<n;i++){
            v1[i]=min(v1[i-1],arr[i]);
            v2[n-i-1]=max(v2[n-i],arr[n-i-1]);
        }
        
        i=0,j=0;
        while(i<n && j<n){
            while(j<n && v1[i]<=v2[j]){
                j++;
            }
            ans=max(ans,j-i-1);
            i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends