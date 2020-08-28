#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define get(x,a) ((x/expo[a-1])%10)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll dp[20][11][11][2];
ll expo[20];

ll solve(int pos, int p1, int p2, bool flag, bool zero, const ll &lim){
    assert(pos<20&&p1<11&&p2<11);
    if (pos==0) return 1;
    if (dp[pos][p1][p2][flag]!=-1) return dp[pos][p1][p2][flag];
    ll ans=0;
    int digit=get(lim,pos),top=(flag?digit:9);
    for (int i=0;i<=top;++i){
        if (!zero&&(i==p1||i==p2)) continue;
        ans+=solve(pos-1,(zero&&(i==0))?10:i,p1,flag&(i==top),zero&(i==0),lim);
    }
    return dp[pos][p1][p2][flag]=ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    expo[0]=1;
    for (int i=1;i<=19;++i) expo[i]=expo[i-1]*10;
    ll l,r; cin >> l >> r;
    ms(dp,-1);
    if (r==0) r=1;
    else r=solve(log10(r)+1,10,10,1,1,r);
    ms(dp,-1);
    if (l==0) l=0;
    else if (l==1) l=1;
    else l=solve(log10(l-1)+1,10,10,1,1,l-1);
    cout << r-l << '\n';
}