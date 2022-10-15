#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q,a; cin >> n >> q;
    cin >> a; vector<int> arr={0,a};
    cout << (n-1)*2 << '\n';
    for (int i=2,p;i<=n;++i){
        cin >> a; p=i-1;
        while (arr[p]>a) p--;
        if (p+1<=i-1) cout << p+1 << " " << i-1 << '\n';
        else cout << 1 << " " << 1 << '\n';
        cout << p+1 << " " << i << '\n';
        arr.insert(arr.begin()+p+1,a);
    }
}