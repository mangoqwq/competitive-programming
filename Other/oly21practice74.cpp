#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

vector<int> adj[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= 5 * n; ++i){
        if (i * (i - 1) == 2 * n) ans = i;
    }
    if (ans == 0) cout << "No" << '\n';
    else{
        cout << "Yes" << '\n';
        cout << ans << '\n';
        int T = 0;
        for (int i = 1; i <= ans; ++i){
            for (int j = i + 1; j <= ans; ++j){
                ++T;
                adj[i].push_back(T);
                adj[j].push_back(T);
            }
        }
        for (int i = 1; i <= ans; ++i){
            cout << adj[i].size() << " ";
            for (int to : adj[i]){
                cout << to << " ";
            }
            cout << '\n';
        }
    }
}
