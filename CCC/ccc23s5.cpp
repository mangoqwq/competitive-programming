#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;

    auto prune = [&](auto self, int its, double L, double R) -> vector<int> {
        if (its == 0){
            vector<int> v;
            for (int i = ceil(L); i <= floor(R+1e-15); ++i){
                v.push_back(i);
            }
            return v;
        }
        double x = L + (R-L)/3;
        double y = L + 2 * (R-L)/3;
        vector<int> retl = self(self, its-1, L, x);
        vector<int> retr = self(self, its-1, y, R);
        for (int x : retr) retl.push_back(x);
        return retl;
    };

    unordered_map<int, bool> can;
    auto solve = [&](auto self, ll a) -> bool {
        if (can.count(a)){
            if (can[a] == 0) return 0;
            else return can[a] = 1;
        }
        if (N < 3 * a && 3 * a < 2 * N) return 0;
        if (3 * a <= N){
            can[a] = 1;
            return can[a] = self(self, 3*a);
        }
        else{
            can[a] = 1;
            return can[a] = self(self, 3*a - 2*N);
        }
    };

    vector<int> pts = prune(prune, 25, 0, N);
    vector<int> ans;
    for (int p : pts){
        bool b = solve(solve, p);
        if (b){
            ans.push_back(p);
        }
    }

    for (int x : ans){
        cout << x << '\n';
    }
}
