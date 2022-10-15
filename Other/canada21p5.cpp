#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=201;

struct matrix{
    int n;
    vector<vector<ll>> m;
    matrix(int sz) : n(sz), m(sz+1,vector<ll>(sz+1)){}
    ll& operator()(int r, int c){
        return m[r][c];
    }
    matrix operator*(matrix x){
        matrix a(n);
        for (int i=0;i<=n;++i){
            for (int j=0;j<=n;++j){
                for (int k=0;k<=n;++k){
                    a(i,j)+=m[i][k]*x(k,j);
                    a(i,j)%=mod;
                }
            }
        }
        return a;
    }
    ll sum(){
        ll tot=0;
        for (int i=0;i<=n;++i){
            for (int j=0;j<=n;++j){
                tot+=m[i][j];
                tot%=mod;
            }
        }
        return tot;
    }
    void print(){
        for (int i=0;i<=n;++i){
            for (int j=0;j<=n;++j){
                printf("%-4d ",m[i][j]);
            }
            printf("\n");
        }
    }
    void set_identity(){
        for (int i=0;i<=n;++i) m[i][i]=1;
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

ll fact[MAXN];
ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod; e>>=1;
    }
    return ret;
}
ll inv(ll x){ return fpow(x,mod-2); }
ll choose(ll n, ll k){
    if (n<k) return 0;
    return fact[n]*inv(fact[k])%mod*inv(fact[n-k])%mod;
}
ll ways(ll g, ll b, ll mg, ll mb){
    return choose(g,mg)*choose(b,mb)%mod*inv(choose(g+b,mg+mb))%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, x, k; cin >> n >> x >> k;
    fact[0]=1;
    for (int i=1;i<=n;++i){
        fact[i]=fact[i-1]*i%mod;
    }
    matrix t(n);
    for (int g=0;g<=n;++g){
        for (int mg=0;mg<=x;++mg){
            int b=n-g, mb=x-mg;
            int nextg=g-mg+mb, nextb=n-nextg;
            if (nextg>=0&&nextb>=0){
                t(nextg,g)=ways(g,b,mg,mb);
            }
        }
    }
    // for (int i=0;i<=n;++i){
    //     for (int j=0;j<=n;++j){
    //         // chance to go from gj -> gi
    //         int df=j-i;
    //         if ((df+x)%2==1) t(i,j)=0;
    //         else{
    //             if (df<0){
    //                 df=-df;
    //                 int mb=df+(x-df)/2;
    //                 int mg=x-mb;
    //                 t(i,j)=ways(j,n-j,mg,mb);
    //             }
    //             else{
    //                 int mg=df+(x-df)/2;
    //                 int mb=x-mg;
    //                 t(i,j)=ways(j,n-j,mg,mb);
    //             }
    //         }
    //     }
    // }
    t=t.pow(k);
    // t.print();
    string s1, s2; cin >> s1 >> s2;
    int diff=0;
    for (int i=0;i<n;++i){
        if (s1[i]==s2[i]) diff++;
    }
    cout << t(n,diff)%mod << '\n';
}
