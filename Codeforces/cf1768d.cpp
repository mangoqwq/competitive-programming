#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i]; a[i]--;
        }
        vector<int> vis(N);
        int T = 0;
        for (int i = 0; i < N; ++i){
            if (vis[i]) continue;
            T++;
            int v = i;
            while (true){
                vis[v] = T;
                v = a[v];
                if (v == i) break;
            }
        }
        int ans = N - T + 1;
        for (int i = 1; i < N; ++i){
            if (vis[i] == vis[i-1]){
                ans -= 2;
                break;
            }
        }
        cout << ans << '\n';
    }
}
