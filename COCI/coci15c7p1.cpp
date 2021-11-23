#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    bool start = 1;
    int indent = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '}') indent--;
        if (!start && (s[i] == '{' || s[i] == '}')) cout << '\n', start = 1;
        if (start){
            for (int j = 0; j < indent; ++j) cout << "  ";
        }
        if (s[i] == '{'){
            indent++;
            cout << '{' << '\n';
            start = 1;
        }
        else if (s[i] == '}'){
            cout << '}';
            start = 0;
        }
        else if (s[i] == ','){
            cout << ',' << '\n';
            start = 1;
        }
        else{
            cout << s[i];
            start = 0;
        }
    }
    cout << '\n';
}
