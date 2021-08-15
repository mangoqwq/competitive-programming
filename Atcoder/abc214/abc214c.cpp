#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> S(N), T(N), ans(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    for (int i = 0; i < N; ++i) cin >> T[i];
    int src = min_element(T.begin(), T.end()) - T.begin();
    ans[src] = T[src];
    for (int i = 1; i < N; ++i){
        int idx = (src + i) % N;
        int last = (src + i - 1) % N;
        ans[idx] = min(T[idx], ans[last] + S[last]);
    }
    for (int x : ans) cout << x << '\n';
}
