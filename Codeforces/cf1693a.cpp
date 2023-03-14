#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [](){
		int N; cin >> N;
		vector<ll> a(N);
		for (int i = 0; i < N; ++i){
			cin >> a[i];
		}
		while (!a.empty() && a.back() == 0) a.pop_back();
		N = a.size();
		ll cur = 0;
		for (int i = N-1; i >= 1; --i){
			if (a[i] >= cur){
				cout << "NO" << '\n';
				return;
			}
			cur = cur - a[i];
		}
		if (cur == a[0]) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}();
}
