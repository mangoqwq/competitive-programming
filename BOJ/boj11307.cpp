#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        string a, b; cin >> a >> b;
        int N = a.size(), M = b.size();

        auto answer = [&](int b){
            cout << (b ? "Alice" : "Bob") << '\n';
        };

        auto match = [&](int i){
            if (i < 0) return 0;
            for (int j = 0; j < M; ++j){
                if (i + j >= N) return 0;
                if (a[i+j] != b[j]) return 0;
            }
            return 1;
        };

        if (N == 1){
            answer(a == b);
        }
        else if (N % 2 == 0 && M % 2 == 0){
            int c = N/2 - M/2;
            answer((match(c)) || (match(c-1) && match(c+1)));
        }
        else if (N % 2 == 0 && M % 2 == 1){
            int c = N/2 - (M+1)/2;
            answer(match(c) && match(c+1));
        }
        else if (N % 2 == 1 && M % 2 == 0){
            int c = N/2 - M/2;
            answer(match(c) && match(c+1));
        }
        else if (N % 2 == 1 && M % 2 == 1){
            int c = N/2 - M/2;
            answer((match(c) || (match(c-1) && match(c+1))));
        }

    }
}
