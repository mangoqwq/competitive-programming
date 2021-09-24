#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int cal[4][4] = {
    {461, 431, 420, 0},
    {100, 57, 70, 0},
    {130, 160, 118, 0},
    {167, 266, 75, 0}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int tot = 0;
    for (int i = 0; i < 4; ++i){
        int x; cin >> x;
        tot += cal[i][x - 1];
    }
    cout << "Your total Calorie count is " << tot << "." << '\n';
}
