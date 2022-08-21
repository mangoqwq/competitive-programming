#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mid ((l+r) >> 1)
#define lc (v+1)
#define rc (v + 2*(mid-l+1))
const int mod = 1e9 + 2022;

int N, M;
vector<int> fact, arr;
vector<ll> st, tot, lz;

void build(int v=0, int l=0, int r=N+M-1){
    if (l==r) tot[v] = fact[l], st[v] = arr[l]*fact[l];
    else{
        build(lc, l, mid), build(rc, mid+1, r);
        tot[v] = tot[lc] + tot[rc];
        st[v] = st[lc] + st[rc];
    }
}
void push(int v, int l, int r){
    if (!lz[v]) return;
    st[v] = tot[v] - st[v];
    if (l != r){
        lz[lc] ^= 1;
        lz[rc] ^= 1;
    }
    lz[v] = 0;
}
void flip(int ql, int qr, int v=0, int l=0, int r=N+M-1){
    push(v, l, r);
    if (ql > r || qr < l) return;
    if (l >= ql && r <= qr) lz[v]^=1, push(v, l, r);
    else{
        flip(ql, qr, lc, l, mid);
        flip(ql, qr, rc, mid+1, r);
        st[v] = st[lc] + st[rc];
    }
}

void init(int _N, int _M, vector<int> P, vector<int> A){
    N = _N, M = _M;
    vector<vector<int>> c(N, {-1});
    vector<int> idx(N+M);
    for (int i = 1; i < N+M; ++i){
        idx[i] = c[P[i]].size();
        c[P[i]].push_back(i);
    }
    vector<int> val(N+M, 1);
    for (int i = N-1; i >= 0; --i){
        val[i] = c[i].size()-1;
        for (int to : c[i]){
            if (to == -1) continue;
            val[i] = 1LL * val[i] * val[to] % mod;
        }
    }
    vector<vector<int>> pre(N);
    vector<vector<int>> suf(N);
    for (int v = 0; v < N; ++v){
        int ch = c[v].size()-1;
        pre[v].resize(ch+1);
        pre[v][0] = 1;
        for (int i = 1; i <= ch; ++i){
            pre[v][i] = 1LL * pre[v][i-1] * val[c[v][i]] % mod;
        }
        suf[v].resize(ch+2);
        suf[v][ch+1] = 1;
        for (int i = ch; i >= 1; --i){
            suf[v][i] = 1LL * suf[v][i+1] * val[c[v][i]] % mod;
        }
    }
    fact = vector<int>(N+M);
    fact[0] = 1;
    for (int i = 1; i < N+M; ++i){
        fact[i] = 1LL * fact[P[i]] * pre[P[i]][idx[i]-1] % mod * suf[P[i]][idx[i]+1] % mod;
    }
    arr.resize(N+M);
    for (int i = 0; i < N+M; ++i){
        if (i >= N) arr[i] = A[i-N];
    }
    st.resize(2*(N+M));
    lz.resize(2*(N+M));
    tot.resize(2*(N+M));
    build();
}

int count_ways(int L, int R){
    flip(L, R);
    return st[0] % mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    init(3, 4, {-1, 0, 1, 2, 1, 1, 0}, {1, 0, 1, 0});
    cout << count_ways(3, 4) << '\n';
    cout << count_ways(4, 5) << '\n';
    cout << count_ways(3, 6) << '\n';
}
