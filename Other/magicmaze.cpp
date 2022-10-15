#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int lim=1e5+1;
int r[lim],c[lim];
vector<int> primes;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
void genprimes(){
    bool prime[lim];
    memset(prime,true,sizeof prime);
    prime[0]=prime[1]=false;
    for (int i=2;i<=31;++i){
        if (prime[i]){
            for (int k=i*i;k<=1000;k+=i){
                prime[k]=false;
            }
        }
    }
    for (int i=2;i<=1000;++i){
        if (prime[i]) primes.push_back(i);
    }

}

int query(int x){
    int ans=-1;
    for (int i=0;primes[i]<=x;++i){
        if (x%primes[i]==0){
            ans=primes[i];
        }
    }
    return ans;
}

int main(){
    genprimes();
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> r[i];
    for (int i=1;i<=n;++i) cin >> c[i];
    int ra,ca,rb,cb;
    while (q--){
        cin >> ra >> ca >> rb >> cb;
        if (ra==rb&&ca==cb){
            cout << -1 << '\n';
        }
        else if (ra==rb){
            cout << query(r[ra]) << '\n';
        }
        else if (ca==cb){
            cout << query(c[ca]) << '\n';
        }
        else{
            int rgcd=gcd(r[ra],r[rb]);
            int rans=-1;
            for (int i=ca;i<=cb;++i){
                rans=max(rans,query(gcd(rgcd,c[i])));
            }
            int cgcd=gcd(c[ca],c[cb]);
            int cans=-1;
            for (int i=ra;i<=rb;++i){
                cans=max(cans,query(gcd(cgcd,r[i])));
            }
            //cout << cans << " " << rans << '\n';
            int ans=max(max(query(gcd(r[ra],c[cb])),query(gcd(r[rb],c[ca]))),max(rans,cans));
            if (ans==1) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
}