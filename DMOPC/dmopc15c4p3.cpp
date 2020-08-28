#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

bool dp[101];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ms(dp,false);
        int tot=0;
        dp[0]=true;
        for (int i=0,a;i<n;++i){
            cin >> a;
            for (int k=100;k>=a;--k) dp[k]|=dp[k-a];
            tot+=a;
        }
        int taunt,health; cin >> health >> taunt;
        int uwu=0x3f3f3f3f;
        for (int i=taunt;i<=100;++i){
            if (dp[i]){ uwu=i; break; }
        }
        if (uwu==0x3f3f3f3f||(tot-uwu)<health) cout << "NOT LETHAL" << '\n';
        else cout << "LETHAL" << '\n';
    }
}