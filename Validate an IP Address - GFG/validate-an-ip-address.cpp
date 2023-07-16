//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            
    // code here
    int n = s.size();
    // for test case like 1...1 or something lesser than 7
    if (n < 7)
        return false;
    // Using string stream to separate all the string from
    // '.' and push back into vector like for ex -
    // 222.111.111.111 vector is v = ["222" , "111"  , "111"
    // , "111"]
    vector<string> v;
    stringstream ss(s);
    while (ss.good()) {
        string substr;
        getline(ss, substr, '.');
        v.push_back(substr);
    }
    // If the vector size != 4 return false,  like
    // 222.111.111.111  v = ["222" , "111"  , "111"  ,
    // "111"].
    if (v.size() != 4)
        return false;
    // Iterating over the generated vector of string
    for (int i = 0; i < v.size(); i++) {
        //
        string temp = v[i];
        // for leading zero , test case like 222.0.0.10 this
        // is valid but this is not vaild 222.00.100.100  , we
        // check for the size of the i th string if
        // temp.size() > 1 and if(temp[0] == '0') return
        // false;
        if (temp.size() > 1) {
            if (temp[0] == '0')
                return false;
        }
        // For test case like a.b.c.d , checking the alpha
        // values like abcde...... if any present simply
        // return false
 
        for (int j = 0; j < temp.size(); j++) {
            if (isalpha(temp[j]))
                return false;
        }
        // And lastly we are checking if the number is
        // greater than 255 or not
 
        if (stoi(temp) > 255)
            return false;
    }
    return true;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends