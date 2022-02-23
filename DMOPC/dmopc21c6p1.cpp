#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    for (int i = 0; i < N - 1; ++i){
        if (s[i + 1] > s[i]){
            swap(s[i], s[i + 1]);
            break;
        }
    }
    cout << s << '\n';
}
