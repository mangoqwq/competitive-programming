#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 10;

struct bit{
    int arr[MN], a[MN];
    void fill(int i, int v){ for (; i < MN; i += i & -i) a[i] ^= v; }
    void ins(int i, int v){
        fill(i, arr[i]);
        arr[i] = v;
        fill(i, v);
    }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i) ret ^= a[i];
        return ret;
    }
    int qry(int l, int r){
        return qry(r) ^ qry(l - 1);
    }
} odd, even;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        int a; cin >> a;
        if (i % 2 == 1) odd.ins((i + 1) / 2, a);
        if (i % 2 == 0) even.ins(i / 2, a);
    }
    for (int i = 1; i <= q; ++i){
        int op; cin >> op;
        if (op == 1){
            int i, a; cin >> i >> a;
            if (i % 2 == 1) odd.ins((i + 1) / 2, a);
            if (i % 2 == 0) even.ins(i / 2, a);
        }
        if (op == 2){
            int l, r; cin >> l >> r;
            int sz = r - l + 1;
            if (sz % 2 == 0) cout << 0 << '\n';
            else{
                if (r % 2 == 1){
                    cout << odd.qry((l + 1) / 2, (r + 1) / 2) << '\n';
                }
                else{
                    cout << even.qry(l / 2, r / 2) << '\n';
                }
            }
        }
    }
}
