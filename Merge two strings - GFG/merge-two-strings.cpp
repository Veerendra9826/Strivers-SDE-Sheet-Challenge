//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string S1, string S2)
{
int i = 0; // Pointer for string 1
    int j = 0; // Pointer for string 2
    std::string result; // Final string

    // Merge the strings alternately until one of them reaches its end
    while (i < S1.length() && j < S2.length()) {
        result.push_back(S1[i]);
        result.push_back(S2[j]);
        i++;
        j++;
    }

    // Append remaining characters from string 1, if any
    while (i < S1.length()) {
        result.push_back(S1[i]);
        i++;
    }

    // Append remaining characters from string 2, if any
    while (j < S2.length()) {
        result.push_back(S2[j]);
        j++;
    }

    return result;
}