#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [](){
		int N; cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; ++i){
			cin >> a[i];
			a[i]++;
		}
		for (int i = 1; i < N; ++i){
			if (a[i] % a[i-1] == 0) a[i]++;
		}
		for (int i = 0; i < N; ++i){
			cout << a[i] << (i == N-1 ? '\n' : ' ');
		}
	}();
}
