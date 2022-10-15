#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=301;

int n, k, c[1<<8], val[1<<8];
ll dp[27'000'000]; 
char s[MAXN];

int get(int l, int r, int m){
    return l*90000+r*300+m;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k; ms(dp,-0x3f);
    for (int i=1;i<=n;++i) cin >> s[i];
    for (int i=0;i<1<<k;++i) cin >> c[i] >> val[i];
    for (int i=1;i<=n;++i) dp[get(i,i,s[i]-'0')]=0;
    for (int len=1;len<n;++len){
        for (int l=1;l+len<=n;++l){
            int r=l+len, rem=len%(k-1);
            if (rem==0) rem=k-1;
            for (int mid=r;mid>l;mid-=(k-1)){
                for (int curr=0;curr<1<<rem;++curr){
                    dp[get(l,r,curr<<1|0)]=max(dp[get(l,r,curr<<1|0)], dp[get(l,mid-1,curr)]+dp[get(mid,r,0)]);
                    dp[get(l,r,curr<<1|1)]=max(dp[get(l,r,curr<<1|1)], dp[get(l,mid-1,curr)]+dp[get(mid,r,1)]);
                }
            }
            if (rem==k-1){
                ll best[2]={LLONG_MIN,LLONG_MIN};
                for (int i=0;i<1<<k;++i){
                    best[c[i]]=max(best[c[i]],dp[get(l,r,i)]+val[i]);
                }
                dp[get(l,r,0)]=best[0], dp[get(l,r,1)]=best[1];
            }
        }
    }
    ll ans=0;
    for (int i=0;i<1<<k;++i) ans=max(ans,dp[get(1,n,i)]);
    cout << ans << '\n';
}