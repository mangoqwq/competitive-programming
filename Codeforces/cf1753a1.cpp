#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        int cnt = 0;
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            if (a[i]) cnt++;
        }
        if (cnt % 2 == 1){
            cout << -1 << '\n';
            continue;
        }
        using pii = pair<int, int>;
        vector<pii> ans;
        vector<int> cur;
        for (int i = 0; i < N; ++i){
            if (a[i] == 0){
                if (cur.empty()) ans.push_back({i, i});
                continue;
            }
            cur.push_back(i);
            if (cur.size() == 2){
                if (a[cur[0]] == a[cur[1]]){
                    if ((cur[1] - cur[0]) % 2 == 0){
                        ans.push_back({cur[0], cur[1]-2});
                        ans.push_back({cur[1]-1, cur[1]});
                    }
                    else{
                        ans.push_back({cur[0], cur[1]});
                    }
                }
                else{
                    for (int j = cur[0]; j <= cur[1]; ++j){
                        ans.push_back({j, j});
                    }
                }
                cur.clear();
            }
        }
        cout << ans.size() << '\n';
        for (auto [a, b] : ans){
            cout << a+1 << " " << b+1 << '\n';
        }
    }
}
