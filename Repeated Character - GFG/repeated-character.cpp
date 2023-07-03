//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        char ch = '#';
        int n = s.length();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(s[i] == s[j]){
                    ch = s[i];
                    return ch;
                }
            }
        }
        return ch;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends