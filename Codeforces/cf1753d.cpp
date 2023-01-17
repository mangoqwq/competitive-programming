#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
pii del[] = {{-1, -1}, {-1, 1}, {-1, 1}, {1, 1}, {1, 1}, {1, -1}, {1, -1}, {-1, -1}, {-2, 0}, {0, 2}, {2, 0}, {0, -2}};
char deln[] = {'L', 'R', 'U', 'D', 'R', 'L', 'D', 'U', 'U', 'R', 'D', 'L'};
pii chk[] = {{-1, 0}, {-1, 0}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {0, -1}, {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char chkn[] = {'R', 'L', 'D', 'U', 'L', 'R', 'U', 'D', 'D', 'L', 'U', 'R'};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    ll P, Q; cin >> P >> Q;
    vector<vector<char>> g(N, vector<char>(M));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> g[i][j];
        }
    }

    vector<vector<ll>> dist(N, vector<ll>(M, 1e18));
    struct Item{
        int x, y; ll d;
        bool operator>(const Item &other) const{
            return d > other.d;
        }
    };
    priority_queue<Item, vector<Item>, greater<Item>> pq;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (g[i][j] == '.'){
                dist[i][j] = 0;
                pq.push({i, j, 0});
            }
        }
    }

    auto get = [&](int i, int j) -> char{
        if (i >= 0 && i < N && j >= 0 && j < M){
            return g[i][j];
        }
        return '?';
    };
    while (!pq.empty()){
        auto [x, y, d] = pq.top(); pq.pop();
        if (dist[x][y] != d) continue;
        // cout << x << " " << y << " -> ";
        for (int i = 0; i < 12; ++i){
            int nx = x + del[i].first;
            int ny = y + del[i].second;
            int cx = x + chk[i].first;
            int cy = y + chk[i].second;
            // cout << nx << " " << ny << " | ";
            if (get(nx, ny) != deln[i]) continue;
            if (get(cx, cy) != chkn[i]) continue;
            ll nd = d;
            if (i < 8) nd += P;
            else nd += Q;
            if (nd < dist[nx][ny]){
                // cout << x << " " << y << " " << nx << " " << ny << '\n';
                dist[nx][ny] = nd;
                pq.push({nx, ny, nd});
            }
        }
        // cout << '\n';
    }

    ll ans = 2e18;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (i > 0) ans = min(ans, dist[i][j] + dist[i-1][j]);
            if (j > 0) ans = min(ans, dist[i][j] + dist[i][j-1]);
            // if (dist[i][j] >= 1e18) cout << "_ ";
            // else cout << dist[i][j] << " ";
        }
        // cout << '\n';
    }
    if (ans >= 1e18) cout << -1 << '\n';
    else cout << ans << '\n';
}
