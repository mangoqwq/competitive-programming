#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e4+1;

vector<int> graph[MAXN];
int marked[MAXN], sz[MAXN];
int ans, cntans;

int dfs0(int curr, int prev){
    sz[curr]=1;
    for (int x:graph[curr]){
        if (x==prev||marked[x]) continue;
        sz[curr]+=dfs0(x,curr);
    }
    return sz[curr];
}

int centroid(int curr, int prev, int size){
    for (int x:graph[curr]){
        if (x==prev||marked[x]) continue;
        if (sz[x]*2>=size) return centroid(x,curr,size);
    }
    return curr;
}

void dfs(int curr, int prev, int d, int &a, int &b){
    if (d>a) a=d, b=1;
    else if (d==a) b++;
    for (int x:graph[curr]){
        if (x==prev||marked[x]) continue;
        dfs(x,curr,d+1,a,b);
    }
}

void solve(int curr){
    int best=0, cnt=1;
    marked[curr]=1;
    for (int x:graph[curr]){
        if (marked[x]) continue;
        int a=0, b=0;
        dfs(x,x,1,a,b);
        if (best+a>ans) ans=best+a, cntans=cnt*b;
        else if (best+a==ans) cntans+=cnt*b;
        if (a>best) best=a, cnt=b;
        else if (a==best) cnt+=b;
    }
    for (int x:graph[curr]){
        if (marked[x]) continue;
        solve(centroid(x,x,dfs0(x,x)));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1);
    cout << cntans << '\n';
}