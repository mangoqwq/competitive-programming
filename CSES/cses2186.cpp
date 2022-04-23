#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int inf = 0x3f3f3f3f;
const int MN = 0;

mt19937 gen(3);
uniform_int_distribution<ll> dis(1, 1e15);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    ll mod = 0;
    vector<ll> hsh(26);
    for (char c : s) hsh[c - 'a'] = dis(gen);
    for (ll val : hsh) mod += val;
    unordered_map<ll, int> cnt;
    ll cur = 0, ans = 0;
    cnt[0] = 1;
    for (char c : s){
        cur = (cur + hsh[c - 'a']) % mod;
        ans += cnt[cur];
        cnt[cur]++;
    }
    cout << ans << '\n';
}
