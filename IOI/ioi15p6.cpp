#include <bits/stdc++.h>
using namespace std;

int getDistance(int i, int j);
int hubDistance(int N, int sub);

int hubDistance(int N, int sub) {

    vector<vector<int>> dist(N, vector<int>(N));

    int C = 0;
    for (int i = 0; i < N; ++i){
        dist[C][i] = getDistance(C, i);
    }

    int A = max_element(dist[0].begin(), dist[0].end()) - dist[0].begin();
    for (int i = 0; i < N; ++i){
        dist[A][i] = getDistance(A, i);
    }
    int B = max_element(dist[A].begin(), dist[A].end()) - dist[A].begin();
    int D = dist[A][B];

    int R = 1e9;
    vector<int> a(N), c(N), d(N);
    for (int i = 0; i < N; ++i){
        d[i] = (dist[A][i] + dist[C][i] - dist[A][C]) / 2;
        a[i] = dist[A][C] - (dist[C][i] - d[i]);
        c[i] = dist[A][C] - (dist[A][i] - d[i]);
        R = min(R, max(a[i], D - a[i]));
    }

    struct Item{ int v, cnt; };
    function<bool(int)> is_balanced = [&](int dist_a) -> bool{

        int a_side = 0;
        vector<Item> middle;
        for (int i = 0; i < N; ++i){
            if (a[i] < dist_a) a_side++;
            if (a[i] == dist_a) middle.push_back({i, 1});
        }

        if (a_side > N / 2) return 0;
        if (N - middle.size() - a_side > N / 2) return 0;

        vector<Item> save;
        while (middle.size() >= 2){
            vector<Item> nxt;
            for (int i = 0; i < middle.size(); i += 2){
                if (i == middle.size() - 1){
                    nxt.push_back(middle[i]);
                }
                else{
                    Item x = middle[i];
                    Item y = middle[i + 1];
                    if (getDistance(x.v, y.v) != d[x.v] + d[y.v]){
                        nxt.push_back({x.v, x.cnt + y.cnt});
                    }
                    else{
                        int sub = min(x.cnt, y.cnt);
                        x.cnt -= sub;
                        y.cnt -= sub;
                        if (x.cnt) nxt.push_back(x);
                        if (y.cnt) nxt.push_back(y);
                        save.push_back({x.v, sub});
                        save.push_back({y.v, sub});
                    }
                }
            }
            swap(middle, nxt);
        }
        if (middle.size() == 1){
            int v = middle[0].v;
            int same = middle[0].cnt, diff = 0;
            for (auto [u, cnt] : save){
                if (getDistance(u, v) != d[u] + d[v]){
                    same += cnt;
                }
            }
            return same <= N / 2;
        }
        else{
            return 1;
        }
    };

    bool balanced = 0;
    set<int> checked;
    for (int i = 0; i < N; ++i){
        if (max(a[i], D - a[i]) == R && !checked.count(a[i])){
            balanced |= is_balanced(a[i]);
            checked.insert(a[i]);
        }
    }

    return (balanced ? R : -R);
}
