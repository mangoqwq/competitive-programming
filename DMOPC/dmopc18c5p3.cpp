#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200001;
int arr[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; ll m; cin >> n >> m;
    for (int i=0;i<n;++i){
        cin >> arr[i];
    }
    int l=0,ans=0; 
    ll temp=0;
    for (int r=0;r<n;++r){
        temp+=arr[r];
        while (temp>=m){
            temp-=arr[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout << ans << '\n';
}