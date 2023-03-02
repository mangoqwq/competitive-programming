#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    ll ans = 0;
    for (char a = 'a'; a <= 'z'; ++a){
        ll cur = 0;
        for (char c : s){
            if (c == a) cur++;
        }
        ans = max(ans, cur);
    }
    for (char a = 'a'; a <= 'z'; ++a){
        for (char b = 'a'; b <= 'z'; ++b){
            ll ca = 0, cur = 0;
            for (char c : s){
                if (c == b) cur += ca;
                if (c == a) ca++;
            }
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}
