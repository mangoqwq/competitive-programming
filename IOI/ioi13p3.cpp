#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MR = 5000, MC = 200, BSZ = 10;

int R, C, H[MR][MC], V[MR][MC];
int N, blk[MR], blkL[MR], blkR[MR];
struct Item{
    int d[MC][MC];
    Item(){ ms(d, 0); }
    int operator()(int a, int b) const{ return d[a][b]; }
    void set(int r){
        Item rhs;
        for (int i = 0; i < C; ++i){
            d[i][i] = V[r][i];
            rhs.d[i][i] = 0;
            for (int j = i - 1; j >= 0; --j){
                d[i][j] = d[i][j + 1] - V[r][j + 1] + H[r][j] + V[r][j];
                rhs.d[i][j] = rhs.d[i][j + 1] + H[r + 1][j];
            }
            for (int j = i + 1; j < C; ++j){
                d[i][j] = d[i][j - 1] - V[r][j - 1] + H[r][j - 1] + V[r][j];
                rhs.d[i][j] = rhs.d[i][j - 1] + H[r + 1][j - 1];
            }
        }
        Item tmp = merge(*this, rhs);
        memcpy(d, tmp.d, MC * MC * sizeof(int));
    }
    friend Item merge(const Item &lhs, const Item &rhs){
        Item ret;
        for (int i = 0; i < C; ++i){
            for (int k = 0; k < C; ++k){
                if (lhs(i, k) + rhs(k, i) < lhs(i, ret.d[i][i]) + rhs(ret.d[i][i], i)) ret.d[i][i] = k;
            }
        }
        for (int sz = 2; sz <= C; ++sz){
            for (int l = 0, r = sz - 1; r < C; ++l, ++r){
                for (int k = ret.d[l][r - 1]; k <= ret.d[l + 1][r]; ++k){
                    if (lhs(l, k) + rhs(k, r) < lhs(l, ret.d[l][r]) + rhs(ret.d[l][r], r)) ret.d[l][r] = k;
                }
            }
            for (int l = sz - 1, r = 0; l < C; ++l, ++r){
                for (int k = ret.d[l - 1][r]; k <= ret.d[l][r + 1]; ++k){
                    if (lhs(l, k) + rhs(k, r) < lhs(l, ret.d[l][r]) + rhs(ret.d[l][r], r)) ret.d[l][r] = k;
                }
            }
        }
        for (int i = 0; i < C; ++i){
            for (int j = 0; j < C; ++j){
                ret.d[i][j] = lhs(i, ret.d[i][j]) + rhs(ret.d[i][j], j);
            }
        }
        return ret;
    }
} arr[MR / BSZ + 5], cur, ans;
struct Seg{
    Item st[2 * (MR / BSZ + 5) + 1];
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
    void build(int v = 1, int l = 0, int r = N - 1){
        if (l == r) memcpy(st[v].d, arr[l].d, MC * MC * sizeof(int));
        else{
            build(lc, l, mid), build(rc, mid + 1, r);
            st[v] = merge(st[lc], st[rc]);
        }
    }
    void upd(int i, int v = 1, int l = 0, int r = N - 1){
        if (l == r) memcpy(st[v].d, arr[l].d, MC * MC * sizeof(int));
        else{
            if (i <= mid) upd(i, lc, l, mid);
            else upd(i, rc, mid + 1, r);
            st[v] = merge(st[lc], st[rc]);
        }
    }
    int getans(int v1, int v2){ return st[1](v1, v2); }
} st;

void fix_block(int b){
    arr[b].set(blkL[b]);
    for (int i = blkL[b] + 1; i <= blkR[b]; ++i){
        cur.set(i);
        arr[b] = merge(arr[b], cur);
    }
}

void init(int r, int c, int h[5000][200], int v[5000][200]){
    R = r, C = c;
    memcpy(H, h, MR * MC * sizeof(int));
    memcpy(V, v, MR * MC * sizeof(int));

    ms(blkL, 0x3f); 
    for (int i = 0; i < R - 1; ++i){
        int b = i / BSZ;
        blk[i] = b;
        blkL[b] = min(blkL[b], i);
        blkR[b] = max(blkR[b], i);
    }
    N = (R - 2) / BSZ + 1;

    for (int i = 0; i < N; ++i) fix_block(i);
    st.build();
}

void changeH(int p, int q, int w){
    H[p][q] = w;
    if (p != 0 && blk[p] != blk[p - 1]){
        fix_block(blk[p - 1]);
        st.upd(blk[p - 1]);
    }
    fix_block(blk[p]);
    st.upd(blk[p]);
}

void changeV(int p, int q, int w){
    V[p][q] = w;
    fix_block(blk[p]);
    st.upd(blk[p]);
}

int escape(int v1, int v2){
    return st.getans(v1, v2);
}

int h[5000][200];
int v[5000][200];
int main(){
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
#endif
    int r, c; cin >> r >> c;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c - 1; ++j){
            cin >> h[i][j];
        }
    }
    
    for (int i = 0; i < r - 1; ++i){
        for (int j = 0; j < c; ++j){
            cin >> v[i][j];
        }
    }
    init(r, c, h, v);

    int q; cin >> q;
    while (q--){
        int op; cin >> op;
        if (op == 1){
            int p, q, w; cin >> p >> q >> w;
            changeH(p, q, w);
        }
        if (op == 2){
            int p, q, w; cin >> p >> q >> w;
            changeV(p, q, w);
        }
        if (op == 3){
            int v1, v2; cin >> v1 >> v2;
            cout << escape(v1, v2) << '\n';
        }
    }
}
