#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=201;

int arr[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    for (int i=1,a,l,r;i<=q;++i){
        cin >> a >> l >> r;
        if (a==1){
            sort(arr+l,arr+r+1);
        }
        else{
            sort(arr+l,arr+r+1,greater<int>());
        }
    }
    for (int i=1;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << arr[n] << '\n';
}