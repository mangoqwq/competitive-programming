#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
struct Fenwick{
    vector<T> v;
    Fenwick(int N){ v.resize(N); }
    void ins(int i, T val){
        for (; i < v.size(); i += i & -i) v[i] += val;
    }
    T qry(int i){
        T ret(0);
        for (; i; i -= i & -i) ret += v[i];
        return ret;
    }
    T qry(int l, int r){
        return qry(r) - qry(l - 1);
    }
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    struct Query{ int t, op, l, r, x, i, j, id; };
    vector<Query> qs(Q);
    vector<int> lst(N, -1);
    int T = 0;
    for (int t = 0; t < Q; ++t){
        qs[t].t = t;
        cin >> qs[t].op;
        if (qs[t].op == 1){
            cin >> qs[t].l >> qs[t].r >> qs[t].x;
            qs[t].l--; qs[t].r--;
        }
        if (qs[t].op == 2){
            cin >> qs[t].i >> qs[t].x;
            qs[t].i--;
            lst[qs[t].i] = t;
        }
        if (qs[t].op == 3){
            cin >> qs[t].i >> qs[t].j;
            qs[t].i--, qs[t].j--;
            qs[t].id = T;
            qs[t].x = 1;
            if (lst[qs[t].i] != -1){
                Query tmp;
                tmp.t = lst[qs[t].i] - 1;
                tmp.op = 3;
                tmp.x = -1;
                tmp.i = qs[t].i;
                tmp.j = qs[t].j;
                tmp.id = T;
                qs.push_back(tmp);
            }
            T++;
        }
    }
    sort(qs.begin(), qs.end(), [](Query a, Query b){
        return tie(a.t, a.op) < tie(b.t, b.op);
    });

    Fenwick<ll> bit(M + 1);
    vector<ll> ans(T);
    vector<int> row(N);
    for (auto [t, op, l, r, x, i, j, id] : qs){
        if (op == 1){
            bit.ins(l + 1, x);
            bit.ins(r + 1 + 1, -x);
        }
        if (op == 2){
            row[i] = x;
        }
        if (op == 3){
            if (x == -1){
                ans[id] -= bit.qry(j + 1);
            }
            else{
                ans[id] += bit.qry(j + 1);
                ans[id] += row[i];
            }
        }
    }
    for (ll x : ans){
        cout << x << '\n';
    }
}
