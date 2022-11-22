#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwick{
    vector<ll> a;
    vector<int> t;
    int T;
    Fenwick(int N) : T(0), a(N), t(N) {}
    void ins(int i, ll v){
        for (++i; i < a.size(); i += i & -i){
            if (t[i] != T) a[i] = 0;
            a[i] += v;
            t[i] = T;
        }
    }
    ll qry(int i){
        ll ret = 0;
        for (++i; i; i -= i & -i){
            if (t[i] == T) ret += a[i];
        }
        return ret;
    }
    void reset(){ T++; }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<int> o(M);
    vector<vector<int>> own(N);
    for (int i = 0; i < M; ++i){
        cin >> o[i]; o[i]--;
        own[o[i]].push_back(i);
    }
    vector<ll> need(N);
    for (int i = 0; i < N; ++i){
        cin >> need[i];
    }
    struct Meteor{ int l, r, a; };
    int Q; cin >> Q;
    vector<Meteor> qs(Q);
    for (int i = 0; i < Q; ++i){
        cin >> qs[i].l >> qs[i].r >> qs[i].a;
        qs[i].l--, qs[i].r--;
    }

    vector<int> ans(N);
    Fenwick bit(M + 10);
    auto go = [&](auto self, int ql, int qr, vector<int> states) -> void{
        if (qr == ql+1){
            auto [l, r, a] = qs[ql];
            for (int i : states){
                ll cur = 0;
                for (int j : own[i]){
                    if (l > r){
                        if (j <= r|| j >= l){
                            cur += a;
                        }
                    }
                    else{
                        if (l <= j && j <= r){
                            cur += a;
                        }
                    }
                }
                if (need[i] <= cur){
                    ans[i] = ql;
                    need[i] = 0;
                }
                else ans[i] = -1;
            }
            return;
        }

        int mid = (ql+qr) >> 1;
        bit.reset();
        for (int i = ql; i < mid; ++i){
            auto [l, r, a] = qs[i];
            if (l > r){
                bit.ins(0, a);
                bit.ins(r+1, -a);
                bit.ins(l, a);
                bit.ins(M, -a);
            }
            else{
                bit.ins(l, a);
                bit.ins(r+1, -a);
            }
        }
        vector<int> vl, vr;
        for (int i : states){
            ll cur = 0;
            for (int j : own[i]){
                cur += bit.qry(j);
                if (cur >= need[i]) break;
            }
            if (cur >= need[i]){
                vl.push_back(i);
            }
            else{
                need[i] -= cur;
                vr.push_back(i);
            }
        }
        self(self, ql, mid, vl);
        self(self, mid, qr, vr);
    };
    vector<int> all_states(N);
    iota(all_states.begin(), all_states.end(), 0);
    go(go, 0, Q, all_states);

    // for (int i = 0; i < Q; ++i){
    //     cout << need[i] << " ";
    // }

    for (int i = 0; i < N; ++i){
        if (ans[i] == -1) cout << "NIE" << '\n';
        else cout << ans[i]+1 << '\n';
    }
}
