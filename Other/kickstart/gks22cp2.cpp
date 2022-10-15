#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int N, X, Y; cin >> N >> X >> Y;
    int tot = N * (N + 1) / 2;
    if (tot % (X + Y)){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cout << "POSSIBLE" << '\n';
    tot = tot / (X + Y) * X;
    vector<int> v;
    for (int i = N; i >= 1; --i){
        if (i <= tot) tot -= i, v.push_back(i);
    }
    cout << v.size() << '\n';
    for (int x : v) cout << x << " ";
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
