#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=36;

// 0 is a's turn, 1 is b's turn
vector<int> adj[MAXN];
map<ll,int> dp;

ll encode(ll mask, ll a, ll b){ return mask+(a<<40)+(b<<50); }

int dfs(ll mask1){
    ll mask=mask&((1LL<<40)-1);
    ll a=(mask1>>40)&((1LL<<10)-1);
    ll b=(mask1>>50)&((1LL<<10)-1);
    cout << mask1 << '\n';
    int ret=-0x3f3f3f3f;
    for (int x:adj[a]){
        if (mask&(1<<x)) continue;
        ret=max(ret,1-dfs(encode(mask|(1<<x),b,x)));
    }
    if (ret==0x3f3f3f3f){
        bool can=0;
        for (int x:adj[b]) can|=(mask&(1<<x));
        if (!can){ cout << "AAA" << '\n'; return 0; }
        ret=max(ret,-dfs(encode(mask,b,a)));
    }
    return ret;
}

int solve(){
    int n, ra, pa, rb, pb, m;
    cin >> n >> ra >> pa >> rb >> pb >> m;
    ra--; rb--;
    for (int i=0;i<n;++i){
        for (int j=1;j<=2*n-1;j+=2){
            adj[i*i+j].push_back((i-1)*(i-1)+j-1);
            adj[(i-1)*(i-1)+j-1].push_back(i*i+j);
            adj[i*i+j].push_back(i*i+j-1);
            adj[i*i+j-1].push_back(i*i+j);
            adj[i*i+j].push_back(i*i+j+1);
            adj[i*i+j+1].push_back(i*i+j);
        }
    }
    ll mask=0;
    for (int i=1,r,p;i<=m;++i){
        cin >> r >> p;
        mask|=(1<<(r*r+p));
    }
    return dfs(encode(mask,ra*ra+pa,rb*rb+pb));
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int t=1; //cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": " << solve() <<'\n';
    }
}