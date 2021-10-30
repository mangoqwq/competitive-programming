#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 51;

int N; double Z[MN];
string s;
int i;

double calc(vector<double> v, double tot){
    if (v.empty()) return 1;
    sort(v.begin(), v.end(), greater<double>());
    double take = min(v.back(), tot / v.size());
    v.pop_back();
    return take * calc(v, tot - take);
}

double solve(){
    i++;
    vector<double> v;
    char op = '+';
    while (true){
        if (s[i] == '('){
            v.push_back(solve());
        }
        else if (s[i] == '?'){
            i++; i++;
            return Z[1];
        }
        else if (s[i] == ')'){
            i++;
            if (op == '+'){
                return min(accumulate(v.begin(), v.end(), .0), Z[v.size()]);
            }
            else{
                return calc(v, Z[v.size()]);
            }
        }
        else{
            op = s[i];
            i++;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> Z[i];
    cin >> s;
    cout << fixed << setprecision(14) << solve() << '\n';
}
