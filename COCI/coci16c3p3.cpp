#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 20;

int N, K;
int c[MN][MN];
int cur[(1 << MN)], nxt[(1 << MN)];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> c[i][j];
        }
    }
    ms(nxt, 0x3f); nxt[0] = 0;
    for (int k = 0; k <= K; ++k){
        swap(nxt, cur); ms(nxt, 0x3f);
        for (int msk = 0; msk < (1 << N); ++msk){
            for (int i = 0; i < N; ++i){
                if (1 & (msk >> i)) continue;
                int cost = inf;
                for (int j = 0; j < N; ++j){
                    if (1 & (msk >> j)) cost = min(cost, c[i][j]);
                }
                cur[msk + (1 << i)] = min(cur[msk + (1 << i)], cur[msk] + cost);
                nxt[msk + (1 << i)] = min(nxt[msk + (1 << i)], cur[msk]);
            }
        }
    }
    cout << cur[(1 << N) - 1];
}
