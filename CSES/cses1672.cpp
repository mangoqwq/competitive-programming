#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 501;

ll dist[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    ms(dist, 0x3f);
    for (int i = 1; i <= N; ++i) dist[i][i] = 0;
    for (int i = 1; i <= M; ++i){
        int a, b; ll c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int k = 1; k <= N; ++k){
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (Q--){
        int a, b; cin >> a >> b;
        if (dist[a][b] == inf) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
    }
}
