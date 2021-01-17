#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=2e5+1,MAXC=3001;

ll fact[MAXN], inv[MAXN], dp[MAXC];
int r,c,n; 
struct Square{ int r,c; };
vector<Square> s;

bool cmp(Square a, Square b){ return tie(a.r,a.c)<tie(b.r,b.c); }

ll fpow(ll x, ll e){
    ll expo=x,ans=1;
    for (int i=0;(1<<i)<=e;++i){
        if (e&(1<<i)) ans*=expo, ans%=mod;
        expo*=expo, expo%=mod; 
    }
    return ans;
}

void gen(){
    ll curr=1; fact[0]=1; inv[0]=1;
    for (int i=1;i<=r+c;++i){
        curr*=i; curr%=mod;
        fact[i]=curr;
        inv[i]=fpow(curr,mod-2);
    }
}

ll cnt(Square a, Square b){
    return fact[b.r-a.r+b.c-a.c]*inv[b.r-a.r]%mod*inv[b.c-a.c]%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> n;
    gen();
    for (int i=1,a,b;i<=n;++i){
        cin >> a >> b;
        s.push_back({a,b});
    } s.push_back({r,c});
    sort(s.begin(),s.end(),cmp);
    for (int i=0;i<=n;++i){
        dp[i]=cnt({1,1},s[i]);
        for (int j=0;j<i;++j){
            if (s[j].r>s[i].r||s[j].c>s[i].c) continue;
            dp[i]-=dp[j]*cnt(s[j],s[i])%mod;
            dp[i]+=mod; dp[i]%=mod;
        }
    }
    cout << dp[n] << '\n';
}