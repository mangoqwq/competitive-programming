#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, L = 16;

int p[L + 1][MN];
int Find(int i, int x){ return p[i][x] == x ? x : p[i][x] = Find(i, p[i][x]); }
void Union(int i, int a, int b){
    a = Find(i, a); b = Find(i, b);
    if (a == b) return;
    p[i][b] = a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 0; i <= L; ++i) iota(p[i], p[i] + 1 + N, 0);
    for (int i = 1; i <= M; ++i){
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int sz = L; sz >= 0; --sz){
            if (a + (1 << sz) - 1 <= b){
                Union(sz, a, c);
                a += (1 << sz);
                c += (1 << sz);
            }
        }
    }
    for (int sz = L; sz >= 1; --sz){
        for (int i = 1; i + (1 << sz) - 1 <= N; ++i){
            int j = Find(sz, i);
            Union(sz - 1, i, j);
            Union(sz - 1, i + (1 << (sz - 1)), j + (1 << (sz - 1)));
        }
    }
    int cnt = -1;
    for (int i = 1; i <= N; ++i){
        if (Find(0, i) == i) cnt++;
    }
    ll ans = 9;
    while (cnt--) ans = (ans * 10) % mod;
    cout << ans << '\n';
}
