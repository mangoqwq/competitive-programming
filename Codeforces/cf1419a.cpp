#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s; s=" "+s;
        bool odd=0, even=0;
        if (n%2==1){
            for (int i=1;i<=n;i+=2){
                if ((s[i]-'0')%2==1) odd=1;
            }
            cout << (odd?1:2) << '\n';
        }
        else{
            for (int i=2;i<=n;i+=2){
                if ((s[i]-'0')%2==0) even=1;
            }
            cout << (even?2:1) << '\n';
        }
    }
}