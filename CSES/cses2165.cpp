#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Pair{ int l, r; }; vector<Pair> ans;
void solve(int n, int l, int r){
    if (n == 0) return;
    int m = 6 - l - r;
    solve(n - 1, l, m);
    ans.push_back({l, r});
    solve(n - 1, m , r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    solve(N, 1, 3);
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) cout << l << " " << r << '\n';
}
