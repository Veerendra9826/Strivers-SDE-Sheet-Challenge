//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(string& str, vector<string>& ans, int index) {
    if (index >= str.length()) {
        ans.push_back(str);
        return;
    }
    for (int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        solve(str, ans, index + 1);
        swap(str[index], str[j]);
    }
}

vector<string> permutation(string S) {
    vector<string> ans;
    int index = 0;
    solve(S, ans, index);
    sort(ans.begin(),ans.end());
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends