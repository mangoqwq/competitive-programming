#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

string n;
ll k;
struct State{
    int idx; ll tot; bool zero, flag;
    bool operator<(const State &x) const{
        return tie(idx,tot,zero,flag)<tie(x.idx,x.tot,x.zero,x.flag);
    }
    bool operator==(const State &x) const{
        return tie(idx,tot,zero,flag)==tie(x.idx,x.tot,x.zero,x.flag);
    }
};
map<State,ll> dp;

ll solve(int idx, ll tot, bool zero, bool flag){
    if (idx==n.size()) return (!zero&&tot<=k);
    State curr={idx,tot,zero,flag};
    if (dp.count(curr)) return dp[curr];
    ll &cdp=dp[curr];
    int r=flag?n[idx]-'0':9;
    for (int i=0;i<=r;++i){
        bool still=zero&(i==0);
        cdp+=solve(idx+1,still?tot:tot*i,still,flag&(i==r));
    }
    return cdp;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    cout << solve(0,1,1,1) << '\n';
}