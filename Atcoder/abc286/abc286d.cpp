#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, X; cin >> N >> X;
	vector<int> dp(X+1);
	dp[0] = 1;
	for (int i = 0; i < N; ++i){
		int v, cnt; cin >> v >> cnt;
		vector<int> nxt(X+1);
		for (int c = 0; c <= cnt; ++c){
			for (int l = 0; l <= X; ++l){
				if (dp[l] && l + c*v <= X){
					nxt[l + c*v] = 1;
				}
			}
		}
		swap(dp, nxt);
	}
	cout << (dp[X] ? "Yes" : "No") << '\n';
}

