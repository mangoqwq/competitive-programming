#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    using pii = pair<int, int>;
    int N; cin >> N;
    vector<pii> ans;
    set<pii> s; 
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        if (a[i]) s.insert({a[i], i});
    }
    for (int i = 1; i <= N; ++i){
        if (!a[i]) continue;
        s.erase({a[i], i});
        vector<pii> sav;
        while (a[i]){
            if (s.empty()){
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
            int j = (--s.end())->second;
            s.erase(--s.end());
            a[j]--;
            sav.push_back({a[j], j});
            ans.push_back({i, j});
            a[i]--;
        }
        for (pii p : sav) if (p.first) s.insert(p);
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << " " << b << '\n';
}
