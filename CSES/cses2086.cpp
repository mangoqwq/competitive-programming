#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
struct Function{
    ll m, b; int cnt;
    ll eval(ll x){
        return m * x + b;
    }
};
const Function e = {0, (ll)1e18};
 
struct SparseLichao{
 
#define mid ((l + r) >> 1)
 
    int N;
    struct Node{
        Function f;
        int lc, rc;
    };
    vector<Node> arr;
 
    SparseLichao() = default;
    SparseLichao(int N) : N(N){
        arr.push_back({e, 0, 0});
    }
 
    void extendl(int v){
        if (!arr[v].lc){
            arr[v].lc = arr.size();
            arr.push_back({e, 0, 0});
        }
    }
    void extendr(int v){
        if (!arr[v].rc){
            arr[v].rc = arr.size();
            arr.push_back({e, 0, 0});
        }
    }
 
    void insert(int v, int l, int r, Function f){
        while (true){
            bool bl = f.eval(l) < arr[v].f.eval(l);
            bool bm = f.eval(mid) < arr[v].f.eval(mid);
            if (bm) swap(arr[v].f, f);
            if (l == r || f.b == 1e18) return;
            if (bl != bm){
                extendl(v);
                r = mid;
                v = arr[v].lc;
            }
            else{
                extendr(v);
                l = mid + 1;
                v = arr[v].rc;
            }
        }
    }
    void insert(Function f){ return insert(0, 0, N - 1, f); }
 
    pair<ll, int> query(int v, ll x, int l, int r){
        pair<ll, int> ret = {1e18, 0};
        while (true){
            ret = min(ret, {arr[v].f.eval(x), arr[v].f.cnt});
            if (x <= mid){
                r = mid;
                if (arr[v].lc == 0) break;
                v = arr[v].lc;
            }
            else{
                l = mid + 1;
                if (arr[v].rc == 0) break;
                v = arr[v].rc;
            }
        }
        return ret;
    }
    pair<ll, int> query(ll x){ return query(0, x, 0, N - 1); }
};
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("txt.in", "r", stdin);
    int N, K; cin >> N >> K;
    vector<ll> x(N);
    for (int i = 0; i < N; ++i){
        cin >> x[i];
        if (i) x[i] += x[i - 1];
    }
 
    function<pair<ll, int>(ll)> solve = [&](ll lmd) -> pair<ll, int>{
        vector<ll> dp(N);
        vector<int> cnt(N);
        SparseLichao lct(3e8 + 1);
        lct.insert({0, 0});
        for (int i = 0; i < N; ++i){
            pair<ll, int> res = lct.query(x[i]);
            cnt[i] = res.second + 1;
            dp[i] = res.first + x[i] * x[i] + lmd;
            lct.insert({-2 * x[i], x[i] * x[i] + dp[i], cnt[i]});
        }
        return {dp[N - 1], cnt[N - 1]};
    };
 
    ll lo = 0, hi = 1e18;
    while (lo < hi){
        ll mi = (lo + hi) >> 1;
        if (solve(mi).second <= K) hi = mi;
        else lo = mi + 1;
    }
    pair<ll, int> ans = solve(lo);
    cout << ans.second << " ";
    cout << ans.first - lo * K << '\n';
}
