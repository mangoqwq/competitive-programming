#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int arr[MAXN], uwu[MAXN];
stack<int> l, d; 
vector<string> ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i], uwu[i]=arr[i];
    for (int i=1;i<=n;++i){
        d.push(arr[i]);
        ans.push_back("UZMI L L");
        ans.push_back("STAVI L D");
    }
    sort(arr+1,arr+1+n);
    for (int i=n;i>=1;--i){
        for (int j=1;j<=i;++j){
            ans.push_back("UZMI L D");
            ans.push_back("STAVI L L");
            l.push(d.top()), d.pop();
        }
        int full=0;
        for (int j=1;j<=i;++j){
            int v=l.top(); l.pop();
            if (!full&&v==arr[i]){
                ans.push_back("UZMI D L");
                full=arr[i];
            }
            else{
                ans.push_back("UZMI L L");
                ans.push_back("STAVI L D");
                d.push(v);
            }
        }
        ans.push_back("STAVI D L");
        l.push(full);
    }
    cout << ans.size() << '\n';
    for (string x:ans) cout << x << '\n';
}