#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, SZ = 300;

struct Query{ int l, r, id; };
vector<Query> qs[MN / SZ + 1];
struct Answer{
    int cnt, c;
    bool operator<(const Answer &x) const{
        return tie(cnt, c) < tie(x.cnt, x.c);
    }
} ans[MN];
int a[MN], cnt[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= Q; ++i){
        int l, r; cin >> l >> r;
        if ((r - l + 1) < SZ){
            for (int j = l; j <= r; ++j){
                cnt[a[j]]++;
                ans[i] = max(ans[i], {cnt[a[j]], a[j]});
            }
            for (int j = l; j <= r; ++j) cnt[a[j]]--;
        }
        else{
            qs[(l + SZ - 1) / SZ].push_back({l, r, i});
        }
    }
    for (int k = SZ; k <= N; k += SZ){
        int blk = k / SZ;
        sort(qs[blk].begin(), qs[blk].end(), [](Query a, Query b){ return a.r < b.r; });
        int p = k; Answer rans = {0, 0};
        for (auto [l, r, id] : qs[blk]){
            while (p <= r){
                cnt[a[p]]++;
                rans = max(rans, {cnt[a[p]], a[p]});
                p++;
            }
            ans[id] = rans;
            for (int i = k - 1; i >= l; --i){
                cnt[a[i]]++;
                ans[id] = max(ans[id], {cnt[a[i]], a[i]});
            }
            for (int i = k - 1; i >= l; --i) cnt[a[i]]--;
        }
        for (int i = p - 1; i >= k; --i) cnt[a[i]]--;
    }

    for (int i = 1; i <= Q; ++i){
        cout << ans[i].c << '\n';
    }
}
