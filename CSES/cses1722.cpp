#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Matrix{
    vector<vector<ll>> a;
    Matrix(int N){
        a = vector<vector<ll>>(N, vector<ll>(N, 0));
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
                    ret(i, j) = (ret(i, j) + (*this)(i, k) * rhs(k, j)) % mod;
                }
            }
        }
        return ret;
    }
};
Matrix idMatrix(int N){
    Matrix ret(N);
    for (int i = 0; i < N; ++i){
        ret(i, i) = 1;
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
    ll N; cin >> N;
    if (N == 0) cout << 0 << '\n';
    else cout << (fpow(Matrix({{1, 1}, {1, 0}}), N - 1) * Matrix({{1, 0}, {0, 0}}))(0, 0) << '\n';
}
