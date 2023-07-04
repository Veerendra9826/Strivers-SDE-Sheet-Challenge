//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
         long long p=1;//intial product
        int l=0,r=0,ans=0;
        while(r<n)
        {
            p=p*a[r];
            while(p>=k&&l<=r)//decrementing window from left
            {
                p=p/a[l];
                l++;
            }
            ans=ans+(r-l+1);//ending with rth index element hiw many sub arrays
            r++;
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
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends