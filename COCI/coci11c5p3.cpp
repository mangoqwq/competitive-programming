#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    s = s + "A";
    int ans = 0, cnt = 2, pass = 1;
    for (int i = N - 1; i >= 0; --i){
        if (s[i] != s[i + 1]){
            if (cnt == 1 && pass) pass = 0;
            else ans++, pass = 1;
            cnt = 0;
        }
        cnt++;
    }
    cout << ans << '\n';
}
