#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll limit=1000000001;
vector<int> s;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    s.push_back(0);
    for (int i=0,a;i<n;++i){
        cin >> a;
        int qsize=s.size();
        for (int i=0;i<qsize;++i){
            s.push_back(s[i]+a);
        }
    }
    sort(s.begin(),s.end());
    for (auto&&x:s){
        if (x>=m){
            cout << x-m << '\n';
            return 0;
        } 
    }
    cout << -1 << '\n';
}