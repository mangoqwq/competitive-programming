#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

double ask(int i, int j){
    cout << "? " << i << " " << j << '\n';
    cout.flush();
    double w; cin >> w;
    if (w < 0){ exit(0); }
    return w;
}
struct Edge{ int to; double w; };
vector<Edge> adj[MN];
int N;
double val[MN], mn, mx = inf;
int ans[MN];
void dfs(int v){
    if (val[v] > 0){
        mn = max(mn, 1 / val[v]);
        mx = min(mx, N / val[v]);
    }
    else{
        mn = max(mn, 1.0 / N * -val[v]);
        mx = min(mx, 1 * -val[v]);
    }
    for (auto [to, w] : adj[v]){
        val[to] = -w / val[v];
        dfs(to);
    }
}

void attempt(double v1){
    for (int i = 1; i <= N; ++i){
        double tmp;
        if (val[i] > 0) tmp = v1 * val[i];
        else tmp = -val[i] / v1;
        if (abs(tmp - round(tmp)) > 1e-5) return;
        ans[i] = round(tmp);
    }
    cout << "! ";
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << (i == N ? '\n' : ' ');
    }
    exit(0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    adj[1].push_back({4, ask(1, 4)});
    adj[4].push_back({2, ask(2, 4)});
    adj[1].push_back({3, ask(1, 3)});
    for (int i = 6; i <= N + 1; i += 2){
        adj[i - 3].push_back({i - 1, ask(i - 3, i - 1)});
        if (i <= N) adj[i - 2].push_back({i, ask(i - 2, i)});
    }
    val[1] = 1, dfs(1);
    attempt(mn); attempt(mx);
}
