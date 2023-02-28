#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        string s; cin >> s;
        deque<char> q;
        for (char c : s) q.push_back(c);
        sort(q.begin(), q.end());
        string a = "", b = "";
        auto pop_second = [&](){
            int x = q.front(); q.pop_front();
            q.pop_front(); q.push_front(x);
        };
        while (!q.empty()){
            if (q.size() == 1){
                b += q[0];
                q.pop_front();
                break;
            }
            if (q[0] == q[1]){
                a += q[0];
                b += q[1];
                q.pop_front();
                q.pop_front();
            }
            else{
                char addtob = q[1];
                if (q.size() >= 3) addtob = q[2];
                if (q.size() >= 2 && addtob > b.back() && q[0] < b.back()){
                    char c = a.back();
                    while (!a.empty() && a.back() == c){
                        b.push_back(a.back());
                        a.pop_back();
                    }
                    a += q[0];
                    q.pop_front();
                    for (char c : q) b += c;
                    break;
                }
                char c = q[1];
                b += q[1];
                pop_second();
                if (q.size() != 1 && c == q[1]){
                    a += q[1];
                    pop_second();
                }
                else{
                    a += q[0];
                    q.pop_front();
                    for (char c : q) b += c;
                    break;
                }
            }
        }
        reverse(b.begin(), b.end());
        string ans = a+b;
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if (rev > ans) cout << rev << '\n';
        else cout << ans << '\n';
    }
}
