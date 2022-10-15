#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 + 1;

queue<int> q[MN];
vector<int> add[MN];
int last[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin >> N >> T;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        q[i].push(x);
    }
    while (T--){
        for (int i = 1; i <= N; ++i){
            if (q[i].empty()) continue;
            last[i] = q[i].front(); q[i].pop();
            add[last[i]].push_back(i);
        }
        for (int i = 1; i <= N; ++i){
            for (int x : add[i]) q[i].push(x);
            add[i].clear();
        }
    }
    for (int i = 1; i <= N; ++i) cout << last[i] << (i == N ? '\n' : ' ');
}
