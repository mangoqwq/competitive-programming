#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

struct Fenwick{
    vector<int> a, t;
    int T;
    Fenwick(int N) : a(N+1), t(N+1), T(0) {}
    void ins(int i, int v){
        for (++i; i < a.size(); i += i & -i){
            if (t[i] != T) a[i] = 0;
            t[i] = T;
            a[i] = max(a[i], v);
        }
    }
    int qry(int i){
        int ret = 0;
        for (++i; i; i -= i & -i){
            if (t[i] != T) a[i] = 0;
            ret = max(ret, a[i]);
        }
        return ret;
    }
    void reset(){ T++; }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int M, N; cin >> M >> N;
    vector<vector<int>> a(3, vector<int>(N));
    vector<int> comp;
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            cin >> a[i][j];
            comp.push_back(a[i][j]);
        }
    }
    if (M == 2) a[2] = a[0];
    sort(all(comp));
    comp.resize(unique(all(comp)) - comp.begin());
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < N; ++j){
            a[i][j] = lower_bound(all(comp), a[i][j]) - comp.begin();
        }
    }

    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){ return a[0][i] < a[0][j]; });

    Fenwick bit(3*N + 1);
    vector<int> ans(N, 1);
    auto go = [&](auto self, vector<int> v, int l, int r){
        if (l+1 == r) return;
        int m = (l+r) >> 1;
        vector<int> vl, vr;
        for (int i : v){
            if (a[1][i] < m) vl.push_back(i);
            else vr.push_back(i);
        }
        self(self, vl, l, m);
        bit.reset();
        for (int i : v){
            if (a[1][i] < m){
                bit.ins(a[2][i], ans[i]);
            }
            else{
                ans[i] = max(ans[i], bit.qry(a[2][i]) + 1);
            }
        }
        self(self, vr, m, r);
    };
    go(go, ord, 0, 3*N);
    cout << *max_element(ans.begin(), ans.end()) << '\n';
}
