#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=100001,L=17; int n,t=0;
struct segment{
    int l,r,v,idx;
};
vector<int> graph[MAXN]; vector<segment> arr;
int in[MAXN],out[MAXN],up[L+1][MAXN];

bool cmp(segment a, segment b){return a.l<b.l;}

void generate(int &index,segment a){
    while (index<=n){
        segment t=arr[index];
        if (t.l>a.r){
            return;
        }
        graph[t.idx].push_back(a.idx);
        graph[a.idx].push_back(t.idx);
        index++;
        if (t.v<=a.v){
            generate(index,t);
        }
    }
}
void dfs(int node, int prev){
    in[node]=++t;
    up[0][node]=prev;
    for (int i=1;i<=L;++i){
        up[i][node]=up[i-1][up[i-1][node]];
    }
    for (auto&&x:graph[node]){
        if (x==prev) continue;
        dfs(x,node);
    }
    out[node]=++t;
}
bool is_ancestor(int x,int y){
    return in[x]<=in[y]&&out[x]>=out[y];
}
int lca(int a,int b){
    if (is_ancestor(a,b)) return up[0][a];
    if (is_ancestor(b,a)) return up[0][b];
    for (int i=L;i>=0;--i){
        if (!is_ancestor(up[i][a],b)){
            a=up[i][a];
        }
    }
    return up[0][a];
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    segment a;
    for (a.idx=1;a.idx<=n;++a.idx){
        cin >> a.l >> a.r >> a.v;
        arr.push_back(a);
    }
    a.l=0;a.r=1000000001;a.v=0x3f3f3f3f;a.idx=0; arr.push_back(a);
    sort(arr.begin(),arr.end(),cmp);
    int index=1;
    generate(index,a);
    dfs(0,0);

    int q,x,y,ans; cin >> q;
    while (q--){
        cin >> x >> y;
        ans=lca(x,y);
        if (ans==0) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}