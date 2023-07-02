//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
 bitset<26> occurrence;
    
    for (char ch : s) {
        // Calculate the index of the character in the bitset
        int index = ch - 'a';
        
        // Check if the character has already occurred
        if (occurrence[index]) {
            return false;
        }
        
        // Mark the character as occurred
        occurrence[index] = true;
    }
    
    return true;
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
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends