//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        int arr[n+m];
        int j = 0;
        for(int i= 0;i<n;i++){
            arr[j++] = a[i];
        }
        for(int i = 0;i<m;i++){
            arr[j++] = b[i]; 
        }
        int size = sizeof(arr)/sizeof(arr[0]);
        set<int>st;
        for(int i = 0;i<size;i++){
            st.insert(arr[i]);
        }
        return st.size();
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends