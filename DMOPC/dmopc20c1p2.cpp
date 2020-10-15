#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    for (int i=1;i<=n;++i) cin >> arr[i], arr[i]+=arr[i-1];
    int pl=1, pr=n;
    for (int i=1,m;i<=d;++i){
        cin >> m;
        int sl=arr[pl+m-1]-arr[pl-1], sr=arr[pr]-arr[pl+m-1];
        if (sl>=sr) cout << sl << '\n', pl+=m;
        else cout << sr << '\n', pr=pl+m-1;
    }
}