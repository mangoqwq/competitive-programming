#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e3+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    srand(time(0));
    int n; cin >> n;
    iota(arr+1,arr+1+n,1);
    for (int i=1;i<=20;++i){
        random_shuffle(arr+1,arr+1+n);
        for (int j=1;j<=n;++j) cout << arr[j] << (j==n?'\n':' ');
        cout.flush();
        int res; cin >> res;
        if (res==-1) assert(false);
        if (res==0) return 0;
    }
    assert(false);
}