#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int a[MAXN], tot=0, cnt;

int nextprime(int x){
    while (true){
        x++;
        bool flag=1;
        for (int i=2;i*i<=x;++i){
            if (x%i==0) flag=0;
        }
        if (flag) return x;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k; cin >> k;
    for (cnt=1;;++cnt){
        tot+=cnt; a[cnt]=1;
        if (tot>=k) break;
    }
    a[0]=1;
    for (int i=1;tot>k;++i,--tot) a[i]=nextprime(a[i-1]);
    cout << cnt << '\n';
    for (int i=1;i<=cnt;++i) cout << a[i] << " ";
}