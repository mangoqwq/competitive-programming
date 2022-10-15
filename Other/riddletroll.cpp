#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

unordered_map<char, int> pr;
int a, b, c, d, i;
string s;

int solve();

int getint(){
    if (s[i] == '('){ i++; return solve(); };
    string tmp;
    while (true){
        if (i == s.size()) return stoi(tmp);
        if (s[i] == '-' && tmp.empty());
        else if (!(s[i] >= '0' && s[i] <= '9')) return stoi(tmp);
        tmp += s[i++];
    }
}

char getop(){
    return s[i++];
}

void div0(){
    cout << "attack troll with sword" << '\n';
    exit(0);
}

struct op{
    char c; int v;
    bool operator<(const op &rhs) const{
        return pr[c] < pr[rhs.c];
    }
    bool operator==(const op &rhs) const{
        return pr[c] == pr[rhs.c];
    }
    bool operator>(const op &rhs) const{
        return pr[c] > pr[rhs.c];
    }
    op apply(const op &rhs) {
        if (rhs.c == '+') v += rhs.v;
        if (rhs.c == '-') v -= rhs.v;
        if (rhs.c == '*') v *= rhs.v;
        if (rhs.c == '/'){
            if (rhs.v == 0) div0();
            v /= rhs.v;
        }
        return *this;
    }
};

int solve(){
    op ret = {',', getint()}, tmp;
    deque<op> dq;
    while (true){
        if (s[i] == ')'){
            i++;
            while (!dq.empty()){
                int idx = dq.size() - 1;
                while (idx && dq[idx - 1] == dq[idx]) idx--;
                if (idx == 0){
                    for (auto tmp : dq) ret.apply(tmp);
                    dq.clear();
                    break;
                }
                for (int j = idx; j < dq.size(); ++j) dq[idx - 1].apply(dq[j]);
                while (dq.size() > idx) dq.pop_back();
            }
            return ret.v;
        }
        tmp = {getop(), getint()};
        if (dq.empty()){ dq.push_back(tmp); }
        else if (tmp > dq.back()) dq.push_back(tmp);
        else if (tmp == dq.back()) dq.push_back(tmp);
        else if (tmp < dq.back()){
            while (!dq.empty() && dq.back() > tmp){
                int idx = dq.size() - 1;
                while (idx && dq[idx - 1] == dq[idx]) idx--;
                if (idx == 0){
                    for (auto tmp : dq) ret.apply(tmp);
                    dq.clear();
                    break;
                }
                for (int j = idx; j < dq.size(); ++j) dq[idx - 1].apply(dq[j]);
                while (dq.size() > idx) dq.pop_back();
            }
            dq.push_back(tmp);
        }
        // cout << ret.v << " -> ";
        // for (auto [op, v] : dq) cout << op << v << " ";
        // cout << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c >> d >> s;
    for (int i = 1; i <= 110; ++i) s += ')';
    pr['+'] = a, pr['-'] = b, pr['*'] = c, pr['/'] = d;
    cout << solve() << '\n';
}
