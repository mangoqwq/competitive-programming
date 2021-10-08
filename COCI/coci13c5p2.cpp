#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int a[1 << 10];
vector<int> ans[11];

void solve(int l, int r, int dep){
    if (l == r) return;
    int mid = (l + r) / 2;
    ans[dep].push_back(a[mid]);
    solve(l, mid, dep + 1);
    solve(mid + 1, r, dep + 1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int K; cin >> K;
    for (int i = 0; i < (1 << K) - 1; ++i) cin >> a[i];
    solve(0, (1 << K) - 1, 1);
    for (int i = 1; i <= K; ++i){
        for (int x : ans[i]) cout << x << " ";
        cout << '\n';
    }
}
