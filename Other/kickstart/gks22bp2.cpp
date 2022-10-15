#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> facts;
void solve(){
    ll A; cin >> A;
    ll ans = 0;
    for (ll x : facts) ans += (A % x == 0);
    cout << ans << '\n';
}

void precomp(){
    function<void(int, int, bool, string)> gen = [&](int i, int num, bool inc, string cur){
        if (i == num){
            string tmp = cur;
            reverse(tmp.begin(), tmp.end());
            if (!inc) tmp = tmp.substr(1);
            cur += tmp;
            facts.push_back(stoll(cur));
            return;
        }
        for (char c = '0'; c <= '9'; ++c){
            if (i == 0 && c == '0') continue;
            gen(i + 1, num, inc, cur + c);
        }
    };
    for (int i = 1; i <= 5; ++i){
        gen(0, i, 0, "");
        gen(0, i, 1, "");
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    precomp();
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
