//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(int i = 0;i<n;i++){
        maxheap.push(a[i]);
    }
       for(int i = 0;i<n;i++){
        minheap.push(a[i]);
    }
    long long minele = minheap.top();
    long long maxele = maxheap.top();
    pair<long long , long long> p;
    p.first = minele;
    p.second = maxele;
    return p;
}