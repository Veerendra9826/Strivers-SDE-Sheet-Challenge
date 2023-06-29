//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int n)
{
    set<int> s;
    while (1)
    {
        int sum = 0;
        while (n)
        {
            int ind = n % 10;
            sum += ind * ind;
            n /= 10;
        }
        if (sum == 1)
        {
            return true;
        }
        if (s.find(sum) != s.end())
        {
            return false;
        }
        s.insert(sum);
        n=sum;
    }
    return false;
}
int nextHappy(int n)
{
    n++;
    while (1)
    {
        
        if (isHappy(n))
        {
            return n;
        }
        n++;
    }
    return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends