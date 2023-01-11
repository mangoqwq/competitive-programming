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
        vector<int> b(N);
        for (int i = 0; i < N; ++i){
            cin >> b[i];
        }
        
        Fenwick<int> bit(2*N+1);
        for (int i = 0; i < N; ++i){
            a[i]--, b[i]--;
            if (b[i] < a[i]){
                bit.ins(a[i], 1);
                bit.ins(b[i], -1);
            }
        }

        vector<int> ans;
        for (int k = 1; k <= N; ++k){
            bool good = 1;
            for (int j = 0; j <= N; j += k){
                good &= bit.qry(j, j+k-1) == 0;
            }
            if (good){
                ans.push_back(k);
            }
        }

        cout << ans.size() << '\n';
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}
