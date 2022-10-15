#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    if (arr[1]==0) arr[1]=1;
    if (arr[1]!=1) return cout << -1 << '\n', 0;
    int mn=0, mx=0, curr=0;
    for (int i=n;i>=1;--i){
        if (arr[i]&&curr&&arr[i]!=curr) return cout << -1 << '\n', 0;
        if (arr[i]) curr=arr[i];
        if (!curr) mx++;
        if (curr==1) mn++, mx++;
        if (curr!=0) curr--;
    }
    cout << mn-1 << " " << mx-1 << '\n';
}