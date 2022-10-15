#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MN = 0;
const int lim = 1e9;

struct Rectangle{
    int c[4];
    Rectangle(int x1, int x2, int y1, int y2){ c[0] = x1, c[1] = x2, c[2] = y1, c[3] = y2; }
    int& operator[](int i){ return c[i]; }
    friend ostream& operator<<(ostream &out, Rectangle a){
        return out << a[0] << " " << a[1] << " " << a[2] << " " << a[3];
    }
    bool contains(Rectangle rhs){
        return c[0] <= rhs[0] && c[1] >= rhs[1] && c[2] <= rhs[2] && c[3] >= rhs[3];
    }
};
vector<Rectangle> ans;

int ask(Rectangle qry){
    cout << "? " << qry << '\n';
    cout.flush();
    int ret; cin >> ret;
    assert(ret >= 0);
    for (Rectangle r : ans)
        ret -= qry.contains(r);
    return ret;
}

int bsearch(Rectangle rec, int idx, bool dir){ // 0 for least, 1 for greatest
    int lo, hi, mid;
    if (dir == 0) lo = rec[idx ^ 1], hi = lim;
    if (dir == 1) lo = 1, hi = rec[idx ^ 1];
    while (lo < hi){
        mid = (lo + hi + dir) >> 1;
        rec[idx] = mid;
        int ret = ask(rec);
        if (dir == 0){
            if (ret) hi = mid;
            else lo = mid + 1;
        }
        if (dir == 1){
            if (ret) lo = mid;
            else hi = mid - 1;
        }
    }
    return lo;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        Rectangle cur(1, lim, 1, lim);
        cur[0] = bsearch(cur, 0, 1);
        cur[1] = bsearch(cur, 1, 0);
        cur[2] = bsearch(cur, 2, 1);
        cur[3] = bsearch(cur, 3, 0);
        int cnt = ask(cur);
        for (int x = 1; x <= cnt; ++x)
            ans.push_back(cur);
    }
    cout << "!" << '\n';
    for (Rectangle r : ans){
        cout << r << '\n';
    }
    cout.flush();
}
