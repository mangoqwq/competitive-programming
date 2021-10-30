#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2010;

char g[MN][MN];
bool vis[MN][MN];

char get(pair<int, int> a){
    return g[a.first][a.second];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> g[i][j];
        }
    }
    string ans = "";
    ans += g[1][1];
    vector<pair<int, int>> last, cur;
    cur.push_back({1, 1}); vis[1][1] = 1;
    for (int _ = 2; _ <= N + M - 1; ++_){
// cout << ans << " ";
        swap(cur, last); cur.clear();
        for (auto [x, y] : last){
            if (x != N && !vis[x + 1][y]) vis[x + 1][y] = 1, cur.push_back({x + 1, y});
            if (y != M && !vis[x][y + 1]) vis[x][y + 1] = 1, cur.push_back({x, y + 1});
        }
        sort(cur.begin(), cur.end(), [](pair<int, int> a, pair<int, int> b){ return get(a) < get(b); });
        while (get(cur.back()) != get(cur.front())) cur.pop_back();
        ans += get(cur.front());
    }
    cout << ans << '\n';
}
