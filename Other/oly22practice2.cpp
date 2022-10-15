#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int N, A, B;
int l[2][MN], r[2][MN], ans[2][MN];
struct Event{
    int l, r, id;
    bool operator<(const Event &a) const{ return l < a.l; }
}; set<Event> eve[2];
void solve(){
    for (int i = 1; i <= N; ++i){
        int t = 0;
        while (true){
            Event key = {t, t, -1};
            auto it = eve[0].lower_bound(key);
            if (it == eve[0].end()) break;
            ans[0][i]++;
            t = it->r;
            eve[0].erase(it);
        }
    }
    for (int i = 1; i <= N; ++i) ans[0][i] += ans[0][i - 1];
    for (int i = 1; i <= N; ++i){
        int t = 0;
        while (true){
            Event key = {t, t, -1};
            auto it = eve[1].lower_bound(key);
            if (it == eve[1].end()) break;
            ans[1][i]++;
            t = it->r;
            eve[1].erase(it);
        }
    }
    for (int i = 1; i <= N; ++i) ans[1][i] += ans[1][i - 1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    for (int i = 1; i <= A; ++i) cin >> l[0][i] >> r[0][i];
    for (int i = 1; i <= B; ++i) cin >> l[1][i] >> r[1][i];
    for (int i = 1; i <= A; ++i){
        eve[0].insert({l[0][i], r[0][i], i});
    }
    for (int i = 1; i <= B; ++i){
        eve[1].insert({l[1][i], r[1][i], i});
    }
    solve();
    int ret = 0;
    for (int i = 0; i <= N; ++i){
        ret = max(ret, ans[0][i] + ans[1][N - i]);
    }
    cout << ret << '\n';
}
