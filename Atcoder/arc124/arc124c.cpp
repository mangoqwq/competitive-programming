#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=51;

int n, a[MAXN], b[MAXN];

bool check(int x, int y){
    for (int i=1;i<=n;++i){
        if (a[i]%x==0&&b[i]%y==0) continue;
        if (b[i]%x==0&&a[i]%y==0) continue;
        return 0;
    }
    return 1;
}

vector<int> fact(int x){
    vector<int> ret;
    for (int i=1;i*i<=x;++i){
        if (x%i) continue;
        ret.push_back(i);
        if (i*i!=x) ret.push_back(x/i);
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i] >> b[i];
    ll ans=1;
    for (int x:fact(a[1])){
        for (int y:fact(b[1])){
            if (check(x,y)) ans=max(ans,lcm((ll)x,y));
        }
    }
    cout << ans << '\n';
}
