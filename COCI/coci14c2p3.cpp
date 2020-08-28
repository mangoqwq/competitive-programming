#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
map<int,int> m;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    int count[n/k];
    vector<int> a;
    vector<int> b;
    for (int i=0,x;i<n;++i){
        cin >> x; a.push_back(x); b.push_back(x);
    }
    sort(begin(b),end(b));
    for (int i=0;i<n;++i){
        m[b[i]]=i/k;
        count[i/k]++;
    }
    int ans=0;
    for (int i=0;i<n;++i){
        
    }
}