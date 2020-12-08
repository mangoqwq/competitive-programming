#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

int arr[MAXN], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,a;i<=n;++i) cin >> a, arr[i]=a-arr[i];
    for (int i=1;i<=n;++i){
        while (arr[i]){
            int best=1, curr=1, idx=i; 
            for (int j=i+1;j<=n;++j){
                if (arr[i]*arr[j]>0) curr++;
                else curr--;
                if (curr>best) best=curr, idx=j;
            }
            for (int j=idx;j>=i;--j) arr[j]+=(arr[i]>0?-1:1);
            ans++;
        }
    }
    cout << ans << '\n';
}