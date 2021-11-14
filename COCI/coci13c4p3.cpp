#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int N, M;
int p[2 * MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) return;
    p[b] = a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    int ans = M;
    iota(p + 1, p + 1 + 2 * N, 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        Union(a, b + N);
        Union(a + N, b);
        if (Find(a) == Find(a + N)){
            cout << i << '\n';
            return 0;
        }
    }
}
