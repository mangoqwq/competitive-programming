#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

double lfact[MAXN];
ll fact[MAXN], inv[MAXN];
struct Number{
    double val;
    int n, k;
    Number(int _n, int _k){
        n=_n, k=_k;
        if (n<=0||k<0||k>n) val=-1;
        val=lfact[n]-lfact[k]-lfact[n-k];
    }
    ll eval() const{
        return fact[n]*inv[k]%mod*inv[n-k]%mod;
    }
    bool operator<(const Number &x) const{
        return tie(val,n,k)<tie(x.val,x.n,x.k);
    }
    bool operator==(const Number &x) const{
        return n==x.n&&k==x.k;
    }
};
set<Number> vis;
priority_queue<Number> pq;

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod; e>>=1;
    }
    return ret;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    fact[0]=inv[0]=1;
    for (int i=1;i<=n;++i){
        lfact[i]=log10(i)+lfact[i-1];
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
    }
    pq.push(Number(n,n/2)); vis.insert(Number(n,n/2));
    ll ans=0;
    for (int i=1;i<=k;++i){
        auto [_,n1,k1]=pq.top();
        ans+=pq.top().eval(); pq.pop(); ans%=mod;
        if (!vis.count(Number(n1,k1-1))) pq.push(Number(n1,k1-1)), vis.insert(Number(n1,k1-1));
        if (!vis.count(Number(n1,k1+1))) pq.push(Number(n1,k1+1)), vis.insert(Number(n1,k1+1));
        if (!vis.count(Number(n1-1,k1-1))) pq.push(Number(n1-1,k1-1)), vis.insert(Number(n1-1,k1-1));
        if (!vis.count(Number(n1-1,k1))) pq.push(Number(n1-1,k1)), vis.insert(Number(n1-1,k1));
    }
    cout << ans << '\n';
}