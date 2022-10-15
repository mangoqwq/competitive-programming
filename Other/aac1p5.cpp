#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

struct Edge{ int to, w; };
vector<Edge> adj[MAXN];
ll s[MAXN][2], h[MAXN][2], x, y, ans; // even, odd

void dfs(int v, int p){
    s[v][0]=s[v][1]=h[v][0]=h[v][1]=0;
    for (auto [to,w]:adj[v]){
        if (to==p) continue;
        dfs(to,v);
        s[v][0]+=s[to][0];
        s[v][1]+=s[to][1];
        s[v][0]+=(h[to][0^w]+(w==0))*h[v][0];
        s[v][0]+=(h[to][1^w]+(w==1))*h[v][1];
        s[v][1]+=(h[to][0^w]+(w==0))*h[v][1];
        s[v][1]+=(h[to][1^w]+(w==1))*h[v][0];
        h[v][0]+=h[to][0^w]+(w==0);
        h[v][1]+=h[to][1^w]+(w==1);
    }
    s[v][0]+=h[v][0];
    s[v][1]+=h[v][1];
}

void dp(int v, int p, ll par0, ll par1){
    ll h0=par0+h[v][0], h1=par1+h[v][1], tx, ty;
    for (auto [to,w]:adj[v]){
        if (to==p) continue;
        h0-=(h[to][0^w]+(w==0));
        h1-=(h[to][1^w]+(w==1));
        if (w==0) dp(to,v,h0+1,h1);
        else dp(to,v,h1,h0+1);
        tx=x-(h[to][0^w]+(w==0))*h0-(h[to][1^w]+(w==1))*h1-h[to][0^w]-(w==0);
        ty=y-(h[to][0^w]+(w==0))*h1-(h[to][1^w]+(w==1))*h0-h[to][1^w]-(w==1);
        w^=1;
        tx+=(h[to][0^w]+(w==0))*h0+(h[to][1^w]+(w==1))*h1+h[to][0^w]+(w==0);
        ty+=(h[to][0^w]+(w==0))*h1+(h[to][1^w]+(w==1))*h0+h[to][1^w]+(w==1);
        ans=min(ans,abs(tx-ty));
        w^=1;
        h0+=(h[to][0^w]+(w==0));
        h1+=(h[to][1^w]+(w==1));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<n;++i){
        int a, b, x; cin >> a >> b >> x;
        adj[a].push_back({b,x%2});
        adj[b].push_back({a,x%2});
    }
    dfs(1,1);
    x=s[1][0], y=s[1][1];
    ans=abs(x-y);
    dp(1,1,0,0);
    cout << ans << '\n';
}