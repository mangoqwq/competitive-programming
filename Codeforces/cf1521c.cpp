#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e4+1;

int ans[MAXN];
int ask(int t, int i, int j, int x){
    cout << "? " << t << " " << i << " " << j << " " << x << '\n';
    cout.flush();
    int ret; cin >> ret;
    if (ret==-1) exit(0);
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n==-1) return 0;
        set<int> sus;
        for (int i=2;i<=n;i+=2){
            int tmp=ask(1,i-1,i,n-1);
            if (tmp==n-1){
                tmp=max(tmp,ask(1,i,i-1,n-1));
            }
            if (tmp==n) sus.insert(i), sus.insert(i-1);
            if (i==n-1) i--;
        }
        int idx=*sus.begin(); sus.erase(idx);
        int hi=idx;
        for (int j:sus){
            if (ask(1,idx,j,n-1)==n) hi=j;
        }
        ans[hi]=n;
        for (int i=1;i<=n;++i){
            if (i==hi) continue;
            ans[i]=ask(2,i,hi,1);
        }
        cout << "! ";
        for (int i=1;i<=n;++i) cout << ans[i] << " ";
        cout << '\n';
        cout.flush();
    }
}