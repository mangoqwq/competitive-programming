#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int dp[6][3001];
vector<pii> items[6];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t,n; cin >> t >> n;
    for (int i=0,a,b,c;i<n;++i){
        cin >> a >> b >> c;
        items[c].push_back({a,b});
    }
    //first is cost, second is value.
    for (int tp=1;tp<=t;++tp){
        for (auto&&x:items[tp]){
            for (int i=3000;i>=x.first;--i){
                dp[tp][i]=max(dp[tp-1][i-x.first]+x.second,dp[tp][i]);
            }
        }
    }
    int b; cin >> b;
    if (dp[t][b]==-1) cout << -1 << '\n';
    else cout << dp[t][b] << '\n';
}