#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int arr[MAXN+1];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        arr[a]++;
        arr[b+1]--;
    }
    int ans=0,curr=0;
    for (int i=1;i<=n;++i){
        curr+=arr[i];
        ans+=curr%2;
    }
    cout << ans << '\n';
}