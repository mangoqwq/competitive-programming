#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
struct Fenwick{
    vector<T> v;
    Fenwick(int N){ v.resize(N+1); }
    void ins(int i, T val){
        for (++i; i < v.size(); i += i & -i) v[i] += val;
    }
    T qry(int i){
        T ret(0);
        for (++i; i; i -= i & -i) ret += v[i];
        return ret;
    }
    T qry(int l, int r){
        return qry(r) - qry(l - 1);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        Fenwick<int> bit(N);
        ll ans = 0;
        for (int i = 0; i < N; ++i){
            Fenwick<int> in(N);
            ll sub = 0;
            for (int j = i-1; j >= 0; --j){
                sub += in.qry(a[j], N-1);
                in.ins(a[j]-1, 1);
                if (a[i] < a[j]){
                    ans += bit.qry(j+1, i-1) - sub;
                }
            }
            for (int j = i-1; j >= 0; --j){
                if (a[i] > a[j]){
                    bit.ins(i, 1);
                }
            }
        }
        cout << ans << '\n';
    }
}
