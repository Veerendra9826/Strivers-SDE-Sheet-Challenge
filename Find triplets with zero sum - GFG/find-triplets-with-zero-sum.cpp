//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
 bool findTriplets(int arr[], int n)
{ 
    // Sorting the array in ascending order
    sort(arr,arr+n);
    
    // Initializing the first pointer
    int i = 0;
    
    // Loop through the array
    while(i<n){
        // Initializing the second pointer
        int j = i+1;
        
        // Initializing the third pointer
        int k = n-1;
        
        // Check for triplets
        while(j<k){
            // If the sum of the second and third elements is less than the negation of the first element
            if(arr[j]+arr[k] < -(arr[i])){
                j++; // Move the second pointer to the right
            }
            // If the sum of the second and third elements is greater than the negation of the first element
            else if(arr[j]+arr[k] > -arr[i]){
                k--; // Move the third pointer to the left
            }
            else {
                return true; // Triplet found
            }
        }
        
        // Move the first pointer to the right
        i++;
    }
    
    return false; // No triplet found
}

};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends