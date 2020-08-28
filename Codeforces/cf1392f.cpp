#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,tot=0,cnt=0; cin >> n;
    vector<ll> arr(n+1);
    for (int i=1;i<=n;++i) cin >> arr[i], tot+=arr[i];
    for (int i=2;i<=n;++i) cnt+=arr[i]-arr[i-1]>=2;
    ll l=0,r=1e12,mid,curr,uwu,seen;
    while (l<=r){
        mid=(l+r)>>1;
        curr=mid; uwu=0; seen=0;
        for (int i=1;i<=n;++i){
            if ((i>1)&&(arr[i]-arr[i-1]>=2)) seen++;
            if ((i>1)&&(arr[i]-arr[i-1]>=2)^((cnt+seen+1)%2)) curr++;
            uwu+=curr;
        }
        if (uwu==tot) break;
        if (uwu>tot) r=mid-1;
        if (uwu<tot) l=mid+1;
    }
    curr=mid;
    // if (cnt==0){
    //     for (int i=1;i<=n;++i) cout << arr[i] << " ";
    //     cout << '\n';
    //     return 0;
    // }
    for (int i=1;i<=n;++i){
        if ((i>1)&&(arr[i]-arr[i-1]>=2)) seen++;
        if ((i>1)&&(arr[i]-arr[i-1]>=2)^((cnt+seen+1)%2)) curr++;
        cout << curr << " ";
    }

}