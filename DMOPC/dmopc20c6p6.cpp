#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    // cin.tie(0)->sync_with_stdio(0);

    auto Empty = [&](int i){
        cout << "E " << i << '\n';
    };
    auto Fill = [&](int i){
        cout << "F " << i << '\n';
    };
    auto Dump = [&](int i, int j) -> int{
        cout << "D " << i << " " << j << '\n';
        int x; cin >> x;
        assert(x != -1);
        return x;
    };

    int N, M; cin >> N >> M;
    vector<int> ans(N + 1);
    vector<int> vol(N + 1);

    int j = 1;
    Empty(j);

    queue<int> q;
    for (int i = 2; i <= N; ++i){
        if (vol[j]){
            int x = Dump(i, j);
            int y = Dump(j, i);
            vol[i] = y;
            if (x == y){
                ans[i] = y;
                q.push(i);
                vol[j] = 0;
            }
            else{
                ans[j] = vol[j] + x;
                j = i;
            }
        }
        else{
            int x = Dump(i, j);
            if (q.empty()){
                Fill(i);
                q.push(i);
            }
            int k = q.front(); q.pop();
            int y = Dump(k, j);
            vol[j] = x + y;
            if (y == 0){
                ans[j] = x;
                q.push(j);
                j = i;
            }
            else{
                ans[i] = x;
            }
        }
    }

    int b = (j == 1 ? 2 : 1);
    ans[j] = vol[j];
    while (true){
        if (q.empty()){
            Fill(b);
            q.push(b);
        }
        int i = q.front(); q.pop();
        int x = Dump(i, j);
        ans[j] += x;
        if (x == 0 || ans[j] == M){
            break;
        }
    }
    
    cout << "A ";
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << (i == N ? '\n' : ' ');
    }
}
