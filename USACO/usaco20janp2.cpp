#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e4+1,MAXQ=2e5+1;

int arr[MAXN]; int lc[MAXN+1][21],rc[MAXN+1][21],cnt[21];
struct Query{ int l,r,id; };
int ans[MAXQ];

void solve(int l, int r, vector<Query> &q){
    if (l>r || q.empty()) return;
    ll tot; int mid=(l+r)/2;
    for (int j=1;j<=20;++j){
        ms(cnt,0); tot=0;
        for (int i=mid;i>=l;--i){
            for (int k=arr[i];k<=j;++k){
                tot+=cnt[k]; cnt[arr[i]]+=cnt[k]; 
                cnt[arr[i]]%=mod; tot%=mod;
            }
            if (arr[i]==j) cnt[j]++, tot++;
            lc[i][j]=tot;
        }
        ms(cnt,0); tot=0;
        for (int i=mid+1;i<=r;++i){
            for (int k=arr[i];k>=j;--k){
                tot+=cnt[k]; cnt[arr[i]]+=cnt[k];
                cnt[arr[i]]%=mod; tot%=mod;
            }
            if (arr[i]==j) cnt[j]++, tot++;
            rc[i][j]=tot;
        }
    }
    ll temp,uwu;
    vector<Query> left, right;
    for (Query x:q){
        if (x.r<mid){ left.push_back(x); continue; }
        if (x.l>mid){ right.push_back(x); continue; }
        temp=1;
        for (int i=1;i<=20;++i) temp+=rc[x.r][i], temp%=mod;
        uwu=temp;
        for (int i=1;i<=20;++i){
            uwu=(uwu+(temp*lc[x.l][i])%mod)%mod;
            temp=(temp-rc[x.r][i]+mod)%mod;
        }
        ans[x.id]=uwu;
    }
    solve(1,mid-1,left); solve(mid+1,r,right);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("name.in","r",stdin);
    freopen("name.out","w",stdout);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i];
    int q; cin >> q;
    vector<Query> uwu;
    for (int i=1,a,b;i<=q;++i) cin >> a >> b, uwu.push_back({a,b,i});
    // for (int i=144;i<=152;++i) cout << arr[i] << " ";
    // cout << '\n';
    solve(1,n,uwu);
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}