#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwick{
    vector<int> a, t;
    int T;
    Fenwick(int N) : a(N), t(N), T(0){}
    void ins(int i){
        for (; i < a.size(); i += i & -i){
            if (t[i] != T) a[i] = 0;
            t[i] = T;
            a[i]++;
        }
    }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i){
            if (t[i] != T) a[i] = 0;
            ret += a[i];
        }
        return ret;
    }
    void reset(){ T++; }
};

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N+1), b(N+1), c(N+1);
    for (int i = 1; i <= N; ++i){
        int id; cin >> id;
        a[id] = i;
    }
    for (int i = 1; i <= N; ++i){
        int id; cin >> id;
        b[id] = i;
    }
    for (int i = 1; i <= N; ++i){
        int id; cin >> id;
        c[id] = i;
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return a[i] < a[j];
    });

    vector<int> better(N+1);
    Fenwick bit(N+1);
    auto go = [&](auto self, vector<int> v, int l, int r) -> void{
        if (v.empty() || l >= r) return;
        vector<int> lv, rv;
        int m = (l+r) >> 1;
        for (int i : v){
            if (b[i] <= m){
                lv.push_back(i);
                bit.ins(c[i]);
            }
            else{
                rv.push_back(i);
                better[i] += bit.qry(c[i]);
            }
        }
        bit.reset();
        self(self, lv, l, m);
        self(self, rv, m+1, r);
    };
    go(go, ord, 1, N);

    int ans = 0;
    for (int i = 1; i <= N; ++i){
        if (better[i] == 0) ans++;
    }
    cout << ans << '\n';
}
