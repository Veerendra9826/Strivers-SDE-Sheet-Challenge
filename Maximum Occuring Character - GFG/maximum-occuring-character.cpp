//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
int charCount[26] = {0}; // Initialize count array with zeros for lowercase alphabets

    int length = str.length();
    for (int i = 0; i < length; i++) {
        charCount[str[i] - 'a']++; // Increment the count for the corresponding alphabet
    }

    char maxChar = 'a';
    int maxCount = charCount[0];

    for (int i = 1; i < 26; i++) {
        if (charCount[i] > maxCount || (charCount[i] == maxCount && ('a' + i) < maxChar)) {
            maxChar = 'a' + i; // Get the corresponding alphabet
            maxCount = charCount[i];
        }
    }

    return maxChar;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends