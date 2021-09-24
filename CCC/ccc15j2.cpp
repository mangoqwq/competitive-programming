#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string str; getline(cin, str);
    int happy = 0, sad = 0;
    for (int i = 0; i < str.size(); ++i){
        string s = str.substr(i, 3);
        if (s == ":-)") happy++;
        if (s == ":-(") sad++;
    }
    if (happy == 0 && sad == 0) cout << "none" << '\n';
    else if (happy > sad) cout << "happy" << '\n';
    else if (happy < sad) cout << "sad" << '\n';
    else cout << "unsure" << '\n';
}
