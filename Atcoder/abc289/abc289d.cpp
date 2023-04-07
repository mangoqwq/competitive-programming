#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
	}
	
	int M; cin >> M;
	vector<int> bad(1e5+1);
	for (int i = 0; i < M; ++i){
		int b; cin >> b;
		bad[b] = 1;
	}

	int X; cin >> X;
	vector<int> dp(X+1);
	dp[0] = 1;
	for (int i = 0; i <= X; ++i){
		if (dp[i]){
			for (int add : a){
				if (i + add <= X && !bad[i+add]){
					dp[i+add] = 1;
				}
			}
		}
	}
	cout << (dp[X] ? "Yes" : "No") << '\n';
}
