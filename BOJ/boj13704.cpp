#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 1e5 + 1, MAXA = (1 << 20) + 1;
const int B = 500;

int n, k, m, a[MAXN], blk[MAXN];
ll ans[MAXN];
int cnt[MAXA];
struct Query{
    int l, r, id;
    friend bool operator<(const Query &a, const Query &b){
        if (blk[a.l] == blk[b.l]) return a.r < b.r;
        return a.l < b.l;
    }
};
vector<Query> q_large, q_small;

void ins(int l, int r, ll &ans){
    for (int i = l; i <= r; ++i){
        ans += cnt[a[i] ^ k];
        cnt[a[i]]++;
    }
}

void rem(int l, int r){
    for (int i = l; i <= r; ++i) cnt[a[i]]--;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
        blk[i] = i / B;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int l, r; cin >> l >> r; l--;
        if (r - l > B) q_large.push_back({l, r, i});
        else q_small.push_back({l, r, i});
    }
    for (auto [l, r, id] : q_small){
        ins(l, r, ans[id]);
        rem(l, r);
    }
    sort(q_large.begin(), q_large.end());
    int lastblk = -1, blk_end, pr;
    ll cur = 0 ;
    for (auto [l, r, id] : q_large){
        if (blk[l] != lastblk){
            ms(cnt, 0);
            lastblk = blk[l];
            blk_end = (blk[l] + 1) * B - 1;
            pr = blk_end + 1;
            cur = 0;
        }
        if (pr <= r){
            ins(pr, r, cur);
            pr = r + 1;
        }
        ll tmp = 0;
        ins(l, blk_end, tmp);
        rem(l, blk_end);
        ans[id] = cur + tmp;
    }
    for (int i = 1; i <= m; ++i){
        cout << ans[i] << '\n';
    }
}
