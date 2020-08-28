#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1'000'001;

ll val[MAXN];
vector<int> graph[MAXN];
bool vis[MAXN];
vector<int> ans;
int n; ll k;

bool bfs(int node, ll &w){
    bool end=false;
    w+=val[node];
    ans.push_back(node);
    vis[node]=true;
    if (w>=k && w<=2*k) return true;
    for (int x:graph[node]){
        if (vis[x]) continue;
        end |= bfs(x,w);
        if (end) return end;
    }
    return end;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i){
        cin >> val[i];
        if (val[i]>=k&&val[i]<=2*k){
            cout << 1 << '\n' << i << '\n';
            return 0;
        }
    }
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        if (val[a]>k||val[b]>k) continue;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll temp;
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        ans.clear(); temp=0;
        if (bfs(i,temp)){
            cout << ans.size() << '\n';
            for (int x:ans){
                cout << x << " ";
            }
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    
}