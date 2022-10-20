#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
	vector<int> eto(2*M), nxt(2*M), h(N+1, -1);
	int T = 0;
	for (int i = 0; i < M; ++i){
		int a, b; cin >> a >> b;
		eto[T] = b; nxt[T] = h[a]; h[a] = T++;
		eto[T] = a; nxt[T] = h[b]; h[b] = T++;
	}
	vector<int> in(N+1), up(N+1), ans(M); T = 0;
	auto dfs = [&](auto self, int v, int p) -> void{
		in[v] = up[v] = ++T;
		for (int i = h[v]; i != -1; i = nxt[i]){
			if (i == (p^1)) continue;
			int to = eto[i];
			if (in[to]){
				ans[i/2] = i%2;
				up[v] = min(up[v], in[to]);
			}
			else{
				ans[i/2] = ((i+1)%2);
				self(self, to, i);
				up[v] = min(up[v], up[to]);
			}
		}
		if (up[v] == in[v] && p != -1){
			ans[p/2] = 2;
		}
	};
	if (N != 0) dfs(dfs, 1, -1);
	for (int i = 0; i < M; ++i){
		if (ans[i] == 2) cout << '=' << '\n';
		else if (ans[i] == 1) cout << '>' << '\n';
		else cout << '<' << '\n';
	}
}
