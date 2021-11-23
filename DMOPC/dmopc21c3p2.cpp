#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6;

map<ll, ll> mp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll K; cin >> K;
    if (K == 0){
        cout << 1 << '\n' << 1 << '\n';
        return 0;
    }
    for (ll i = 0; i <= MN; ++i){
        ll cur = (i) * (i + 1) / 2;
        mp[cur] = i;
        if (mp.count(K - cur) && (mp[K - cur] + i + 1 <= MN || (mp[K - cur] == 0))){
            ll j = mp[K - cur];

            vector<int> ans;
            while (i--) ans.push_back(0);
            if (j != 0) ans.push_back(1);
            while (j--) ans.push_back(0);
            cout << ans.size() << '\n';
            for (int k = 0; k < ans.size(); ++k){
                cout << ans[k] << (k == ans.size() - 1 ? '\n' : ' ');
            }

            return 0;
        }
    }
    cout << -1 << '\n';
}
