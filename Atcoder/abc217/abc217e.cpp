#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int Q; cin >> Q;
    multiset<int> a1;
    queue<int> a2;
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int x; cin >> x;
            a2.push(x);
        }
        if (op == 2){
            if (!a1.empty()) cout << (*a1.begin()) << '\n', a1.erase(a1.begin());
            else cout << a2.front() << '\n', a2.pop();
        }
        if (op == 3){
            while (!a2.empty()){
                int x = a2.front(); a2.pop();
                a1.insert(x);
            }
        }
    }
}
