#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

string lim;
ll dp[MAXN][2][2][2];

ll solve(int idx, bool flag, bool one, bool zero){
    if (idx>=lim.size()) return one&zero;
    ll &curr=dp[idx][flag][one][zero];
    if (curr!=-1) return curr;
    int top=(flag?lim[idx]-'0':9);
    curr=0;
    for (int i=zero;i<=top;++i){
        curr+=solve(idx+1,flag&(i==top),one|(i==1),zero|(one&(i==0)));
        curr%=mod;
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> lim; ms(dp,-1);
    cout << solve(0,1,0,0) << '\n';
}