#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

//Sqrt decomposition

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<int,int> pii;
const int seed=131,MAXN=150'001,len=400,inf=0x3f3f3f3f;

struct Decomp{
    int l[MAXN],r[MAXN]; //left station # in line, right station # in line
    int val;
};
Decomp sq[len+1]; //square root
int t[MAXN],ppl[MAXN],p[MAXN]; //which line, people, station # in line
int shift[MAXN]; //shift
vector<int> ln[MAXN]; //line

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    for (int i=0;i<len;++i){
        ms(sq[i].l,0x3f);
        ms(sq[i].r,-1);
        sq[i].val=0;
    }
    int n,m,q; cin >> n >> m >> q;
    for (int i=1;i<=n;++i){
        cin >> t[i];
    }
    for (int i=1,a;i<=n;++i){
        cin >> a;
        ppl[i]=a;
        sq[i/len].val+=a;
        ln[t[i]].push_back(a);
        sq[i/len].l[t[i]] = min(sq[i/len].l[t[i]],sz(ln[t[i]])-1);
        sq[i/len].r[t[i]] = max(sq[i/len].r[t[i]],sz(ln[t[i]])-1);
        p[i]=sz(ln[t[i]])-1;
    }
    int op,l,r,x;
    int mod,ans;
    while (q--){
        cin >> op;
        if (op==1){
            cin >> l >> r;
            ans=0;
            for (int i=l;i<=r;){
                if (i%len==0&&i+len-1<=r){
                    ans+=sq[i/len].val;
                    i+=len;
                }
                else{
                    //cout << (p[i]-shift[t[i]]+sz(ln[t[i]]))%sz(ln[t[i]]) << " ";
                    ans+=ln[t[i]][(p[i]-shift[t[i]]+sz(ln[t[i]]))%sz(ln[t[i]])];
                    ++i;
                }
            }
            cout << ans << '\n';
        }
        if (op==2){
            cin >> x;
            mod=sz(ln[x]);
            shift[x]++; shift[x]%=mod;
            for (int i=0;i<=len;++i){
                int &pl=sq[i].l[x],&pr=sq[i].r[x],&pval=sq[i].val;
                if (pr==-1) continue;
                pval-=ln[x][pr];
                pl--; pr--;
                pl=(pl+mod)%mod; pr=(pr+mod)%mod;
                pval+=ln[x][pl];
            }
        }
    }


}