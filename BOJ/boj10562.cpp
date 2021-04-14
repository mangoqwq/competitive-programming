#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+9, MAXN=1e9+1, MAXM=257;

int n, m;

struct Matrix{
    int sz;
    vector<vector<ll>> a;
    Matrix(int _sz): sz(_sz), a(sz,vector<ll>(sz)) {}
    void set_identity(){
        a=vector<vector<ll>>(sz,vector<ll>(sz));
        for (int i=0;i<sz;++i) a[i][i]=1;
    }
    Matrix operator*(const Matrix &b){
        Matrix ret(sz);
        for (int i=0;i<sz;++i){
            for (int j=0;j<sz;++j){
                for (int k=0;k<sz;++k){
                    ret.a[i][j]+=a[i][k]*b.a[k][j];
                    ret.a[i][j]%=mod;
                }
            }
        }
        return ret;
    }
    ll tot(){
        ll ret=0;
        for (int i=0;i<sz;++i)
            for (int j=0;j<sz;++j)
                ret+=a[i][j], ret%=mod;
        return ret;
    }
    void print(){
        for (int i=0;i<sz;++i){
            for (int j=0;j<sz;++j){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

Matrix fpow(Matrix b, ll e){
    Matrix ret(b.sz); ret.set_identity();
    while (e){
        if (1&e) ret=ret*b;
        b=b*b, e>>=1;
    }
    return ret;
}

int main(){
    int t; cin >> t;
    while (t--){
        int m, n; cin >> m >> n;
        int sz=(1<<(2*m));
        Matrix mat(sz);
        for (int i=0;i<sz;++i){
            for (int j=0;j<sz;++j){
                bool bad=0;
                for (int x=m;x<2*m;++x){
                    if ((1&(j>>x))!=(1&(i>>(x-m)))) bad=1;
                }
                for (int x=0;x<m;++x){
                    if (!(1&(j>>x))) continue;
                    if (x-2>=0) bad|=(1&(i>>(x-2)));
                    if (x+2<m) bad|=(1&(i>>(x+2)));
                    if (x-1>=0) bad|=(1&(i>>(x-1+m)));
                    if (x+1<m) bad|=(1&(i>>(x+1+m)));
                }
                if (!bad) mat.a[j][i]++;
            }
        }
        // mat.print();
        Matrix uwu(sz);
        for (int i=0;i<(1<<m);++i) uwu.a[i][0]=1;
        mat=fpow(mat,n-1);
        uwu=mat*uwu;
        cout << uwu.tot() << '\n';
    }
}