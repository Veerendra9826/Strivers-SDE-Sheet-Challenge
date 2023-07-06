//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
           int mn = m+n;
           int i = 0,j = 0,k = 0;
           int arr3[mn];
           while(i<n && j<m){
               if(arr1[i] < arr2[j]){
                   arr3[k++] = arr1[i++];
               }
               else{
                   arr3[k++] = arr2[j++];
               }
           }
           while(i<n){
               arr3[k++] = arr1[i++];
           }
           while(j<m){
               arr3[k++] = arr2[j++];
           }
           k = 0;
           for(i = 0;i<n;i++){
               arr1[i] = arr3[k++];
           }
           j=0;
           for(k = n;k<mn;k++){
               arr2[j++] = arr3[k];
           }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends