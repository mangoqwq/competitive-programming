#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 5e18;

struct Line{
    ll m, b; int id; 
    bool operator<(const Line &other) const{
        return tie(m, b, id) < tie(other.m, other.b, other.id);
    }
    ll operator()(ll x){
        return m*x + b;
    }
    // when is this line better?
    double sect(Line o){
        if (m == o.m){
            if (b >= o.b) return -inf;
            else return inf;
        }
        return (b-o.b)/(o.m-m);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int B = 1000;
    int N; cin >> N;
    int BLKS = N/B + 1;
    struct Query{ int op, a, b, id; };
    vector<Query> qs(N);
    vector<Line> lines(N);
    vector<vector<Query>> bqs(BLKS);
    for (int i = 0; i < N; ++i){
        cin >> qs[i].op;
        if (qs[i].op == 1){
            cin >> qs[i].a >> qs[i].b;
            lines[i] = {qs[i].a, qs[i].b, i};
        }
        if (qs[i].op == 2 || qs[i].op == 3){
            cin >> qs[i].a;
            if (qs[i].op == 2) qs[i].a--;
        }
        qs[i].id = i;
        bqs[i/B].push_back(qs[i]);
    }
    set<Line> active;
    vector<ll> ans(N, -inf);
    for (int b = 0; b < BLKS; ++b){
        set<Line> temp;
        vector<Query> queries;
        for (auto [op, a, b, id] : bqs[b]){
            if (op == 2){
                if (active.count(lines[a])){
                    active.erase(lines[a]);
                    temp.insert(lines[a]);
                }
            }
            if (op == 3){
                queries.push_back(qs[id]);
            }
        }

        auto better = [&](Line a, Line b, Line c) -> bool{
            if (b.m == c.m) return 1;
            return (a.b-c.b)*(c.m-b.m) >= (b.b-c.b)*(c.m-a.m);
        };

        vector<Line> hull;
        for (Line l : active){
            while (hull.size() >= 2 && better(hull[hull.size()-2], hull.back(), l)){
                hull.pop_back();
            }
            hull.push_back(l);
        }

        sort(queries.begin(), queries.end(), [&](Query a, Query b){
            return a.a < b.a;
        });
        int p = 0;
        for (auto [op, x, _, id] : queries){
            if (hull.empty()) continue;
            while (p != hull.size()-1 && hull[p](x) <= hull[p+1](x)) p++;
            ans[id] = max(ans[id], hull[p](x));
        }

        for (auto [op, a, b, id] : bqs[b]){
            if (op == 1){
                temp.insert(lines[id]);
            }
            if (op == 2){
                temp.erase(lines[a]);
            }
            if (op == 3){
                for (Line l : temp){
                    ans[id] = max(ans[id], l(a));
                }
            }
        }
        for (Line l : temp){
            active.insert(l);
        }
    }
    for (int i = 0; i < N; ++i){
        if (qs[i].op == 3){
            if (ans[i] <= -inf) cout << "EMPTY" << '\n';
            else cout << ans[i] << '\n';
        }
    }
}
