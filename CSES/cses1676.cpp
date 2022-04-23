#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
int p[MN], sz[MN], mxsz = 1;
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) return 0;
    if (sz[b] > sz[a]) swap(a, b);
    sz[b] += sz[a];
    mxsz = max(mxsz, sz[b]);
    return p[b] = a, 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    iota(p + 1, p + 1 + N, 1);
    fill(sz + 1, sz + 1 + N, 1);
    int cc = N;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        if (Union(a, b)){
            cc--;
        }
        cout << cc << " " << mxsz << '\n';
    }
}
