#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    int cnt = N;
    while (K <= 1e6) K *= 2;
    vector<int> ans;
    if (1 & cnt) ans.push_back(K), cnt--;
    for (int i = 1; cnt; cnt -= 2, ++i) ans.push_back(K - i), ans.push_back(K + i);
    for (int i = 0; i < N; ++i) cout << ans[i] << (i == N - 1 ? '\n' : ' ');
}
