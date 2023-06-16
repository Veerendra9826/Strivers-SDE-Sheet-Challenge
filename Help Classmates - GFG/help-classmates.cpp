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
        vector<int> v;
       
        int i=0;int j=i+1;
        while(i<n){
        if(arr[i]>arr[j])
        {
            v.push_back(arr[j]);
         
            i++;
               j=i+1;
          
          }
          else if( j>=n-1){
           
             v.push_back(-1);
             i++;
             j=i+1;
          }
          else
          j++;
         
        } 
        v[n-1]=-1; 
      return v;
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