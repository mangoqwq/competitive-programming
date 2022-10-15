#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[1000001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
    }
    ll ans=0;
    int l=1,r=2; ll water=0;
    while (r<=n){
        if (a[r]>=a[l]){
            ans+=water;
            water=0;
            l=r;
            r++;
            continue;
        }
        water+=a[l]-a[r];
        r++;
    }
    l=n-1,r=n; water=0;
    while (l>0){
        if (a[l]==a[r]){
            water=0;
            r=l;
            l--;
            continue;
        }
        if (a[l]>a[r]){
            ans+=water;
            water=0;
            r=l;
            l--;
            continue;
        }
        water+=a[r]-a[l];
        l--;
    }
    cout << ans << '\n';
}