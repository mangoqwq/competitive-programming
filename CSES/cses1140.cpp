#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
int a[MN], b[MN], v[MN];
ll dp[2 * MN];
vector<int> eve[2 * MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin >> N;
    vector<int> comp;
    for (int i = 1; i <= N; ++i){
        cin >> a[i] >> b[i] >> v[i];
        comp.push_back(a[i]);
        comp.push_back(b[i]);
    }
    sort(comp.begin(), comp.end());
    T = comp.size();
    for (int i = 1; i <= N; ++i){
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
        b[i] = lower_bound(comp.begin(), comp.end(), b[i]) - comp.begin() + 1;
        eve[b[i]].push_back(i);
    }
    for (int i = 1; i <= T; ++i){
        dp[i] = max(dp[i], dp[i - 1]);
        for (int j : eve[i]){
            dp[i] = max(dp[i], dp[a[j] - 1] + v[j]);
        }
    }
    cout << dp[T] << '\n';
}
