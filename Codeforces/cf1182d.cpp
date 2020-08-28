#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

vector<int> graph[MAXN];
int val[MAXN], sz[MAXN], n; bool ans=1;

int dfs(int curr, int prev){
    sz[curr]=1;
    for (int x:graph[curr]){
        if (x==prev) continue;
        sz[curr]+=dfs(x,curr);
    }
    return sz[curr];
}

int centroid(int curr, int prev){
    for (int x:graph[curr]){
        if (x==prev) continue;
        if (sz[x]*2>n) return centroid(x,curr);
    }
    return curr;
}

void solve(int curr, int prev, int d){
    if (val[d]==-1) val[d]=graph[curr].size();
    else if (val[d]!=graph[curr].size()) ans=0;
    for (int x:graph[curr]){
        if (x==prev) continue;
        solve(x,curr,d+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; 
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1);
    int s=centroid(1,1);
    ms(val,-1); solve(s,s,0);
    cout << (ans?s:-1) << '\n';
}