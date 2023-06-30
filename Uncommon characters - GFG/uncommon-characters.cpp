//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // if(A == B){
            //     return "-1";
            // }
            string ans = "";
            for(int i = 0;i<A.length();i++){
            if(B.find(A[i]) != string::npos){
                continue;
            }
            else{
                ans.push_back(A[i]);
            }
            }
             for(int i = 0;i<B.length();i++){
            if(A.find(B[i]) != string::npos){
                continue;
            }
            else{
                ans.push_back(B[i]);
            }
            }
            sort(ans.begin(),ans.end());
            auto it = unique(ans.begin(),ans.end());
            ans.resize(distance(ans.begin(),it));
             if(A == B || ans.empty() == true){
                return "-1";
            }
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends