#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int x; cin >> x;
    int n; cin >> n;
    int tot=0;
    while (n--){
        int a; cin >> a;
        tot+=x-a;
    }
    cout << tot+x << '\n';

}