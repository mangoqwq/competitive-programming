#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll mod=1e9+7;
vector<int> tree[100001];
ll dp[100001];

ll dfs(int node,int prev){
    //cout << node << " ";
    if (dp[node]!=0) return dp[node];
    ll black=1;
    ll white=1;
    for (auto&&x:tree[node]){
        if (x==prev) continue;
        white*=dfs(x,node);
        white%=mod;
        for (auto&&y:tree[x]){
            if (y==node) continue;
            black*=dfs(y,x);
            black%=mod;
        }
    }
    return dp[node]=(black+white)%mod;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cout << dfs(1,0) << '\n';

}