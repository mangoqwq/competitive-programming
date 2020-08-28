#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        queue<int> zero,one; int cnt=0;
        for (int i=0;i<n;++i){
            if (s[i]=='0'){
                if (one.empty()) zero.push(++cnt), ans[i]=cnt;
                else{
                    ans[i]=one.front(); 
                    zero.push(one.front()); one.pop();
                }
            }
            else if (s[i]=='1'){
                if (zero.empty()) one.push(++cnt), ans[i]=cnt;
                else{
                    ans[i]=zero.front();
                    one.push(zero.front()); 
                    zero.pop();
                }
            }
        }
        cout << cnt << '\n';
        for (int i=0;i<n;++i) cout << ans[i] << " ";
        cout << '\n';
    }
}