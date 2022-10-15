#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

int a[MN], ans[MN], T;
vector<int> fact, need;
struct Eve{ int x, c, id; } stk[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        if (a[i] == 0) need.push_back(i);
        else if (a[i] > 1){
            ans[i] = a[i];
            a[i] = 0;
            fact.push_back(i); need.push_back(i);
        }
    }
    if (need.size() == 0){
        for (int i = 0; i < N; ++i){
            cout << a[i] << (i == N ? '\n' : ' ');
        }
        return 0;
    }
    if (fact.size()){
        int p = 0;
        for (int x : fact){
            while (p < need.size() && need[p] <= x) stk[++T] = {need[p++], 0, 0};
            stk[++T] = {x, 1, x};
        }
        while (p < need.size()) stk[++T] = {need[p++], 0, 0};
        for (int x : fact){
            stk[++T] = {x + N, 1, x};
        }
        need.clear();
        for (int i = 1; i <= T; ++i){
            auto [x, c, id] = stk[i];
            if (c == 0){
                need.push_back(x);
            }
            if (c == 1){
                while (!need.empty()){
                    if (ans[id] == 0) break;
                    if (x - need.back() > K) break;
                    ans[id]--;
                    a[need.back()] = 1;
                    need.pop_back();
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) ans[(i + K) % N] += a[i];
    for (int i = 0; i < N; ++i) cout << ans[i] << (i + 1 == N ? '\n' : ' ');
}
