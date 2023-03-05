#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [](){
		int N; cin >> N;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < N; ++i){
			int x; cin >> x;
			pq.push(x);
			while (pq.top() < pq.size()) pq.pop();
			cout << pq.size() << (i == N-1 ? '\n' : ' ');
		}
	}();	
}
