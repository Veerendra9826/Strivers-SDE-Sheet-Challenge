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
  sort(str.begin(), str.end()); // Sort the string in lexicographical order

    char maxChar = str[0];
    int maxCount = 1;
    int count = 1;

    int length = str.length();
    for (int i = 1; i < length; i++) {
        if (str[i] == str[i - 1]) {
            count++; // Increment count if the current character is the same as the previous one
        } else {
            if (count > maxCount || (count == maxCount && str[i] < maxChar)) {
                maxChar = str[i - 1];
                maxCount = count;
            }
            count = 1; // Reset count for a new character
        }
    }

    // Check the count for the last character
    if (count > maxCount || (count == maxCount && str[length - 1] < maxChar)) {
        maxChar = str[length - 1];
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