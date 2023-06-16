//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
       vector<int> result; // Store the Next Smaller Element
                        // (NSE) for each element

    int i = 0; // Index of the current element
    int j = i + 1; // Index of the next element

    // Iterate over the array elements
    while (i < n) {
        if (arr[i] > arr[j]) {
            result.push_back(
                arr[j]); // Push the next smaller element to
                         // the result vector

            i++; // Move to the next element
            j = i + 1; // Update the next element index
        }
        else if (j >= n - 1) {
            result.push_back(
                -1); // No smaller element exists on the
                     // right side, so push -1

            i++; // Move to the next element
            j = i + 1; // Update the next element index
        }
        else {
            j++; // Move to the next element
        }
    }

    result[n - 1]
        = -1; // Set the NSE for the rightmost element as -1

    return result;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends