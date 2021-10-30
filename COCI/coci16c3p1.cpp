#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int cnt = 0;
    while (N){
        string s; cin >> s;
        if (s[0] >= 'A' && s[0] <= 'Z'){
            bool name = 1;
            for (int i = 1; i < s.size(); ++i){
                if (!(s[i] == '.' || s[i] == '?' || s[i] == '!' || (s[i] >= 'a' && s[i] <= 'z')))
                    name = 0;
            }
            if (name) cnt++;
        }
        if (s.find('.') != s.npos || s.find('?') != s.npos || s.find('!') != s.npos){
            cout << cnt << '\n';
            N--;
            cnt = 0;
        }
    }
}
