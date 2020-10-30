#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=100;

pair<int,int> arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=1;i<=k;++i) cin >> arr[i].first >> arr[i].second;
    iota(a.begin(),a.end(),1);
    int ans=0;
    do{
        bool flag=1;
        for (int i=1;i<=k;++i) flag&=a[arr[i].first-1]<a[arr[i].second-1];
        ans+=flag;
    } while (next_permutation(a.begin(),a.end()));
    cout << ans << '\n';
}