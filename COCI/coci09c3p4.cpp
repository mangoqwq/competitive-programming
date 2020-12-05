#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

struct Item{
    ll p, c;
    bool operator<(Item a){
        return p < a.p;
    }
} arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> arr[i].p >> arr[i].c;
    sort(arr+1,arr+1+n);
    ll tot=0;
    for (int i=1;i<=n;++i){
        if (arr[i].c>arr[i-1].c) tot+=arr[i].c-arr[i-1].c;
    }
    cout << tot << '\n';
}