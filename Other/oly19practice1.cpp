#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1;

ll N, a[MN];
bool can[MN][60];

ll sum(int l, int r){ return a[r] - a[l - 1]; }
int bsearch(int i, int sz){
    int lo = i, hi = N, mid;
    while (lo < hi){
        mid = (lo + hi + 1) >> 1;
        if (sum(i, mid) > (1LL << sz)) hi = mid - 1;
        else lo = mid;
    }
    return lo;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i]; 
        can[i][a[i]] = 1;
        a[i] = (1LL << a[i]) + a[i - 1];
    }
    for (int sz = 2; sz <= 60; ++sz){
        for (int i = 1; i <= N; ++i){
            if (sum(i, bsearch(i, sz)) != (1LL << sz)) continue;
            int j = bsearch(i, sz - 1);
            if (can[i][sz - 1] && can[j + 1][sz - 1]){
                can[i][sz] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= 60; ++j){
            if (can[i][j]) ans = max(ans, j);
        }
    }
    cout << ans << '\n';
}
