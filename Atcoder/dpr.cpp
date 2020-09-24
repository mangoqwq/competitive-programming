#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

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
                printf("%-4d",m[i][j]);
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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    matrix adj(n);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> adj(i,j);
        }
    }
    cout << adj.pow(k).sum() << '\n';
}