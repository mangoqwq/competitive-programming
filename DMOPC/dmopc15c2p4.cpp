#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Anime{
    ll l,r,v;
    bool operator<(const Anime x) const{
        return r<x.r;
    }
} arr[MAXN];
set<ll> s;
map<ll,int> m;
ll dp[2*MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i].l >> arr[i].r >> arr[i].v;
        arr[i].r=arr[i].l+arr[i].r-1;
        s.insert(arr[i].l); s.insert(arr[i].r);
    }
    int cnt=0;
    for (ll x:s) m[x]=++cnt;
    for (int i=1;i<=n;++i){
        arr[i].l=m[arr[i].l];
        arr[i].r=m[arr[i].r];
    }
    sort(arr+1,arr+1+n);
    ll ans=0; int pos=1;
    for (int i=1;i<=n;++i){
        Anime x=arr[i];
        while (pos<=x.r) dp[pos]=dp[pos-1], pos++;
        dp[x.r]=max(dp[x.r],dp[x.l-1]+x.v);
        ans=max(ans,dp[x.r]);
    }
    cout << ans << '\n';
}