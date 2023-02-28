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
            cin >> a[i];
        }
        using pii = pair<int, int>;
        vector<pii> ans;
        for (int it = 0; it < 30; ++it){
            int j = min_element(a.begin(), a.end()) - a.begin();
            for (int i = 0; i < N; ++i){
                int nxt = (a[i] + a[j] - 1) / a[j];
                if (i != j && nxt != 1){
                    ans.push_back({i+1, j+1});
                    a[i] = nxt;
                }
            }
        }
        set<int> s;
        for (int x : a){
            s.insert(x);
            // cout << x << " ";
        }
        if (s.size() != 1){
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for (auto [i, j] : ans){
            cout << i << " " << j << '\n';
        }
    }
}
