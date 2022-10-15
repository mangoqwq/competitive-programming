#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    vector<int> arr;
    for (int i=0,a;i<n;++i){
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int pl=0,pr=k-1,ans=0x3f3f3f3f;
    for (;pr<n;++pl,++pr){
        //cout << arr[pl] << " " << arr[pr] << '\n';
        if (arr[pl]*arr[pr]>0){
            ans=min(ans,max(abs(arr[pl]),abs(arr[pr])));
        }
        else{
            ans=min(abs(arr[pl])+abs(arr[pr])+min(abs(arr[pl]),abs(arr[pr])),ans);
        }
    }
    cout << ans << '\n';


}