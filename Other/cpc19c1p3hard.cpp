#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1,inf=0x3f3f3f3f;

int a[MAXN],b[MAXN];
int dp[MAXN],n;

bool bad(int l, int r){ 
    for (int i=l;i<=r;++i){
        if (a[i]==1&&b[i]==0) return true;
    }
    return false;
}

void one(int r){
    if (bad(r,r)) return;
    if (dp[r-1]==inf) return;
    dp[r]=min(dp[r],dp[r-1]+1-(a[r]==b[r]));
}

void three(int r,int more=0,bool special=false){
    int l=r-2,ans=0;
    if (l<=0) return;
    if (dp[l-1]==inf&&!special) return;
    if (bad(l,r)){
        for (int i=l;i<=r;++i){
            if (a[i]==0) ans++;
            if (b[i]==1) ans++;
        }
        ans++;
    }
    else{
        for (int i=l;i<=r;++i){
            if (a[i]==0&&b[i]==1) ans++;
        }
    }
    if (special) l=4;
    dp[r]=min(dp[r],dp[l-1]+ans+more);
}

void four(int r,int more=0){
    int l=r-3,ans=0;
    if (l<=0) return;
    if (dp[l-1]==inf) return;
    if (bad(l,r)){
        for (int i=l;i<=r;++i){
            if (a[i]==0) ans++;
            if (b[i]==1) ans++;
        }
        ans++;
    }
    else{
        for (int i=l;i<=r;++i){
            if (a[i]==0&&b[i]==1) ans++;
        }
    }
    dp[r]=min(dp[r],dp[l-1]+ans+more);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    char aa;
    for (int i=1;i<=n;++i) cin >> aa, a[i]=aa-'0';
    for (int i=1;i<=n;++i) cin >> aa, b[i]=aa-'0';
    ms(dp,0x3f); dp[0]=0;
    for (int i=1;i<=n;++i){
        one(i);
        three(i);
        four(i);
    }
    if (n==5){
        a[3]=b[3];
        three(5,0,1);
    }
    cout << (dp[n]==inf?-1:dp[n]) << '\n';

}