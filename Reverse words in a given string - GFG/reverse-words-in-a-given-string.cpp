//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int i = S.length() - 1;
        string ans = "";
        while(i>=0){
            while(i>=0 && S[i] == '.'){
                i--;
            }
            int j = i;
            if(i<0){
                break;
            }
            while(i>=0 && S[i] != '.'){
                i--;
            }
             if (ans.empty()) {
            ans = ans.append(S.substr(i + 1, j - i));
        } else {
            ans = ans.append("." + S.substr(i + 1, j - i));
        }
            // if(ans.empty()){
            //     ans = ans.append(S.substr(i+1,j-i));
            // }
            // else{
            //     ans = ans.apppend("." + S.substr(i+1,j-i));
            // }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends