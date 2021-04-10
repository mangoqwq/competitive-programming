#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=501;

bool used[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ms(used,0);
        int n, l, r, s; cin >> n >> l >> r >> s;
        int k=r-l+1;
        int curr=0, mn=0;
        vector<int> v, ans;
        for (int i=n;i>n-k;--i) curr+=i, v.push_back(i);
        if (curr<s||(k*(k+1))/2>s){ cout << -1 << '\n'; continue; }
        while (curr>s){
            if (v.back()==mn+1) ans.push_back(v.back()), v.pop_back(), mn++;
            else v.back()--, curr--;
        }
        int p=1;
        for (int x:v) ans.push_back(x);
        for (int x:ans) used[x]=1;
        for (int i=1;i<=n;++i){
            if (i>=l&&i<=r) cout << ans.back() << " ", ans.pop_back();
            else{
                while (used[p]) p++;
                cout << p << " "; used[p]=1;
            }
        }
        cout << '\n';
    }
}