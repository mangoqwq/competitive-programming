#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;

struct Item{
    int a, dir, l, r;
    bool operator<(const Item &other) const{
        return tie(l, other.r, dir, a) < tie(other.l, r, other.dir, other.a);
    }
}; // 1 ->, <- 2
vector<Item> vec;
set<Item> s = {{0, 0, -inf, inf - 1}, {0, 0, inf, inf}};
set<pii> vals, idxs;
int N, Q, bads = 1;

// b contained in a?
bool bad(Item a, Item b){
    if (a.dir == 1 && b.dir == 2){
        return !(b.l > a.l && b.r <= a.r);
    }
    else if (a.dir == 2 && b.dir == 1){
        return !(b.l >= a.l && b.r < a.r);
    }
    else{
        return !(b.l >= a.l && b.r <= a.r);
    }
}

bool modify(int i, int v){

    auto remove = [&](int i){
        assert(vec[i].a);
        Item m = vec[i];
        Item l = *(--s.find(vec[i]));
        Item r = *(++s.find(vec[i]));
        bads -= bad(l, m);
        bads -= bad(m, r);
        bads += bad(l, r);
        s.erase(vec[i]);
    };
    auto insert = [&](int i){
        assert(vec[i].a);
        s.insert(vec[i]);
        Item m = vec[i];
        Item l = *(--s.find(vec[i]));
        Item r = *(++s.find(vec[i]));
        bads -= bad(l, r);
        bads += bad(l, m);
        bads += bad(m, r);
    };
    auto direct = [&](int i){
        int l = -1, r = -1;
        auto it = idxs.find({i, vec[i].a});
        if (it != idxs.begin()){
            l = (--it)->second;
            ++it;
        }
        if (!idxs.empty() && it != --idxs.end()){
            r = (++it)->second;
            --it;
        }
        if (l >= r){
            vec[i].dir = 2;
            vec[i].l = i - N + vec[i].a;
            vec[i].r = i;
        }
        else{
            vec[i].dir = 1;
            vec[i].l = i;
            vec[i].r = i + N - vec[i].a;
        }
    };

    if (vec[i].a){
        remove(i);
        vals.erase({vec[i].a, i});

        auto it = idxs.find({i, vec[i].a});
        int l = -1, r = -1;
        if (it != idxs.begin()){
            l = (--it)->first;
            ++it;
        }
        if (!idxs.empty() && it != --idxs.end()){
            r = (++it)->first;
            --it;
        }
        idxs.erase(it);

        if (l != -1) remove(l), direct(l), insert(l);
        if (r != -1) remove(r), direct(r), insert(r);
    }

    vec[i].a = v;

    if (v){
        idxs.insert({i, vec[i].a});
        direct(i);
        vals.insert({vec[i].a, i});

        auto it = idxs.find({i, vec[i].a});
        int l = -1, r = -1;
        if (it != idxs.begin()){
            l = (--it)->first;
            ++it;
        }
        if (!idxs.empty() && it != --idxs.end()){
            r = (++it)->first;
            --it;
        }

        if (l != -1) remove(l), direct(l), insert(l);
        if (r != -1) remove(r), direct(r), insert(r);
        insert(i);
    }

    bool ans = 0;
    if (vals.empty()) ans = 1;
    else{
        int j = (--vals.end())->second;
        
        remove(j);
        vec[j].dir = 2;
        vec[j].l = j - N + vec[j].a;
        vec[j].r = j;
        insert(j);
        ans |= bads == 1;

        remove(j);
        vec[j].dir = 1;
        vec[j].l = j;
        vec[j].r = j + N - vec[j].a;
        insert(j);
        ans |= bads == 1;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    s.insert({0, 0, 0, N - 1});
    vec.resize(N);
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        modify(i, a[i]);
    }
    cout << (modify(0, a[0]) ? "YES" : "NO") << '\n';
    for (int i = 0; i < Q; ++i){
        int q, v; cin >> q >> v;
        q--;
        cout << (modify(q, v) ? "YES" : "NO") << '\n';
    }
}
