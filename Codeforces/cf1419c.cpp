#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, x; cin >> n >> x;
        vector<int> arr(n+1);
        int tot=0, same=0, same2=0, temp;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            tot+=arr[i];
            if (arr[i]==x) same++;
            else{
                if (same2==0) temp=arr[i];
                if (arr[i]==temp) same2++;
            }
        }
        if (same==n) cout << 0 << '\n';
        else if (same) cout << 1 << '\n';
        else if (tot%n==0 && tot/n==x) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}