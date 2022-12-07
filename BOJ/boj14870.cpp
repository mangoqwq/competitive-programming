#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwick{
    vector<ll> a;
    Fenwick(int N) : a(N+1) {}
    void ins(int i, int v){
        for (++i; i < a.size(); i += i & -i) a[i] += v;
    }
    ll qry(int i){
        ll ret = 0;
        for (++i; i > 0; i -= i & -i) ret += a[i];
        return ret;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<Fenwick> a(N+1, Fenwick(N+1));
    vector<vector<ll>> g(N+1, vector<ll>(N+1));
    ll tot = 0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j){
        cin >> g[i][j];
        ll cur = max(a[i].qry(j-1), a[i-1].qry(j)) + g[i][j];
        a[i].ins(j, cur);
        a[i].ins(j+1, -cur);
        tot += a[i].qry(j);
    }
    cout << tot << '\n';
    for (int q = 0; q < N; ++q){
        char c; cin >> c;
        int del = (c == 'U' ? 1 : -1);
        int x, y; cin >> x >> y;
        g[x][y] += del;
        vector<int> pl(N+1), pr(N+1);
        pl[x-1] = y, pr[x-1] = y+1;
        for (int i = x; i <= N; ++i){
            pl[i] = pl[i-1], pr[i] = pr[i-1];
            while (pl[i] < pr[i] &&
                    a[i].qry(pl[i]) == max(a[i].qry(pl[i]-1), a[i-1].qry(pl[i]) + del) + g[i][pl[i]]){
                pl[i]++;
            }
            while (pl[i] < pr[i] && pr[i] <= N && 
                    a[i].qry(pr[i]) != max(a[i].qry(pr[i]-1) + del, a[i-1].qry(pr[i])) + g[i][pr[i]]){
                pr[i]++;
            }
        }
        for (int i = x; i <= N; ++i){
            tot += (pr[i] - pl[i]) * del;
            a[i].ins(pl[i], del);
            a[i].ins(pr[i], -del);
        }
        cout << tot << '\n';
    }
}
