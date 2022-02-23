#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, M, A, B, C, D;
int a[MN], b[MN], c[MN];
struct Edge{ int to, id; };
vector<Edge> adj[MN];
struct Item{
    int v, d, c;
    bool operator<(const Item &x) const{
        return tie(d, c) > tie(x.d, x.c);
    }
};
int dist[MN][2], lst[MN][2];
bool on[MN];

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        cin >> a[i] >> b[i];
        adj[a[i]].push_back({b[i], i});
        adj[b[i]].push_back({a[i], i});
    }
    cin >> A >> B >> C >> D;
    ms(dist, 0x3f); 
    dist[A][0] = 0;
    priority_queue<Item> pq; pq.push({A, 0});
    while (!pq.empty()){
        auto [v, d, c] = pq.top(); pq.pop();
        for (auto [to, id] : adj[v]){
            int nc = c + (to == C || to == D);
            if (nc == 2) continue;
            if (dist[to][nc] > d + 1){
                dist[to][nc] = d + 1;
                lst[to][nc] = id;
                pq.push({to, dist[to][nc], nc});
            }
        }
    }
    if (dist[B][0] == inf && dist[B][1] == inf){
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= M; ++i){
        if ((a[i] == C && b[i] == D) || (a[i] == D && b[i] == C)){
            cout << -1 << '\n';
            return 0;
        }
    }
    int curv = B, curc = (dist[B][0] < dist[B][1] ? 0 : 1);
    on[B] = 1;
    while (curv != A){
        int e = lst[curv][curc];
        int nxtv = a[e] ^ b[e] ^ curv;
        if (curv == C || curv == D) curc--;
        on[nxtv] = 1;
        curv = nxtv;
        // cout << curv << " " << curc << '\n';
        assert(curv);
        assert(curc >= 0);
    }
    int paint = (on[C] ? D : C);
    for (auto [to, id] : adj[paint]){
        c[id] = 1;
    }
    cout << 2 << '\n';
    for (int i = 1; i <= M; ++i){
        cout << c[i] + 1 << '\n';
    }
}
