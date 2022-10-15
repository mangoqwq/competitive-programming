#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int t; t=5;
    while (t--){
        int n; cin >> n;
        vector<int> arr;
        for (int i=n;i>=1;--i){
            arr.push_back(i);
        }
        vector<int> ans;
        for (int i=1,a;i<=n;++i){
            cin >> a;
            if (a>=arr.size()){
                continue;
            }
            ans.push_back(arr[a]);
            arr.erase(arr.begin()+a);
        }
        if (ans.size()!=n){
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        for (int x:ans){cout << x << " ";}
        cout << '\n';

    }
}