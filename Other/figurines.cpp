#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MN = 1e6 + 1;
const int inf = 0x3f3f3f3f;
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))

int N, Q;
struct Node{
    int mnb, mn2b;
    int mxa, mxb;
    bool lza, lzb;
    int seta, chmaxb;
    int ans1, ans2; // ans2: best with b = mnb
} st[2 * MN];
int A[MN], B[MN];

void push(int v, int l, int r){
    if (st[v].lza){
        st[v].mxa = st[v].seta;
        st[v].ans1 = st[v].mxa + st[v].mxb;
        st[v].ans2 = st[v].mxa + st[v].mnb;
        if (l != r){
            st[lc].seta = st[v].seta;
            st[lc].lza = 1;
            st[rc].seta = st[v].seta;
            st[rc].lza = 1;
        }
        st[v].lza = 0;
        st[v].seta = -inf;
    }
    if (st[v].lzb){
        if (st[v].chmaxb > st[v].mnb){
            st[v].ans2 += st[v].chmaxb - st[v].mnb;
            st[v].ans1 = max(st[v].ans1, st[v].ans2);
            st[v].mnb = st[v].chmaxb;
            if (l != r){
                st[lc].chmaxb = max(st[lc].chmaxb, st[v].chmaxb);
                st[lc].lzb = 1;
                st[rc].chmaxb = max(st[rc].chmaxb, st[v].chmaxb);
                st[rc].lzb = 1;
            }
            if (l == r){
                st[v].mxb = st[v].chmaxb;
            }
            else{
                if (st[v].chmaxb >= st[v].mxb) st[v].mxb = st[v].chmaxb;
            }
        }
        st[v].lzb = 0;
        st[v].chmaxb = -inf;
    }
}

Node merge(Node a, Node b){
    Node ret;
    ret.mxa = max(a.mxa, b.mxa);
    ret.mxb = max(a.mxb, b.mxb);
    ret.ans1 = max(a.ans1, b.ans1);
    ret.lza = ret.lzb = ret.seta = 0;
    ret.chmaxb = -inf;

    if (a.mnb == b.mnb){
        ret.mnb = a.mnb;
        ret.mn2b = min(a.mn2b, b.mn2b);
        ret.ans2 = max(a.ans2, b.ans2);
    }
    else{
        if (a.mnb > b.mnb) swap(a, b);
        ret.mnb = a.mnb;
        ret.mn2b = min(a.mn2b, b.mnb);
        ret.ans2 = a.ans2;
    }
    return ret;
}

void build(int v, int l, int r){
    if (l == r){
        st[v] = {B[l], inf,
                 A[l], B[l], 
                 0, 0, 
                 0, -inf, 
                 A[l] + B[l], A[l] + B[l]};
    } else{
        build(lc, l, mid);
        build(rc, mid + 1, r);
        st[v] = merge(st[lc], st[rc]);
    }
}

int query(int ql, int qr, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql) return -2 * inf;
    if (l >= ql && r <= qr) return st[v].ans1;
    return max(query(ql, qr, lc, l, mid), query(ql, qr, rc, mid + 1, r));
}

void update_seta(int ql, int qr, int val, int v = 1, int l = 1, int r = N){
    push(v, l, r);
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr){
        st[v].seta = val;
        st[v].lza = 1;
        push(v, l, r);
        return;
    }

    update_seta(ql, qr, val, lc, l, mid);
    update_seta(ql, qr, val, rc, mid + 1, r);
    st[v] = merge(st[lc], st[rc]);
}

void update_chmaxb(int ql, int qr, int val, int v = 1, int l = 1, int r = N){
    assert(l <= r);
    push(v, l, r);
    if (l > qr || r < ql || val <= st[v].mnb) return;
    if (l >= ql && r <= qr && val < st[v].mn2b){
        st[v].chmaxb = max(st[v].chmaxb, val);
        st[v].lzb = 1;
        push(v, l, r);
        return;
    }

    update_chmaxb(ql, qr, val, lc, l, mid);
    update_chmaxb(ql, qr, val, rc, mid + 1, r);
    st[v] = merge(st[lc], st[rc]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i){
        cin >> B[i];
    }
    build(1, 1, N);
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int l, r, k; cin >> l >> r >> k;
            update_seta(l, r, k);
        }
        if (op == 2){
            int l, r, k; cin >> l >> r >> k;
            update_chmaxb(l, r, k);
        }
        if (op == 3){
            int l, r; cin >> l >> r;
            cout << query(l, r) << '\n';
        }
    }
}
