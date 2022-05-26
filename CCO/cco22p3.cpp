#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct State{ int cnt, c, lst; };
struct Slide{ int l, r, id; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N1, N2, K; cin >> N1 >> N2 >> K;
    vector<vector<Slide>> slides(2);
    for (int i = 0; i < N1; ++i){
        int a, b; cin >> a >> b;
        slides[0].push_back({a, b, i});
    }
    for (int i = 0; i < N2; ++i){
        int a, b; cin >> a >> b;
        slides[1].push_back({a, b, i});
    }
    auto cmp_slide = [](Slide a, Slide b){ return a.l < b.l; };
    sort(slides[0].begin(), slides[0].end(), cmp_slide);
    sort(slides[1].begin(), slides[1].end(), cmp_slide);

    auto get_slide = [&](int t, int c) -> Slide{
        if (t >= slides[c].back().r || t < slides[c].front().l){
            return {-1, -1, -1};
        }
        Slide ret = *lower_bound(slides[c].begin(), slides[c].end(), t, [](Slide a, int t){
            return a.r <= t;
        });
        if (ret.l > t) return {-1, -1, -1};
        else return ret;
    };

    // next slide with l >= r
    auto next_slide = [&](int t, int c) -> Slide{
        if (t > slides[c].back().l){
            return {-1, -1, -1};
        }
        Slide ret = *lower_bound(slides[c].begin(), slides[c].end(), t, [](Slide a, int t){
            return a.l < t;
        });
        return ret;
    };

    auto compress = [](State s) -> int{
        return s.cnt * 4 + s.c * 2 + s.lst;
    };

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(4 * (N1 + N2) + 4, 1e9 + 1);
    int s = compress({get_slide(0, 0).id != -1, 0, 0});
    dist[s] = 0; pq.push({dist[s], s});

    int ans = 0;
    while (!pq.empty()){
        auto [t, v] = pq.top(); pq.pop();
        // cout << v << " ";
        // cout.flush();
        if (t > dist[v]) continue;
        int cnt = v / 4;
        int c = 1 & (v >> 1);
        int lst = 1 & (v >> 0);

        ans = max(ans, cnt);

        // stay in room, go to next slide
        Slide nxt = next_slide(t + 1, c);
        if (nxt.id != -1){
            int d = nxt.l - t;
            bool add = get_slide(t + d, c).id != -1 && get_slide(t + d, c).id != get_slide(t, c).id;
            bool nlst = lst && !(get_slide(t + d, c ^ 1).id == -1 || get_slide(t + d, c ^ 1).id != get_slide(t, c ^ 1).id);
            int to = compress({cnt + add, c, nlst});
            if (t + d < dist[to]){
                dist[to] = t + d;
                pq.push({dist[to], to});
            }
        }

        // move rooms
        {
            int has_slide = get_slide(t + K, c ^ 1).id != -1;
            int new_slide = has_slide && get_slide(t + K, c ^ 1).id != get_slide(t, c ^ 1).id;
            int add = (lst ? new_slide : has_slide);
            int nlst = get_slide(t, c).id != -1 && get_slide(t + K, c).id == get_slide(t, c).id;
            int to = compress({cnt + add, c ^ 1, nlst});
            if (t + K < dist[to]){
                dist[to] = t + K;
                pq.push({dist[to], to});
            }
        }
    }
    cout << ans << '\n';
}
