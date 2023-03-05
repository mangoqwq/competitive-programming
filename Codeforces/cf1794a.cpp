#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [](){
		int N; cin >> N;
		vector<vector<string>> a(N);
		for (int i = 0; i < 2*N-2; ++i){
			string s; cin >> s;
			a[s.size()].push_back(s);
		}
		bool ans = 1;
		for (int i = 1; i < N; ++i){
			reverse(a[i][0].begin(), a[i][0].end());
			ans &= a[i][0] == a[i][1];
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}();
}
