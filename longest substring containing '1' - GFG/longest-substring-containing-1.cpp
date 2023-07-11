//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxlength(string s);
int main()
{
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
cout<<maxlength(s)<<endl;
}
return 0;
}

// } Driver Code Ends


int maxlength( string s)
{
    regex pattern("1+"); // Regular expression pattern to match one or more '1'
    int maxLength = 0;

    // Find all matches of the pattern in the binary string
    sregex_iterator it(s.begin(), s.end(), pattern);
    sregex_iterator end;

    while (it != end) {
        int length = it->length();
        maxLength = max(maxLength, length);
        ++it;
    }

    return maxLength;
}