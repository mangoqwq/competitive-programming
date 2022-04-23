#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Matrix{
    vector<vector<ll>> a;
    Matrix(int N){
        a = vector<vector<ll>>(N, vector<ll>(N, 2e18));
    }
    Matrix(vector<vector<ll>> vec){
        a =vec;
    }
    ll& operator()(ll i, ll j){
        return a[i][j];
    }
    Matrix operator*(Matrix rhs){
        Matrix ret(a.size());
        for (int i = 0; i < a.size(); ++i){
            for (int j = 0; j < a.size(); ++j){
                for (int k = 0; k < a.size(); ++k){
                    ret(i, j) = min(ret(i, j), (*this)(i, k) + rhs(k, j));
                }
            }
        }
        return ret;
    }
    void print(){
        for (int i = 0; i < a.size(); ++i){
            for (int j = 0; j < a[i].size(); ++j){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
};
Matrix idMatrix(int N){
    Matrix ret(N);
    for (int i = 0; i < N; ++i){
        ret(i, i) = 0;
    }
    return ret;
}
Matrix& operator*=(Matrix &a, Matrix &b){
    return a = a * b;
}
Matrix fpow(Matrix b, ll e){
    Matrix ret = idMatrix(b.a.size());
    while (e){
        if (1 & e) ret = ret * b;
        b = b * b; e >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, M, K; cin >> N >> M >> K;
    Matrix adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj(a, b) = min(adj(a, b), 1LL * c);
    }
    ll ans = fpow(adj, K)(1, N);
    if (ans >= 2e18) cout << -1 << '\n';
    else cout << ans << '\n';
}
