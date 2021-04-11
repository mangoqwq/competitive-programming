#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int p[MAXN];
int Find(int x){ return (p[x]==x?x:p[x]=Find(p[x])); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a==b) return;
    p[b]=a;
}
struct Edge{
    int a, b; ll w;
    bool operator<(const Edge &x) const{ return w<x.w; }
};
vector<Edge> v;
vector<int> ord;
ll val[MAXN];
bool vis[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        v.clear(); ord.clear();
        int n; ll k; cin >> n >> k;
        for (int i=1;i<=n;++i) cin >> val[i], ord.push_back(i), vis[i]=0;
        ll ans=0;
        sort(ord.begin(),ord.end(),[](int a, int b){ return val[a]<val[b]; });
        for (int src:ord){
            if (vis[src]) continue;
            ll curr=val[src];
            for (int i=src-1;i>=1;--i){
                curr=gcd(curr,val[i]);
                if (curr!=val[src]) break;
                v.push_back({src,i,val[src]});
                if (vis[i]) break;
                vis[i]=1;
            }
            curr=val[src];
            for (int i=src+1;i<=n;++i){
                curr=gcd(curr,val[i]);
                if (curr!=val[src]) break;
                v.push_back({src,i,val[src]});
                if (vis[i]) break;
                vis[i]=1;
            }
        }
        for (int i=2;i<=n;++i) v.push_back({i,i-1,k});
        sort(v.begin(),v.end());
        iota(p+1,p+1+n,1);
        for (auto [a,b,w]:v){
            if (Find(a)==Find(b)) continue;
            Union(a,b), ans+=w;
        }
        cout << ans << '\n';
    }
}