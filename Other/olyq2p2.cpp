#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(x,idx) (1&(x>>idx))
#define get(x,idx) ((x/power[idx])%10)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll dp[19][(1<<8)][505];
ll power[20];

ll solve(int pos, int mask, int r, bool flag, ll lim){
    if (pos==-1){
        for (int i=2;i<=9;++i){
            if (i==5) continue;
            if (is(mask,(i-2))&&r%i!=0) return 0;
        } return 1;
    }
    ll &curr=dp[pos][mask][r];
    if (curr!=-1&&!flag) return curr;
    int top=(flag?get(lim,pos):9); ll ret=0;
    for (int i=0;i<=top;++i){
        if (pos==0&&is(mask,3)&&i%5!=0) continue;
        ret+=solve(pos-1,(i>=2?(mask|(1<<(i-2))):mask),(10*r+i)%504,flag&(i==top),lim);
    }
    if (!flag) curr=ret;
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dp,-1);
    power[0]=1;
    for (int i=1;i<20;++i) power[i]=power[i-1]*10;
    int t; cin >> t;
    while (t--){
        ll l,r; cin >> l >> r;
        r=solve(log10(r),0,0,1,r);
        if (l==1) l=1;
        else l=solve(log10(l-1),0,0,1,l-1);
        cout << r-l << '\n';
    }
}