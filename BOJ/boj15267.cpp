#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int n;
vector<int> ans;
struct Edge{ int nxt, to; } adj[2*MAXN];
int h[MAXN], T, sz[MAXN];

int dfs(int v, int p){
    sz[v]=1;
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].to;
        if (to==p) continue;
        sz[v]+=dfs(to,v);
    }
    return sz[v];
}

void solve(int x){
    int cnt=0;
    for (int i=1;i<=n;++i) cnt+=(sz[i]%x==0);
    if (cnt==(n/x)) ans.push_back((n/x)-1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[++T]={h[a],b}, h[a]=T;
        adj[++T]={h[b],a}, h[b]=T;
    }
    dfs(1,1);
    for (int i=1;i*i<=n;++i){
        if (n%i==0){
            solve(i);
            if (i*i!=n) solve(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    for (int i=1;i<ans.size();++i) cout << ans[i] << " ";
    cout << '\n';
}