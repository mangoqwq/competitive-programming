#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	vector<set<int>> s(M);
	for (int i = 0; i < M; ++i){
		int K; cin >> K;
		while (K--){
			int x; cin >> x;
			s[i].insert(x);
		}
	}
	int ans = 0;
	for (int i = 0; i < (1<<M); ++i){
		set<int> al;
		for (int j = 0; j < M; ++j){
			if (1 & (i >> j)){
				for (int x : s[j]) al.insert(x);
			}
		}
		ans += al.size() == N;
	}
	cout << ans << '\n';
}
