#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1500;

int N, p[MN], sz[MN], cnt[MN][MN];
int Find(int v){ return p[v] == v ? v : p[v] = Find(p[v]);}
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (sz[b] > sz[a]) swap(a, b);
    p[b] = a; sz[a] += sz[b];
    for (int i = 0; i < N; ++i) cnt[a][i] += cnt[b][i];
    for (int i = 0; i < N; ++i){
        if (Find(i) == i){
            cnt[i][a] = cnt[i][a] + cnt[i][b];
        }
    }
}

void initialize(int _N){
    N = _N;
    iota(p, p + N, 0);
    fill(sz, sz + N, 1);
    for (int i = 0; i < N; ++i){
        fill(cnt[i], cnt[i] + N, 1);
    }
}

int hasEdge(int a, int b){
    a = Find(a); b = Find(b);
    if (a != b && (cnt[a][b] == 1 || cnt[b][a] == 1)){
        Union(a, b);
        return 1;
    }
    cnt[a][b]--, cnt[b][a]--;
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    initialize(4);
    cout << hasEdge(0, 3) << '\n';
    cout << hasEdge(1, 0) << '\n';
    cout << hasEdge(0, 2) << '\n';
    cout << hasEdge(3, 1) << '\n';
    cout << hasEdge(1, 2) << '\n';
    cout << hasEdge(2, 3) << '\n';
}
