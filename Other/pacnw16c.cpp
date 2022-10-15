#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int ans=0; bool arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,r; cin >> n >> k >> r;
    for (int i=1,a;i<=k;++i) cin >> a, arr[a]=1;
    int cnt=0;
    for (int i=1;i<r;++i) cnt+=arr[i];
    for (int i=r;i<=n;++i){
        cnt+=arr[i];
        cnt-=arr[i-r];
        if (cnt==0) arr[i]=1,arr[i-1]=1,cnt+=2,ans+=2;
        if (cnt==1){
            cnt++, ans++;
            if (arr[i]==1) arr[i-1]=1;
            else arr[i]=1;
        }
    }
    cout << ans << '\n';
}