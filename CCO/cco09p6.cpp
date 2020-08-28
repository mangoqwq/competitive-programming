#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101,MAXC=1e5+1;

vector<pair<int,double>> change;
int val[MAXN],totv;
double dp[MAXC],weight[MAXN],uwu[MAXC],tot;

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int c,d,k; cin >> c >> d >> k;
    for (int i=1;i<MAXC;++i) dp[i]=-1;
    for (int i=1;i<=d;++i){
        cin >> val[i] >> weight[i];
        
        change.push_back({val[i],weight[i]});
    }
    sort(change.begin(),change.end()); change.push_back({0x3f3f3f3f,-1});
    for (int i=1,idx=-1;i<MAXC;++i){
        while (change[idx+1].f<=i) idx++;
        uwu[i]=change[idx].s+uwu[i-change[idx].f];
    }
    for (int i=1,idx;i<=k;++i){
        cin >> idx;
        tot+=weight[idx];
        totv+=val[idx];
        for (int i=MAXC-1;i>=val[idx];--i){
            if (dp[i-val[idx]]>=0) dp[i]=max(dp[i],dp[i-val[idx]]+weight[idx]);
        }
    }
    if (totv<c){ cout << "too poor" << '\n'; return 0; }
    double ans=0x3f3f3f3f;
    for (int i=c;i<=MAXC;++i){
        if (dp[i]>=0) ans=min(ans,tot-dp[i]+uwu[i-c]);
    }
    printf("%.2f\n",ans);
    
    
}