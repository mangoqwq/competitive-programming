#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 5e5 + 5;

struct Answer{
    int a, b, c;
    bool operator<(const Answer &rhs) const{
        return (a + b + c) < (rhs.a + rhs.b + rhs.c);
    }
    Answer operator+(const int &rhs) const{
        return {a, b, rhs};
    }
};

struct SegmentTree{
private:
    vector<int> st;
    vector<Answer> ans, lz;
    void push(int v, int l, int r){
        if (lz[v].a == -1) return;
        st[v] = lz[v].b;
        ans[v] = {l, lz[v].b, 0};
        if (l != r){
            lz[lc] = lz[v];
            lz[rc] = lz[v];
        }
        lz[v] = {-1, -1, -1};
    }
    void ins(int ql, int qr, int val, int v = 1, int l = 0, int r = MAXN - 1){
        push(v, l, r);
        if (l > qr || r < ql || ql > qr) return;
        if (l >= ql && r <= qr){
            lz[v] = {-inf, val, 0};
            push(v, l, r);
            return;
        }
        ins(ql, qr, val, lc, l, mid);
        ins(ql ,qr, val, rc, mid + 1, r);
        st[v] = min(st[lc], st[rc]);
        ans[v] = min(ans[lc], ans[rc]);
    }
    int walk(int idx, int val, int v = 1, int l = 0, int r = MAXN - 1){
        push(v, l, r);
        if (st[v] > val) return -1;
        if (l > idx) return -1;
        if (l == r) return l;
        int ret = walk(idx, val, lc, l, mid);
        if (ret == -1) ret = walk(idx, val, rc, mid + 1, r);
        return ret;
    }
public:
    void init(){
        int n = 2 * MAXN;
        st.resize(n), ans.resize(n), lz.resize(n);
        for (int i = 0; i < MAXN; ++i){
            ins(i, i, 0);
        }
    }
    void ins(int x, int y){
        int i = walk(x - 1, y);
        if (i == -1) return;
        ins(i, x - 1, y);
    }
    Answer qry(){
        return ans[1];
    }
} st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    st.init();
    struct Person{
        int x, y, z;
        bool operator<(const Person &a) const{
            return z < a.z;
        }
    };
    vector<Person> vec(N);
    for (auto &[x, y, z] : vec){
        cin >> x >> y >> z;
    }

    sort(vec.begin(), vec.end());
    Answer ans = {0, 0, vec.back().z};
    for (int i = MAXN - 1; i >= 0; --i){
        while (!vec.empty() && vec.back().z > i){
            auto [x, y, z] = vec.back();
            vec.pop_back();
            st.ins(x, y);
        }
        Answer cur = st.qry() + i;
        // cout << cur.a << " " << cur.b << " " << cur.c << '\n';
        ans = min(ans, cur);
    }
    cout << ans.a << " " << ans.b << " " << ans.c << '\n';
}
