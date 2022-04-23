#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    map<int, int> mp;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        auto it = mp.upper_bound(a);
        if (it == mp.end()) mp[a]++;
        else{
            it->second--;
            if (it->second == 0) mp.erase(it);
            mp[a]++;
        }
    }
    int ans = 0;
    for (auto [a, b] : mp) ans += b;
    cout << ans << '\n';
}
