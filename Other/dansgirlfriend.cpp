#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct matrix{
    int n;
    vector<vector<ll>> m;
    matrix(int sz) : n(sz), m(sz+1,vector<ll>(sz+1)){}
    ll& operator()(int r, int c){
        return m[r][c];
    }
    matrix operator*(matrix x){
        matrix a(n);
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                for (int k=1;k<=n;++k){
                    a(i,j)+=m[i][k]*x(k,j);
                    a(i,j)%=mod;
                }
            }
        }
        return a;
    }
    ll sum(){
        ll tot=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                tot+=m[i][j];
                tot%=mod;
            }
        }
        return tot;
    }
    void print(){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                printf("%-4d ",m[i][j]);
            }
            printf("\n");
        }
    }
    void set_identity(){
        for (int i=1;i<=n;++i) m[i][i]=1;
    }
    matrix pow(ll x){
        matrix ans(n); ans.set_identity();
        matrix a=*this;
        while (x!=0){
            if (x&1) ans=ans*a;
            x>>=1; a=a*a;
        }
        return ans;
    }
};

ll fib(ll N){
    matrix f(2);
    f(1, 1) = 1;
    f(1, 2) = 1;
    f(2, 1) = 1;
    f(2, 2) = 0;
    f = f.pow(N);
    return f(2, 1);
}

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod, e >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    ll num = fib(N + 1) + fib(N - 1);
    ll denom = fpow(fpow(2, N), mod - 2);
    cout << num * denom % mod << '\n';
}
