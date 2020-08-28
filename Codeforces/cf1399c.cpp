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
        int freq[101]={0};
        for (int i=1,a;i<=n;++i){
            cin >> a; freq[a]++;
        }
        int ans=0;
        for (int i=2;i<=100;++i){
            int temp=0;
            for (int j=1;j<(i+1)/2;++j){
                temp+=min(freq[j],freq[i-j]);
            }
            if (i%2==0) temp+=freq[i/2]/2;
            ans=max(ans,temp);
        }
        cout << ans << '\n';
    }
}