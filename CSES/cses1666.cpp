#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int p[MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    p[b] = a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    iota(p + 1, p + 1 + N, 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        Union(a, b);
    }
    vector<int> rts;
    for (int i = 1; i <= N; ++i){
        if (Find(i) == i) rts.push_back(i);
    }
    cout << rts.size() - 1 << '\n';
    for (int i = 1; i < rts.size(); ++i){
        cout << rts[i] << " " << rts[i - 1] << '\n';
    }
}
