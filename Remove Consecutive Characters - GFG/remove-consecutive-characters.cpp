//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        
        string str = "";
        // if(S.length() == 0){
        //     return str;
        // }
        for(int i = 0;i<S.length()-1;i++){
            if(S[i] != S[i+1]){
                str += S[i];
            }
        }
        str.push_back(S[S.length()-1]);
        return str;
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
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends