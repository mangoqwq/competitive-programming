#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

vector<int> a;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    a.push_back(0);
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        if (x<=100) a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    cout << a[0] + a[1] << '\n';
}