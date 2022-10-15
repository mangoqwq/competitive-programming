#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101,MAXM=3'000'001;

struct Item{int a,b,c,d,e,f;} arr[MAXN];
int dp[MAXM];
int n,m;

bool valid(int x){
    int tot=0;
    int a,b,c,d,e,f;
    for (int i=1;i<=n;++i){
        a=arr[i].a; b=arr[i].b; c=arr[i].c; d=arr[i].d; e=arr[i].e; f=arr[i].f;
        for (int k=0;k<=a*x;++k) dp[k]=(k<=b?0:0x3f3f3f3f);
        for (int k=c;k<=a*x;++k) dp[k]=min(dp[k],dp[k-c]+d);
        for (int k=e;k<=a*x;++k) dp[k]=min(dp[k],dp[k-e]+f);
        if (dp[a*x]>m) return 0;
        tot+=dp[a*x];
    }
    return tot<=m;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1,a,b,c,d,e,f;i<=n;++i){
        cin >> a >> b >> c >> d >> e >> f;
        arr[i]={a,b,c,d,e,f};
    }
    int low=0,high=m/n,mid;
    while (low<high){
        mid=(low+high+1) >> 1;
        if (valid(mid)) low=mid;
        else high=mid-1;
    }
    cout << low << '\n';
}