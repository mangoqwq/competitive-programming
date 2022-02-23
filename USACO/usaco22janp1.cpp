#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, B = 200, BLKS = MN / B + 1;
int N, K, a[MN], ans[MN];
int blk[MN], bmin[BLKS], bmax[BLKS];
vector<pair<int, int>> s[BLKS];

void rebuild(int b){
    bmin[b] = inf;
    bmax[b] = 0;
    s[b].clear();
    for (int i = B * b; i < min(B * (b + 1), N); ++i){
        if (a[i] == -1) continue;
        if (a[i] <= bmin[b] + K && a[i] >= bmax[b] - K){
            s[b].push_back({a[i], i});
        }
        bmin[b] = min(bmin[b], a[i]);
        bmax[b] = max(bmax[b], a[i]);
    }
    sort(s[b].begin(), s[b].end());
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        blk[i] = i / B;
        cin >> a[i];
    }
    for (int i = 0; i * B < N; ++i){
        rebuild(i);
    }
    for (int i = 0; i < N; ++i){
        int mn = inf, mx = 0;
        pair<int, int> best = {inf, -1};
        for (int b = 0; b * B < N; ++b){
            auto it = lower_bound(s[b].begin(), s[b].end(), make_pair(mx - K, -1));
            if (it != s[b].end()){
                if (it->first <= mn + K){
                    best = min(best, *it);
                }
            }
            mn = min(mn, bmin[b]);
            mx = max(mx, bmax[b]);
            if (mx - mn > 2 * K) break;
        }
        ans[i] = best.first;
        a[best.second] = -1;
        rebuild(blk[best.second]);
    }
    for (int i = 0; i < N; ++i){
        cout << ans[i] << '\n';
    }
}
