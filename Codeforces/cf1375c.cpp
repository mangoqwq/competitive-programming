#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        int pos1,posn;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            if (arr[i]==1) pos1=i;
            if (arr[i]==n) posn=i;
        }
        if (pos1==1 || posn==n) cout << "YES" << '\n';
        else if (pos1==posn+1){
            int l=0x3f3f3f3f,r=0;
            for (int i=1;i<=posn;++i) l=min(l,arr[i]);
            for (int i=n;i>=pos1;--i) r=max(r,arr[i]);
            cout << (l>r?"NO":"YES") << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
        
    }
}