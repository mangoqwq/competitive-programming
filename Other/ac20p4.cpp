#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3001;

int n, m;
vector<pii> edges;
bool adj[MAXN][MAXN];
struct Best{
    ll a, b, c, d;
    void print(){
        vector<ll> v1={a,b,c,d};
        sort(v1.begin(),v1.end());
        if (v1[0]==MAXN){ cout << -1 << '\n'; return;}
        if (a==0) cout << 3 << '\n';
        else cout << 4 << '\n';
        for (int i=(a==0);i<4;++i) cout << v1[i] << " ";
    }
    bool operator<(const Best &x) const{
        vector<ll> v1={a,b,c,d};
        vector<ll> v2={x.a,x.b,x.c,x.d};
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for (int i=0;i<4;++i){
            if (v1[i]!=v2[i]||i==3) return v1[i]<v2[i];
        }
        return 0;
    }
} ans={MAXN,MAXN,MAXN,MAXN};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a][b]=1; adj[b][a]=1;
        edges.push_back({a,b});
    }
    for (int i=0;i<m;++i){
        for (int j=i+1;j<m;++j){
            if (edges[i].first!=edges[j].first&&edges[i].first!=edges[j].second&&edges[i].second!=edges[j].first&&edges[i].second!=edges[j].second){
                ans=min(ans,{edges[i].first,edges[i].second,edges[j].first,edges[j].second});
            }
            if (edges[i].first==edges[j].first&&adj[edges[i].second][edges[j].second]) ans=min(ans,{0,edges[i].first,edges[i].second,edges[j].second});
            if (edges[i].first==edges[j].second&&adj[edges[i].second][edges[j].first]) ans=min(ans,{0,edges[i].first,edges[i].second,edges[j].first});
            if (edges[i].second==edges[j].first&&adj[edges[i].first][edges[j].second]) ans=min(ans,{0,edges[i].second,edges[i].first,edges[j].second});
            if (edges[i].second==edges[j].second&&adj[edges[i].first][edges[j].first]) ans=min(ans,{0,edges[i].second,edges[i].first,edges[j].first});
        }
    }
    ans.print();
}