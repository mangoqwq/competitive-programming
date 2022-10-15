#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<string> names(N);
    vector<int> scores(N);
    vector<int> id(N);
    for (int i = 0; i < N; ++i) cin >> names[i] >> scores[i];
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int a, int b){ return tie(scores[a], names[a]) < tie(scores[b], names[b]); });
    int median = scores[id[N / 2]];
    for (int i = 0; i < N; ++i){
        if (scores[id[i]] == median) cout << names[id[i]] << '\n';
    }
}
