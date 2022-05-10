#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Segtree{

#define mid ((l + r) >> 1)

    struct Node{
        int lc, rc, val;
    };

    int N;
    vector<Node> st;
    int T;

    Segtree() = default;
    Segtree(int N) : N(N) {
        st.resize(25 * N);
        T = 0;

        build(0, 1, N);
    }

    int build(int v, int l, int r){
        if (l == r) return v;
        st[v].lc = build(++T, l, mid);
        st[v].rc = build(++T, mid + 1, r);
        return v;
    }

    int insert(int v, int l, int r, int idx){
        int nv = ++T;
        if (l == r){
            st[nv] = {0, 0, st[v].val + 1};
        }
        else if (idx <= mid){
            st[nv].lc = insert(st[v].lc, l, mid, idx);
            st[nv].rc = st[v].rc;
            st[nv].val = st[st[nv].lc].val + st[st[nv].rc].val;
        }
        else{
            st[nv].lc = st[v].lc;
            st[nv].rc = insert(st[v].rc, mid + 1, r, idx);
            st[nv].val = st[st[nv].lc].val + st[st[nv].rc].val;
        }
        return nv;
    }
    int insert(int v, int idx){ return insert(v, 1, N, idx); }

    int query(int vl, int vr, int l, int r, int ql, int qr){
        if (l > qr || r < ql || ql > qr) return 0;
        if (l >= ql && r <= qr) return st[vr].val - st[vl].val;
        return query(st[vl].lc, st[vr].lc, l, mid, ql, qr) +
               query(st[vl].rc, st[vr].rc, mid + 1, r, ql, qr);
    }
    int query(int vl, int vr, int ql, int qr){ return query(vl, vr, 1, N, ql, qr); }

    int walk(int vl, int vr, int l, int r, int need){
        if (l == r) return l;
        int lef = st[st[vr].lc].val - st[st[vl].lc].val;
        if (lef < need) return walk(st[vl].rc, st[vr].rc, mid + 1, r, need - lef);
        else return walk(st[vl].lc, st[vr].lc, l, mid, need);
    }
    int walk(int vl, int vr, int need){ return walk(vl, vr, 1, N, need); }

#undef mid
};

using pii = pair<int, int>;

Segtree st;
vector<int> rts;
int N;
vector<pii> xs, ys;

void init(int N, int A[], int B[]){
    ::N = N;

    for (int i = 0; i < N; ++i){
        xs.push_back({A[i], i});
        ys.push_back({B[i], i});
    }

    // give each point unique x and unique y
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    vector<int> y(N + 1);
    for (int i = 0; i < N; ++i){
        int x = lower_bound(xs.begin(), xs.end(), pii{A[i], i}) - xs.begin() + 1;
        y[x] = lower_bound(ys.begin(), ys.end(), pii{B[i], i}) - ys.begin() + 1;
    }

    st = Segtree(N + 1);
    rts.resize(N + 1);
    int v = 0;

    for (int x = 1; x <= N; ++x){
        v = st.insert(v, y[x]);
        rts[x] = v;
    }
}

// number of points in [x1, x2] x [y1, y2]
int count(int x1, int x2, int y1, int y2){
    x2 = min(x2, N);
    y2 = min(y2, N);
    return st.query(rts[x1 - 1], rts[x2], y1, y2);
}

int can(int M, int K[]){
    sort(K, K + M);
    struct Point{ int x, y; };

    vector<Point> stk = {};
    stk.push_back({0, N + 1});

    for (int i = 0; i < M; ++i){
        int qx = upper_bound(xs.begin(), xs.end(), pii{K[i], 1e9}) - xs.begin() + 1 - 1;
        int qy = lower_bound(ys.begin(), ys.end(), pii{K[i], -1}) - ys.begin() + 1;

        while (stk.back().y < qy){
            stk.pop_back();
        }

        int need = K[i];
        while (need){
            if (stk.empty()){
                return 0;
            }
            auto [lx, ly] = stk.back();

            /*
            
            **........^
            **........^
            *****%%%%%% ly
            *****%%%%%% qy
            ***********
            ***********
                lx    qx
            */
            int rect = count(lx + 1, qx, qy, ly);
            if (rect <= need){
                need -= rect;
                qy = ly + 1;
                stk.pop_back();
            }
            else{
                // bsearch for new y

                qy = st.walk(rts[lx], rts[qx], need + count(lx + 1, qx, 1, qy - 1));
                qy += 1;
                need = 0;
            }
        }
        stk.push_back({qx, qy - 1});
    }
    return 1;
}
