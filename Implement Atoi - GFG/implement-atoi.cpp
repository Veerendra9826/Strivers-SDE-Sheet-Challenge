//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
           int ans=0;
        bool f =0;
        int j =0;
        if(str[0]=='-'){
            f=true;
            j=1;
        }
        for(int i =j;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9')
            ans = ans*10+(str[i]-'0');
            else return -1;
        }
        if(f==1)ans *= -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends