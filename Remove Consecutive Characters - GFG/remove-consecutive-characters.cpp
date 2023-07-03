//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        
            // Create a regular expression pattern that matches any character followed by one or more occurrences of the same character
    regex pattern("(.)\\1+");
    
    // Use the regex_replace function to replace all occurrences of the pattern in the string with a single occurrence of the matched character
    return regex_replace(S, pattern, "$1");
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