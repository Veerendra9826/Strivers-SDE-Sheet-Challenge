//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
          // Your code goes here
        long long num1 = 0;
        long long num2 = 0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i = 0; i < n; i++)
            pq.push(arr[i]);
        bool turn1 = true;
        while(!pq.empty())
        {
            long long minElement = pq.top();
            pq.pop();
            if(turn1)
            {
                num1 = (num1 * 10) + minElement;
            }
            else
            {
                num2 = (num2 * 10) + minElement;
            }
            turn1 = !turn1;
        }
        return num1 + num2;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends