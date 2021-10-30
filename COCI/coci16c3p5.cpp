#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1, MM = 4e5 + 1;

map<int, int> mp[MN];
int N;
ll tot[MN], head[MN], len;
ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}

pair<int, ll> go(vector<ll> a){
    len = 0;
    ms(head, 0x3f); head[0] = 0;
    ms(tot, 0); tot[0] = 1;
    for (int i = 1; i <= N; ++i) mp[i].clear();
    mp[0][0] = 1;

    for (int i = 1; i < a.size(); ++i){
        int idx = lower_bound(head, head + 1 + N, a[i]) - head - 1;
// cout << idx << " ";
        while (true){
            auto [val, cnt] = *(--mp[idx].end());
            if (val < a[i]) break;
            tot[idx] = (tot[idx] - cnt + mod) % mod;
            mp[idx].erase(val);
        }
        idx++;
        if (idx > len) len = idx;
        tot[idx] = (tot[idx] + tot[idx - 1]) % mod;
        mp[idx][a[i]] = (mp[idx][a[i]] + tot[idx - 1]) % mod;

        head[idx] = min(head[idx], a[i]);
    }
    return {len, tot[len]};
// cout << len << " " << tot[len] * fpow(2, (N - len)) % mod << '\n';
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<ll> a(N + 1), b(1), l, r(1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 2; i <= N; ++i){
        if (a[i] < a[1]) l.push_back(a[i]);
        if (a[i] > a[1]) r.push_back(a[i]);
    }
    for (int i = N; i >= 2; --i) b.push_back(a[i]);
    for (int i = 2; i <= N; ++i) b.push_back(a[i]);
    l.push_back(0);
    reverse(l.begin(), l.end());
    auto [len, ans] = go(b); ans = ans * fpow(2, N - 1 - len) % mod;
    auto [lenl, ansl] = go(l);
    auto [lenr, ansr] = go(r);
// cout << len << " " << ans << '\n';
// cout << lenl << " " << ansl << '\n';
// cout << lenr << " " << ansr << '\n';
    ll sans = ansl * ansr * fpow(2, N - lenl - lenr - 1) % mod;
    if (lenl + lenr + 1 == len){
        ans = (ans + sans + mod) % mod;
        cout << len << " " << ans << '\n';
    }
    else if (lenl + lenr + 1 > len){ cout << lenl + lenr + 1 << " " << sans << '\n'; }
    else cout << len << " " << ans << '\n';

// for (int i = 1; i <= M; ++i) cout << a[i] << " ";
}
