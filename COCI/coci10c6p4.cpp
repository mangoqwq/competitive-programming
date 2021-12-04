#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

string a[MN];
vector<int> adj[MN];
int deg[MN];
set<int> seen;
vector<int> ans;

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        for (char c : a[i]) seen.insert(c - 'a');
    }
    for (int i = 2; i <= N; ++i){
        for (int j = 0; j < min(a[i].size(), a[i - 1].size()); ++j){
            if (a[i][j] != a[i - 1][j]){
                adj[a[i - 1][j] - 'a'].push_back(a[i][j] - 'a');
                deg[a[i][j] - 'a']++;
                break;
            }
        }
    }
    bool multi = 0;
    queue<int> q;
    for (int i = 0; i < 26; ++i){
        if (deg[i] == 0 && seen.count(i)){
            q.push(i);
        }
    }
    while (!q.empty()){
        if (q.size() != 1) multi = 1;
        int v = q.front(); q.pop();
        seen.erase(v);
        ans.push_back(v);
        for (int to : adj[v]){
            deg[to]--;
            if (deg[to] == 0){
                q.push(to);
            }
        }
    }
    if (!seen.empty()) cout << "!" << '\n';
    else if (multi) cout << "?" << '\n';
    else{
        for (char c : ans) cout << (char)(c + 'a');
        cout << '\n';
    }
}
