#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 1;
const int seed = 131;

string a[MN];
ll val[MN], hsh[MN];
map<ll, int> mp;
vector<int> adj[MN];
int dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + N, [](string a, string b){ return a.size() < b.size(); });

    for (int i = 1; i <= N; ++i){
        reverse(a[i].begin(), a[i].end());
        for (int j = 0; j < a[i].size() - 1; ++j){
            hsh[i] = (hsh[i] * seed + a[i][j]) % mod;
        }
        val[i] = (hsh[i] * seed + a[i].back()) % mod;
        if (mp.count(hsh[i])){
            int to = mp[hsh[i]];
            adj[to].push_back(i);
        }
        else if (a[i].size() == 1) adj[0].push_back(i);
        mp[val[i]] = i;
    }

    int ans = 0;
    for (int v = N; v >= 0; --v){
        int b1 = 0, b2 = 0;
        for (int to : adj[v]){
            if (dp[to] > b1) swap(b1, b2), b1 = dp[to];
            else if (dp[to] > b2) b2 = dp[to];
        }
        int vacant = max(0, (int)adj[v].size() - 2);
        ans = max(ans, b1 + b2 + (v != 0) + vacant);
        vacant = max(0, (int)adj[v].size() - 1);
        dp[v] = 1 + vacant + b1;
    }
    cout << ans << '\n';
}
