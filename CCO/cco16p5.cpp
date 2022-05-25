#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int K; cin >> K;

    struct Point{ int x, y; }; 
    vector<Point> ps;
    for (int i = 1; i <= K; ++i){
        int x, y; cin >> x >> y;
        ps.push_back({x, y});
    }

    function<ll(int)> countQ = [&](int Q) -> ll{
        vector<int> comp;
        for (auto [x, y] : ps){
            comp.push_back(max(x - Q, 1));
            comp.push_back(min(x + Q, N) + 1);
        }
        sort(comp.begin(), comp.end());
        comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

        struct Event{ int op, x, l, r; };
        vector<Event> eves;
        for (auto [x, y] : ps){
            int l = lower_bound(comp.begin(), comp.end(), max(x - Q, 1)) - comp.begin();
            int r = lower_bound(comp.begin(), comp.end(), min(x + Q, N) + 1) - comp.begin();
            eves.push_back({1, max(y - Q, 1), l, r});
            eves.push_back({-1, min(y + Q, M) + 1, l, r});
        }
        sort(eves.begin(), eves.end(), [](Event a, Event b){
            return a.x < b.x;
        });

        vector<int> cnt(comp.size());
        ll lst = 1;
        ll ans = 0;
        for (auto [op, x, l, r] : eves){

            ll on = 0;
            for (int i = 0; i < cnt.size() - 1; ++i){
                if (cnt[i]) on += comp[i + 1] - comp[i];
            }
            ans += 1LL * on * (x - lst);
            lst = x;

            for (int i = l; i < r; ++i){
                cnt[i] += op;
            }
            
        }
        return ans;
    };

    int Q; cin >> Q;
    if (Q == 0){
        cout << K << '\n';
        return 0;
    }
    else{
        cout << countQ(Q) - countQ(Q - 1) << '\n';
    }
}
