#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

int bit[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll tot=0, temp;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        temp=0;
        for (int i=a;i>=1;i-=i&-i) temp+=bit[i];
        for (int i=a;i<=n;i+=i&-i) bit[i]++;
        tot+=min(temp,i-temp-1);
    }
    cout << tot << '\n';
}