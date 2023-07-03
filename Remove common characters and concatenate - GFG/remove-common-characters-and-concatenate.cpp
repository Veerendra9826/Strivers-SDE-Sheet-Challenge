//{ Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        vector<int> count1(26, 0);  // Array to count occurrences of characters in s1
    vector<int> count2(26, 0);  // Array to count occurrences of characters in s2
    
    // Count occurrences of each character in s1
    for (char ch : s1) {
        count1[ch - 'a']++;
    }
    
    // Count occurrences of each character in s2
    for (char ch : s2) {
        count2[ch - 'a']++;
    }
    
    string modified;  // String to store the modified string
    
    // Iterate over s1 and check for uncommon characters
    for (char ch : s1) {
        if (count2[ch - 'a'] == 0) {
            modified += ch;
        }
    }
    
    // Iterate over s2 and check for uncommon characters
    for (char ch : s2) {
        if (count1[ch - 'a'] == 0) {
            modified += ch;
        }
    }
    
    if (modified.empty()) {
        return "-1";
    }
    
    return modified;
    }

};

//{ Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}

// } Driver Code Ends