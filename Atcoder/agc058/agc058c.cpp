#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        deque<int> q(N);
        for (int i = 0; i < N; ++i){
            cin >> q[i];
        }
        auto is = [&](const vector<int> &v) -> bool{
            if (v.size() > q.size()) return 0;
            for (int i = 0; i < v.size(); ++i){
                if (q[i] != v[i]) return 0;
            }
            return 1;
        };
        for (int i = 0; i < N; ++i){
            int sz1 = q.size();
            while (is({1, 2}) || is({2, 1})){
                q.pop_front(); q.pop_front();
                q.push_front(2);
            }
            while (is({4, 3}) || is({3, 4})){
                q.pop_front(); q.pop_front();
                q.push_front(3);
            }
            while (q.size() >= 2 && q[0] == q[1]){
                q.pop_front();
            }
            if (sz1 != q.size()){
                i--;
            }
            else{
                q.push_back(q.front());
                q.pop_front();
            }
        }
        int cnt0 = 0, cnt1 = 0;
        for (int x : q){
            if (x == 2) cnt0++;
            if (x == 4) cnt0--;
            if (x == 3) cnt1++;
            if (x == 1) cnt1--;
        }
        cout << (cnt0 > 0 && cnt1 > 0 ? "Yes" : "No") << '\n';
    }
}
