#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
struct Fenwick{
    int a[MN];
    void ins(int i){ for (; i < MN; i += i & -i) a[i]++; }
    int qry(int i){ int ret = 0; for (; i; i -= i & -i) ret += a[i]; return ret; }
    int qry(int l, int r){ return qry(r) - qry(l - 1); }
} bit;

int N, a[MN];
ll ans;
void step(){
    int last = 1;
    for (int i = 1; i <= N; ++i){
        if (i == N || a[i] < a[i + 1]){
            reverse(a + last, a + 1 + i);
            ans++;
            last = i + 1;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    step();
    for (int i = 1; i <= N; ++i){
        ans += bit.qry(a[i] + 1, N);
        bit.ins(a[i]);
    }
    cout << ans << '\n';
}
