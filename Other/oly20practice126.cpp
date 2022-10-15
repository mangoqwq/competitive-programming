#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

struct fenwick{
    int arr[MAXN];
    void ins(int i){ for (;i<MAXN;i+=i&-i) arr[i]++; }
    int qry(int i){
        int ret=0;
        for (;i>0;i-=i&-i) ret+=arr[i];
        return ret;
    }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a; cin >> a;
        bit.ins(a);
    }
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        cout << n-bit.qry(a-1) << '\n';
    }
}