#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

int n, a[MAXN];
ll tot=0;

struct Fenwick{
    int a[MAXN];
    void ins(int i){ for (;i<MAXN;i+=i&-i) a[i]++; }
    int qry(int i){
        int ret=0;
        for (;i>0;i-=i&-i) ret+=a[i];
        return ret;
    }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i]; a[i]++;
        tot+=i-bit.qry(a[i])-1, bit.ins(a[i]);
    }
    for (int i=1;i<=n;++i){
        cout << tot << '\n';
        tot=tot-(a[i]-1)+(n-a[i]);
    }
}