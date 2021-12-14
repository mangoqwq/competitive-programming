#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = (1 << 20) + 1;

int a[MN], pos[MN], nxt[MN];
set<int> seen;
struct Fenwick{
    int a[MN];
    void ins(int i, int v){ for (++i; i < MN; i += i & -i) a[i] += v; }
    int qry(int i){
        i++;
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
    int qry(int l, int r){
        return qry(r) - qry(l - 1);
    }
} bit[4];

void ins(int i, int v){
    bit[(i + 3) % 4].ins(i, v);
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int M; cin >> M;
    if (M == 1){
        cout << 2 << '\n';
        return 0;
    }
    int N = (1 << M);
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= N; ++i){
        nxt[i] = pos[a[i] ^ (N - 1)];
    }
    ll ans = (1LL * N * (N + 1)) >> 1;
    seen.insert(0);
    stack<int> s;
    for (int i = 1; i <= N; ++i){
        if (nxt[i] > i){
            ins(i, 1); s.push(i);
            seen.insert(i);
        } 
        else{
            while (!s.empty() && s.top() > nxt[i]){
                ins(s.top(), -1);
                s.pop();
            }
            seen.erase(nxt[i]);
            ans -= bit[i % 4].qry((*--seen.end()) + 1, N);
        }
    }
    cout << ans << '\n';
}
