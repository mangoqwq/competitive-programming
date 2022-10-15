#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

mt19937_64 gen(5); uniform_int_distribution<ll> dis(1, 1e12);

set<char> seen;
map<char, ll> val;
map<ll, int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N;
    string s; cin >> s;
    ll tot = 0;
    for (char c : s){
        if (!seen.count(c)){
            val[c] = dis(gen);
            tot += val[c];
        }
        seen.insert(c);
    }
    K = seen.size();
    ll ans = 0, hsh = 0;
    cnt[0] = 1;
    for (char c : s){
        hsh = (hsh + val[c]) % tot;
        ans += cnt[hsh];
        cnt[hsh]++;
    }
    cout << ans % mod << '\n';
}
