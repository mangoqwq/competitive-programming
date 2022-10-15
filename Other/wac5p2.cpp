#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int arr[MAXN],large[MAXN],small[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    large[n]=small[n]=arr[n];
    for (int i=n-1;i>=1;--i){
        large[i]=max(arr[i],large[i+1]);
        small[i]=min(arr[i],small[i+1]);
    }
    reverse(large+1,large+1+n);
    for (int query=1;query<=q;++query){
        int l,acc; cin >> l >> acc;
        int ans1=upper_bound(large+1,large+1+n,l+acc)-large-1;
        int ans2=(n)-(lower_bound(small+1,small+1+n,l-acc)-small-1);
        cout << min(ans1,ans2) << '\n';
    }

}