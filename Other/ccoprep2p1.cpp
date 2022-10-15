#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int seed=131, MAXN=19;

ll n, mod, p10[MAXN];

struct matrix{
    vector<vector<ll>> v;
    matrix(){ v={{1,0,0},{0,1,0},{0,0,1}}; }
    matrix(int x){ v={{(x==19?p10[18]%mod*10:p10[x]%mod),1,0},{0,1,1},{0,0,1}}; }
    ll& operator()(int r, int c){
        return v[r][c];
    }
    matrix operator*(matrix x){
        matrix a; a(0,0)=a(1,1)=a(2,2)=0;
        for (int i=0;i<3;++i){
            for (int j=0;j<3;++j){
                for (int k=0;k<3;++k){
                    a(i,j)+=v[i][k]*x(k,j);
                    a(i,j)%=mod;
                }
            }
        }
        return a;
    }
    matrix pow(ll x){
        matrix ans;
        matrix a; a=*this;
        while (x!=0){
            if (x&1) ans=ans*a;
            x>>=1; a=a*a;
        }
        return ans;
    }
    void print(){
        for (int i=0;i<3;++i){
            for (int j=0;j<3;++j){
                cout << v[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mod;
    p10[0]=1;
    for (int i=1;i<=18;++i) p10[i]=p10[i-1]*10, p10[i];
    matrix tot;
    for (int i=18;i>=0;--i){
        if (p10[i]>n) continue;
        tot=tot*matrix(i+1).pow(n-p10[i]+1);
        n=p10[i]-1;
    }
    cout << (tot(0,1)+tot(0,2))%mod << '\n';
}