#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int x = -1, y = -1;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            char c; cin >> c;
            if (c == 'o'){
                if (x != -1){
                    cout << abs(i - x) + abs(j - y) << '\n';
                }
                else{
                    x = i, y = j;
                }
            }
        }
    }
}
