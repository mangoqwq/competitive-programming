#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> arr(n+1); arr[0]=-0x3f3f3f3f;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr.begin(),arr.end());
    ll tot=0;
    for (int i=4;i<=n;i+=2) tot+=(arr[i]-arr[i-2])*(arr[i]-arr[i-2]);
    for (int i=3;i<=n;i+=2) tot+=(arr[i]-arr[i-2])*(arr[i]-arr[i-2]);
    tot+=(arr[2]-arr[1])*(arr[2]-arr[1]);
    tot+=(arr[n]-arr[n-1])*(arr[n]-arr[n-1]);
    cout << tot << '\n';
}