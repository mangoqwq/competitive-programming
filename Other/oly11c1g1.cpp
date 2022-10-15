#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int bit[2*MAXN+20];
ll tot, curr, temp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, l; cin >> n >> l;
    for (int j=1;j<=n;++j){
        for (int i=-curr+MAXN;i<2*MAXN+20;i+=i&-i) bit[i]++;
        int a; cin >> a;
        curr+=(a>=l?1:-1);
        temp=0;
        for (int i=-curr+MAXN-1;i>0;i-=i&-i) temp+=bit[i];
        tot+=j-temp;
    }
    cout << tot << '\n';
}