#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

bool check8(int x){
    int expo=1;
    while (expo<=x) expo*=8;
    while (x){
        if (x/expo==7) return 0;
        x%=expo, expo/=8;
    }
    return 1;
}

bool check10(int x){
    int expo=1;
    while (expo<=x) expo*=10;
    while (x){
        if (x/expo==7) return 0;
        x%=expo, expo/=10;
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans=0;
    for (int i=1;i<=n;++i){
        ans+=check8(i)&&check10(i);
    }
    cout << ans << '\n';
}