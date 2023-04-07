#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	set<int> s;
	for (int i = 0; i < K; ++i){
		int x; cin >> x;
		s.insert(x);
	}
	int p = 1;
	for (int i = 1; i <= N; ++i){
		if (s.count(i)) continue;
		for (int j = i; j >= p; --j){
			cout << j << " ";
		}
		p = i + 1;
	}
	cout << '\n';
}
