#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=10001;
struct Edge{int n,w; bool visited;};

int denisbad,n,ending,g,r; ll ans=LLONG_MAX;
vector<int> arr;
vector<Edge> graph[MAXN]; ll visited[MAXN][1001];

void dfs(int node, int dist,ll t){
    cout << node << " " << dist << '\n';
    visited[node][dist]=t;
    if (node==n){
        ans=min(t,ans);
        return;
    }
    if (dist==0){
        t+=r;
        dist=g;
    }
    for (Edge &x:graph[node]){
        if (x.w>dist) continue;
        if (visited[x.n][dist-x.w]<=t+x.w) continue;
        dfs(x.n,dist-x.w,t+x.w);
    }
    return;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    ms(visited,0x3f);
    cin >> denisbad >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        arr.push_back(a);
    }
    cin >> g >> r;
    arr.push_back(-0x3f3f3f3f); arr.push_back(0x3f3f3f3f);
    sort(begin(arr),end(arr));
    if (arr[1]!=0){
        arr.push_back(0);
        n++;
    }
    if (arr[arr.size()-2]!=denisbad){
        arr.push_back(denisbad);
        n++;
    }
    sort(begin(arr),end(arr));
    //for (int i:arr) cout << i << " ";
    for (int i=1;i<=n;++i){
        for (int l=i-1;arr[i]-arr[l]<=g;--l){
            graph[i].push_back({l,arr[i]-arr[l],0});
        }
        for (int r=i+1;arr[r]-arr[i]<=g;++r){
            graph[i].push_back({r,arr[r]-arr[i],0});
        }
    }
    dfs(1,g,0);
    cout << (ans==LLONG_MAX?-1:ans) << '\n';
}