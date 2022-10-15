#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int lim=8193,len=91;
int arr[8193];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i){
        cin >> arr[i];
    }
    int q; cin >> q;
    int op,l,r,a,b,index,h;
    while (q--){
        cin >> op;
        if (op==1){
            cin >> l >> r >> a >> b;
            int cnt=0;
            for (int i=l;i<=r;++i){
                cnt+=(arr[i]>=a&&arr[i]<=b);
            }
            cout << cnt << '\n';
        }
        else{
            cin >> index >> h;
            arr[index]=h;
        }
    }
}