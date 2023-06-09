//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		       // Code here there
            int n = S.length();
            vector<string> vect;
            
            //find the factorial of the number
            int res=1, i;
            for(int i=2;i<=n;i++)
            {
                res*=i;
            }
            res--;
            
            //push first original string
            vect.push_back(S);
            
            //using std find permutations and store in vector
            while(res--)
            {
                next_permutation(S.begin(),S.end());
                vect.push_back(S);
            }
            
            //iterator to the vector
             vector<string>::iterator ip;
             
             //sorting the vector
            sort(vect.begin(),vect.end());
            
            //removing duplicate permutaions
            ip = unique(vect.begin(),vect.end());
            //resizing the vector on duplicate elimintation
            vect.resize(distance(vect.begin(), ip));
            
            return vect;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends