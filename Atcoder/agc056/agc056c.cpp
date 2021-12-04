#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

struct Edge{
    int to, w;
    bool operator<(const Edge &x) const{
        return w > x.w;
    }
};
vector<Edge> adj[MN];
int ans[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        adj[i].push_back({i - 1, 1});
        adj[i - 1].push_back({i, 1});
    }
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b; a--;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 0});
    }
    priority_queue<Edge> pq;
    pq.push({0, 0});
    ms(ans, 0x3f);
    ans[0] = 0;
    while (!pq.empty()){
        int v = pq.top().to; pq.pop();
        for (auto [to, w] : adj[v]){
            if (ans[v] + w < ans[to]){
                ans[to] = ans[v] + w;
                pq.push({to, ans[to]});
            }
        }
    }
    // for (int i = 1; i <= N; ++i){
    //     cout << ans[i] << " ";
    // }
    // cout << '\n';
    for (int i = 1; i <= N; ++i){
        if (ans[i] > ans[i - 1]) cout << 0;
        else cout << 1;
    }
    cout << '\n';
}
