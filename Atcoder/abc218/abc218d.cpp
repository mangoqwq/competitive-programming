#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

map<pair<int, int>, ll> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> recs (n);
    for (auto &[x, y] : recs) cin >> x >> y;
    sort(recs.begin(), recs.end());
    vector<int> cur;
    int i = 0;
    ll ans = 0;
    while (i != n){
        int curx = recs[i].first;
        while (i != n && recs[i].first == curx){
            cur.push_back(recs[i].second);
            i++;
        }
        for (int j = 0; j < cur.size(); ++j){
            for (int k = j + 1; k < cur.size(); ++k){
                ans += cnt[{cur[j], cur[k]}];
                cnt[{cur[j], cur[k]}]++;
            }
        }
        cur.clear();
    }
    cout << ans << '\n';
}
