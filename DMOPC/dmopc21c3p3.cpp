#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 * 2 + 2;

int N, M;
char frog[MN];
vector<int> ans;
void advance(char fam){
    if (fam == '>'){
        for (int i = N + M; i >= 0; --i){
            if (frog[i] != '>') continue;
            if (i + 1 <= N + M && frog[i + 1] == '_'){
                if (!(i + 3 <= N + M && frog[i + 2] == '>' && frog[i + 3] == '<')){
                    ans.push_back(i);
                    swap(frog[i], frog[i + 1]);
                }
            }
            else if (i + 2 <= N + M && frog[i + 2] == '_'){
                if (!(i + 4 <= N + M && frog[i + 1] == '>' && frog[i + 4] == '<')){
                    ans.push_back(i);
                    swap(frog[i], frog[i + 2]);
                }
            }
        }
    }
    if (fam == '<'){
        for (int i = 0; i < N + M + 1; ++i){
            if (frog[i] != '<') continue;
            if (i - 1 >= 0 && frog[i - 1] == '_'){
                if (!(i - 3 >= 0 && frog[i - 2] == '<' && frog[i - 3] == '>')){
                    ans.push_back(i);
                    swap(frog[i], frog[i - 1]);
                }
            }
            else if (i - 2 >= 0 && frog[i - 2] == '_'){
                if (!(i - 4 >= 0 && frog[i - 1] == '<' && frog[i - 4] == '>')){
                    ans.push_back(i);
                    swap(frog[i], frog[i - 2]);
                }
            }
        }
    }
}
bool good(){
    for (int i = 0; i < M; ++i) if (frog[i] != '<') return 0;
    for (int i = M + 1; i < N + M + 1; ++i) if (frog[i] != '>') return 0;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) frog[i] = '>';
    frog[N] = '_';
    for (int i = N + 1; i < N + M + 1; ++i) frog[i] = '<';
    while (!good()){
        advance('>');
        advance('<');
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << '\n';
}
