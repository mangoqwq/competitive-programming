#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

stack<int> s;
int l[MN], r[MN], room[MN], ans;
struct Event{
    int t, id, c;
    bool operator<(const Event &x){
        return tie(t, c) < tie(x.t, x.c);
    }
};
vector<Event> eves;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> l[i] >> r[i];
        eves.push_back({l[i], i, 0});
        eves.push_back({r[i], i, 1});
    }
    sort(eves.begin(), eves.end());
    for (auto [t, id, c] : eves){
        if (c == 0){
            if (s.empty()) s.push(++ans);
            room[id] = s.top(); s.pop();
        }
        if (c == 1){
            s.push(room[id]);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= N; ++i) cout << room[i] << " ";
    cout << '\n';
}
