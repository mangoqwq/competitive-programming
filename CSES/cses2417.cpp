#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int MX = 1e6;
    int N; cin >> N;
    function<vector<int>(int)> fact = [&](int x){
        vector<int> ret;
        for (int i = 2; i * i <= x; ++i){
            if (x % i) continue;
            ret.push_back(i);
            while (x % i == 0) x /= i;
        }
        if (x != 1) ret.push_back(x);
        return ret;
    };
    vector<int> cnt(MX + 1);
    ll ans = 0;
    for (int i = 0; i < N; ++i){
        int x; cin >> x;
        vector<int> f = fact(x);
        int n = f.size();
        int cur = 0;
        for (int msk = 1; msk < (1 << n); ++msk){
            int num = 1;
            for (int j = 0; j < n; ++j){
                if (msk & (1 << j)) num *= f[j];
            }
            cur += cnt[num] * (__builtin_popcount(msk) % 2 ? 1 : -1);
        }
        ans += i - cur;
        for (int j = 1; j * j <= x; ++j){
            if (x % j) continue;
            cnt[j]++;
            if (j * j != x) cnt[x / j]++;
        }
    }
    cout << ans << '\n';
}
