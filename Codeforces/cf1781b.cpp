#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        map<int, int> cnt;
        for (int i = 0; i < N; ++i){
            int x; cin >> x;
            cnt[x]++;
        }
        int cur = 0, ans = 1, lst = -1e9;
        for (auto [a, b] : cnt){
            if (cur < a && cur > lst) ans++;
            cur += b;
            lst = a;
        }
        cout << ans << '\n';
    }
}
