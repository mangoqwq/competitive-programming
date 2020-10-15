#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

ll n, kk, t, c;
ll vec[105], ans1[105];

struct matrix{
    ll m[105][105];
    void init(){
        for (int i=1;i<=t;++i){
            for (int j=1;j<=t;++j){
                m[i][j]=0;
            }
        }
    }
    void set_begin(){
        for (int i=1;i<=t;++i){
            m[i][i+1]=1;
        }
        m[1][1]=1;
        m[t][1]=kk;
    }
    ll& operator()(int r, int c){
        return m[r][c];
    }
    matrix operator*(matrix x){
        matrix a; a.init();
        for (int i=1;i<=t;++i){
            for (int j=1;j<=t;++j){
                for (int k=1;k<=t;++k){
                    a(i,j)+=m[i][k]*x(k,j);
                    a(i,j)%=mod;
                }
            }
        }
        return a;
    }
    void set_identity(){
        for (int i=1;i<=t;++i) m[i][i]=1;
    }
    matrix pow(ll x){
        matrix ans; ans.init(); ans.set_identity();
        matrix a=*this;
        while (x!=0){
            if (x&1) ans=ans*a;
            x>>=1; a=a*a;
        }
        return ans;
    }
} m;

ll go(){
    ll ret=0;
    for (int i=1;i<=t;++i){
        for (int j=1;j<=t;++j){
            ans1[i]+=m(i,j)*vec[j];
            ans1[i]%=mod;
        }
    }
    for (int i=1;i<=t;++i) ret+=ans1[i], ret%=mod;
    ret+=ans1[1], ret%=mod;
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> kk >> t >> c; t++;
    m.init(); m.set_begin();
    m=m.pow(n-1);
    vec[1]=c;
    cout << go() << '\n';

}