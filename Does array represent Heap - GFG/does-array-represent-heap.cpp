//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
       for(int i = 0;i<n;i++){
           int leftchild = 2*i+1;
           int rightchild = 2*i+2;
           if(a[leftchild] > a[i] || a[rightchild] > a[i]){
               return false;
           }
       }
       return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends