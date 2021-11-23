#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 10;

string s; int idx;
int N; double r[MN];

double solve(){
    char op = ' ';
    double ret = 0;
    while (true){
        if (s[idx] == ')'){
            idx++;
            if (op == '|') return 1 / ret;
            else return ret;
        }
        else if (s[idx] == '('){
            idx++;
            double val = solve();
            if (op == '|') ret += 1 / val;
            else ret += val;
        }
        else if (s[idx] == 'R'){
            idx++;
            double val = r[s[idx] - '0'];
            if (op == '|') ret += 1 / val;
            else ret += val;
            idx++;
        }
        else if (s[idx] == '|' || s[idx] == '-'){
            if (s[idx] == '|' && op == ' ') ret = 1 / ret;
            op = s[idx];
            idx++;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> r[i];
    idx = 1;
    cin >> s;
    cout << fixed << setprecision(10) << solve() << '\n';

}
