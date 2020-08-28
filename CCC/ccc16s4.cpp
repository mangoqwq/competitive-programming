#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=401;
int dp[MAXN][MAXN];
int arr[MAXN];
int pre[MAXN]; int n; 

int sum(int l,int r){
    return pre[r]-pre[l-1];
}

bool yes(int l,int r){
    if (l>n||r>n) return 0;
    if (dp[l][r]!=-1) return dp[l][r];
    if (l>=r) return dp[l][r]=1;
    for (int pl=l,pr=r;pl<=r;++pl){
        while (sum(pr,r)<sum(l,pl)) pr--;
        if (pl>pr) break;
        if (sum(pr,r)==sum(l,pl)){
            if (yes(l,pl)&&yes(pl+1,pr-1)&&yes(pr,r)){
                return dp[l][r]=1;
            }
        }
    }
    return dp[l][r]=0;
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    ms(dp,-1);
    cin >> n;
    int ans=0;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        ans=max(ans,arr[i]);
        pre[i]=pre[i-1]+arr[i];
    }
    for (int i=1;i<=n;++i){
        for (int k=i;k<=n;++k){
            if (yes(i,k)) ans=max(ans,sum(i,k));
        }
    }
    cout << ans << '\n';


    
}