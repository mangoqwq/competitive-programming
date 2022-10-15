#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<int> arr(n);
    for (int i=0;i<n;++i) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int pl=0,pr=n-1; ll tot=0;
    while (pl!=pr){
        if (arr[pl]+arr[pr]>m) pr--;
        else tot+=pr-pl, pl++;
    }
    cout << tot%mod << '\n';
}
