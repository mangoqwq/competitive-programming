#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        ll arr[7]={0};
        arr[6]=n/100;
        n-=(n/100)*100;
        arr[5]=n/50;
        n-=(n/50)*50;
        arr[4]=n/20;
        n-=(n/20)*20;
        arr[3]=n/10;
        n-=(n/10)*10;
        arr[2]=n/5;
        n-=(n/5)*5;
        arr[1]=n/2;
        n-=(n/2)*2;
        arr[0]=n/1;
        n-=(n/1)*1;
        ll total=0;
        for (int i=0;i<7;++i){
            total+=arr[i];
        }
        cout << total << '\n';
        for (int i=0;i<7;++i){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
}