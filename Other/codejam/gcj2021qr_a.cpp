#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int c=1;c<=t;++c){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> arr[i];
        int ans=0;
        for (int i=1;i<=n-1;++i){
            int mn=i;
            for (int j=i;j<=n;++j){
                if (arr[j]<arr[mn]) mn=j;
            }
            ans+=mn-i+1;
            reverse(arr+i,arr+mn+1);
        }
        cout << "Case #" << c << ": " << ans << '\n';
    }
}