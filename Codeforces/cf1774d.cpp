#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<vector<int>> a(N, vector<int>(M));
        vector<int> cnt(N);
        int tot = 0;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                cin >> a[i][j];
                cnt[i] += a[i][j] == 1;
            }
            tot += cnt[i];
        }

        if (tot % N){
            cout << -1 << '\n';
            continue;
        }
        int need = tot / N;

        vector<set<int>> helps(M);
        for (int i = 0; i < N; ++i){
            if (cnt[i] <= need) continue;
            for (int j = 0; j < M; ++j){
                if (a[i][j]) helps[j].insert(i);
            }
        }

        struct Answer{ int x, y, z; };
        vector<Answer> ans;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                if (cnt[i] >= need) break;
                if (a[i][j] == 0 && !helps[j].empty()){
                    int helper = *helps[j].begin();
                    helps[j].erase(helper);
                    ans.push_back({helper, i, j});
                    a[i][j] = 1;
                    a[helper][j] = 0;
                    cnt[helper]--;
                    cnt[i]++;
                    if (cnt[helper] == need){
                        for (int k = 0; k < M; ++k){
                            helps[k].erase(helper);
                        }
                    }
                }
            }
        }

        cout << ans.size() << '\n';
        for (auto [x, y, z] : ans){
            cout << x+1 << " " << y+1 << " " << z+1 << '\n';
        }
    }
}
